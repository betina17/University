#include "Window.h"
#include <string>
#include <vector>
Window::Window(Services& services1, Session& session1, Driver& driver1, QWidget* parent)
    : QMainWindow(parent), session(session1), driver(driver1), services(services1) //initialization list(this->driver = driver1)
{
    ui.setupUi(this);
    this->setWindowTitle(QString::fromStdString(driver.get_name()));
    ui.latitude->setText(QString::fromStdString("latitude:" + std::to_string(driver.get_current_location().first)));
    ui.longitude->setText(QString::fromStdString("longitude:" + std::to_string(driver.get_current_location().second)));
    ui.score->setText(QString::fromStdString("score:" + std::to_string(driver.get_score())));
    session.add_observer(this); //cream un observer nou, deci il adaugam la vector. NEAPARAT!!!!
    populate_reports_list();
    connections();
    
}
void Window::connections()
{
    QObject::connect(ui.add_report_button, &QPushButton::clicked, this, &Window::add_report);
    QObject::connect(ui.add_message_button, &QPushButton::clicked, this, &Window::send_message);
}
void Window::populate_reports_list()
{
    ui.reports_list->clear();
    
    for (Report report : session.get_reports_from_session())
    {   
        if (services.region_of_interest(driver, report) == 1)
        {
            QListWidgetItem* item = new QListWidgetItem(QString::fromStdString("description:" + report.get_description() + ", reporter:"
                + report.get_reporter() + ", latitude:" + std::to_string(report.get_exact_location().first) + ", longitude:" +
                std::to_string(report.get_exact_location().second)));
            //vezi daca e valid prin bold, nu tre sa afisezi validitatea

            if (report.get_validation_status() == 1)
            {
                QFont font = item->font();
                font.setBold(true);
                item->setFont(font);
            }
            ui.reports_list->addItem(item);
        }
    }

}
void Window::populate_messages_list()
{
    ui.messages_list->clear();
    for (std::string message : session.get_messages_from_session())
    {
        QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(message));
        ui.messages_list->addItem(item);
    }
}
Window::~Window() {};
void Window::update()
{   
    populate_reports_list();
    populate_messages_list();

}
void Window::add_report()
{
   
    std::string report_description = ui.report_description_line->text().toStdString(); //folosim asta pt ca text() method
    //returneaza un QString, da noua ne trebe string normal
    int report_latitude = stoi(ui.report_latitude_line->text().toStdString());
    int report_longitude = stoi(ui.report_longitude_line->text().toStdString());
    std::pair<int, int> exact_location = std::make_pair(report_latitude, report_longitude);
    std::string driver_name = driver.get_name();
    Report new_report(report_description, driver_name , exact_location, 0);
    session.add_new_report(new_report);
    ui.report_description_line->clear();
    ui.report_latitude_line->clear();
    ui.report_longitude_line->clear();

}
void Window::send_message()
{
    std::string new_message = driver.get_name() + ": " +  ui.add_message_line->text().toStdString();
    session.add_message(new_message);
    ui.add_message_line->clear();

}
//OBIECTIVELE DE TIP QT TREBUIE ALOCATE DINAMIC
//debug error poti avea de la stoi, care daca citeste ceva ce nu poate converti in int, da throw la o exceptie
//throw exception da debug error
