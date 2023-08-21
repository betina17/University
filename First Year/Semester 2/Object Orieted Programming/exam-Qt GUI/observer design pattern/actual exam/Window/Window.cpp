#include "Window.h"
#include "QMessageBox"
#include <QTextFormat>
#include <QBrush>
#include <algorithm>
#include <vector>
Window::Window(Person& person, Session& session, QWidget *parent)
    : QMainWindow(parent), person{person}, session{session}
{   
    ui.setupUi(this);
    session.add_observer(this);
    connections();
    this->setWindowTitle(QString::fromStdString(person.get_name()));
    ui.latitude_label->setText(QString::fromStdString("latitude: " + std::to_string(person.get_location().first)));
    ui.longitude_label->setText(QString::fromStdString("longitude: " + std::to_string(person.get_location().second)));
    if (person.get_organiser_status() == false)
        hide_add_event_layout();
    populate_list();
   
}
void Window::add_new_event()
{   
    int valid_input = 1;
    std::string  name, description, date;
    std::pair<int, int> location;
    int latitude, longitude;
    name = ui.name_line_edit->text().toStdString();
    description = ui.descriptio_line_edit->text().toStdString();
    date = ui.date_line_edit->text().toStdString();
    latitude = ui.latitude_line_edit->text().toInt();
    longitude = ui.longitude_line_edit->text().toInt();
    location = std::make_pair(latitude, longitude);
    for (Event& event : session.get_events())
    {
        if (event.get_name() == name || event.get_location() == location)
        {
            QMessageBox::critical(this, "Error", "Invalid input. try again");
            valid_input = 0;
            ui.name_line_edit->clear();
            ui.descriptio_line_edit->clear();
            ui.latitude_line_edit->clear();
            ui.longitude_line_edit->clear();
            ui.date_line_edit->clear();

        }
    }
    if (valid_input == 1)
    {   
        std::string organiser = person.get_name();
        Event event(organiser, name, description, date, location);
        session.add_event(event);
        ui.name_line_edit->clear();
        ui.descriptio_line_edit->clear();
        ui.latitude_line_edit->clear();
        ui.longitude_line_edit->clear();
        ui.date_line_edit->clear();
    }
}

Window::~Window()
{
    session.remove_observer(this);
}

void Window::populate_list()
{
    std::vector<Event>& sorted_events = session.get_events();
        std::sort(sorted_events.begin(), sorted_events.end(), [](Event& a,  Event& b) {
            std::string date_a = a.get_date();
            std::string date_b = b.get_date();
            return date_a.back() < date_b.back();
            });
    ui.events_list->clear();
    for (Event& event : sorted_events)
    {
        QListWidgetItem* item = new QListWidgetItem(QString::fromStdString("organsier:" + event.get_organiser()
            + ", Name:" + event.get_name() + ", Description: " + event.get_description() + ",Location:" +
            std::to_string(event.get_location().first) + "," + std::to_string(event.get_location().second)
            + ",Date: " + event.get_date()));
        if(person.get_organiser_status() == true && event.get_organiser() == person.get_name())
            item->setBackground(QColor(0, 255, 0));
        ui.events_list->addItem(item);

    }
}

void Window::update()
{
    populate_list();
}
void Window::hide_add_event_layout()
{

    int elements_in_layout = ui.add_data_layout->count();
    for (int i = 0; i < elements_in_layout; i++)
    {
        QLayoutItem* item = ui.add_data_layout->itemAt(i);
        QWidget* widget = item->widget();
        if (widget)
            widget->setVisible(false);
    }
}

void Window::connections()
{
    QObject::connect(ui.pushButton, &QPushButton::clicked, this, &Window::add_new_event);
}
