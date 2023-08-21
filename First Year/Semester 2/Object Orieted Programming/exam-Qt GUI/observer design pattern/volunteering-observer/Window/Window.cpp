#include "Window.h"
#include <vector>
#include <algorithm>
#include <QMessageBox>
Window::Window(DepartmentsRepository& departments_repo, VolunteersRepository& volunteers_repo, Session& session1, Department& department1, QWidget *parent)
    : QMainWindow(parent), departments_repository(departments_repo), volunteers_repository(volunteers_repo),session(session1), department(department1) 
{
    ui.setupUi(this);
    this->setWindowTitle(QString::fromStdString(department.get_name()));
    ui.description_label->setText(QString::fromStdString(department.get_description()));
    session.add_observer(this);
    connections();
    populate_departments_volunteers_list();
    populate_unassigned_volunteers_list();
}

Window::~Window()
{}

void Window::populate_departments_volunteers_list()
{
    ui.departments_volunteers_list->clear();
    std::vector<Volunteer> volunteers = volunteers_repository.get_volunteers();
    std::sort(volunteers.begin(), volunteers.end(), [](Volunteer& volunteer1, Volunteer& volunteer2) {return
        volunteer1.get_name() > volunteer2.get_name();  });
    for (Volunteer& volunteer : volunteers)
    {
        if (strcmp(volunteer.get_department().c_str(), department.get_name().c_str()) == 0)
        {
            QListWidgetItem* item = new QListWidgetItem(QString::fromStdString("name:" + volunteer.get_name() +
                ", email:" + volunteer.get_email() + ", interests:" + volunteer.get_list_of_interests()));
            ui.departments_volunteers_list->addItem(item);
        }
    }
}


void Window::populate_unassigned_volunteers_list()
{
    //e foarte important ca aici sa folosesc getteru de volunteers, adica vectoru din sesiune si nu ala din repo-ul
    //de voluntari, petru ca la vectoru asta eu adaug in timpu sesiunii, si add-ul se face in vectorul din sesiune
    //nu in cel din repo, ala ramane doar cu voluntarii cititi initial din fisierul text. functia asta va fi apelata
    //de update, deci trebe sa am vectoru de voluntari updatat, adica ala care e in sesiune. cel mai bine e sa folosesti
    //getteru de voluntari din repo doar cand construiesti sesiunea, si dupa peste tot sa lucerzi cu ala din sesiune
    //AI GRIJA LA CHESTIAA ASTA!!CA DACA NU NU O SA TI PUNA CHESTIILE NOI INTRODUSE IN LISTA!!
    //orice vector schimbi in sesiune, foloseste vectoru din sesiune
    ui.unassigned_volunteers_list->clear();
    for (Volunteer& volunteer : session.get_session_volunteers())
    {
        if (strcmp(volunteer.get_department().c_str(), "unassigned") == 0)
        {
            QListWidgetItem* item = new QListWidgetItem(QString::fromStdString("name:" + volunteer.get_name() +
                ", email:" + volunteer.get_email() + ", interests:" + volunteer.get_list_of_interests()));
            ui.unassigned_volunteers_list->addItem(item);
        }
    }

}

void Window::update() 
{
    populate_unassigned_volunteers_list();
}

void Window::connections()
{
    QObject::connect(ui.add_volunteer_button, &QPushButton::clicked, this, &Window::add_new_volunteer);
}

void Window::add_new_volunteer()
{   
    int valid_input = 1;
    std::string name = ui.name_line_edit->text().toStdString();
    std::string email = ui.email_line_edit->text().toStdString();
    if (name == "" || email == "")
    {
        QMessageBox::critical(this, "Error", "Invalid input. Try again!");
        ui.name_line_edit->clear();
        ui.email_line_edit->clear();
        valid_input = 0;
    }
    if (valid_input = 1)
    {
        std::string interests = ui.interests_line_edit->text().toStdString();
        Volunteer new_volunteer(name, email, interests, "unassigned");
        session.add_volunteer(new_volunteer);
        ui.name_line_edit->clear();
        ui.email_line_edit->clear();
        ui.interests_line_edit->clear();
    }

}

