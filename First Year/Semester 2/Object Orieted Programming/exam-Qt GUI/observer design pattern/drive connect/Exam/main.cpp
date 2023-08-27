#include "Window.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Services services; 
    Session session(services.get_reports_repo().get_reports());
    std::vector<Driver>& drivers = services.get_drivers_repo().get_drivers();
    for (Driver& driver : drivers)
    {
        Window* window = new Window(services, session, driver);
        window->show();
    }
    //nu mai trebuia sa fac services pt o functie, si nici sa dau ca parametru la window
    return a.exec();
}
