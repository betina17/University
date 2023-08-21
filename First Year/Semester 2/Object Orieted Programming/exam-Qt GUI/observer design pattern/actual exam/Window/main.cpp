#include "Window.h"
#include <QtWidgets/QApplication>
#include "Session.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Repository repository;
    Session session(repository);
    for (Person& person : repository.get_persons())
    {
        Window* new_window = new Window(person, session);
        new_window->show();
    }
    
    return a.exec();

}
