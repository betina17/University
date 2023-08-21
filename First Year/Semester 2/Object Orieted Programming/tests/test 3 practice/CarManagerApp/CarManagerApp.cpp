#include "CarManagerApp.h"

CarManagerApp::CarManagerApp(QWidget* parent): QMainWindow(parent)  //initializeaza clasa de baza a clasei carManagerApp, adica clasa QMainWindow cu parent
{
    service.get_car_repo().read_from_file();
    service.sort_cars_by_manufacturer();
    ui.setupUi(this); //the creation of the graphical user interface
    this->populate_list(); //this happens automatically after the creation of gui
    

}

CarManagerApp::~CarManagerApp()
{}

void CarManagerApp::populate_list()
{
    this->ui.CarListWidget->clear(); //ca sa scriem peste, sa o repopulam
    std::vector<Car> cars = this->service.get_car_repo().get_cars();
    for (Car& car : cars)
    {
        QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(car.get_manufacturer() + " " + car.get_model()));
        //clasa e  QListWidgetItem si faci un obiect item cu param pt constructorul corespunzator
        QColor color(QString::fromStdString(car.get_colour())); //clasa e QColor si faci un obiect color cu param pt constructorul corespunzator
        item->setForeground(color);
        this->ui.CarListWidget->addItem(item);

    }
}

/*void CarManagerApp::populate_list()
{
    this->ui.CarListWidget->clear(); //ca sa scriem peste, sa o repopulam
    std::vector<Car> cars = this->service.get_car_repo().get_cars();
    for (Car& car : cars)
    {
        QListWidgetItem item = QListWidgetItem(QString::fromStdString(car.get_manufacturer() + " " + car.get_model()));
        //clasa e  QListWidgetItem si faci un obiect item cu param pt constructorul corespunzator
        QColor color(QString::fromStdString(car.get_colour())); //clasa e QColor si faci un obiect color cu param pt constructorul corespunzator
        item.setForeground(color);
        this->ui.CarListWidget->addItem(item); //you can't do this because addItem exepects a pointer as an argument, and item is statically allocated, not
        dynamically, so it's not a pointer

    }

}
*/
/*In Qt, many functions related to the GUI and strings expect a QString as an argument, not a std::string. The QString::fromStdString() function is used to 
convert a std::string into a QString.

In your case, car.get_manufacturer() + " " + car.get_model() creates a std::string (assuming that get_manufacturer() and get_model() return std::string).
However, QListWidget::addItem() expects a QString, not a std::string. So you use QString::fromStdString() to convert your std::string into a QString before 
passing it to addItem().
This is necessary because std::string and QString are different types, and you can't directly pass a std::string to a function that expects a QString.
*/