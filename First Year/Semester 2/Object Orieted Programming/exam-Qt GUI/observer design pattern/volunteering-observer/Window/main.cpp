#include "Window.h"
#include <QtWidgets/QApplication>
#include "Repository.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DepartmentsRepository departments_repository;
    departments_repository.read_departments_from_file();
    VolunteersRepository volunteers_repository;
    volunteers_repository.read_volunteers_from_file();
    Session session(volunteers_repository.get_volunteers());
    for (Department& department : departments_repository.get_departments())
    {
        Window* new_window = new Window( departments_repository,volunteers_repository, session, department);
        new_window->show();
    }
    //nu trebuia sa-i dau repo-urile la sesiune ca deja are repo-ul de care are nevoie si pe care il foloseste
    //transmis ca parametru in constructor

    return a.exec();
}
