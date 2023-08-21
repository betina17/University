#include "Window.h"
#include <QtWidgets/QApplication>
#include <vector>
#include <QSortFilterProxyModel>
#include "BiologistFilterProxyModel.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Repository repository;
    Table* model = new Table(repository.get_bacteriums());
    for (Biologist& biologist : repository.get_biologists())
    {   
        QStringList species_list = QString::fromStdString(biologist.get_list_of_bacterial_species()).split(",");
        BiologistFilterProxyModel* filter_model = new BiologistFilterProxyModel(species_list);
        filter_model->setSourceModel(model);
        Window* new_window = new Window(model, filter_model);
        new_window->setWindowTitle(QString::fromStdString(biologist.get_name()));
        new_window->show();
    }
    QObject::connect(&a, &QApplication::aboutToQuit, model, &Table::save_bacteriums_in_file);
    return a.exec();
}
/*DE ASTA CLE MAI BINE FAC FUNCTIA DE SAVE IN TABLE SI NU IN REPO, CA DACA VREAU IN REPO, MA MAI COMPLIC PUTIN

QObject::connect(&a, &QApplication::aboutToQuit, repository, &Repository::save_bacteriums_in_file);
    return a.exec();
    why does it say that the arguments of connect don't match the ones that should?
    Here are a few things to check:

Check the signal and slot signatures: The aboutToQuit signal doesn't have any parameters, so the
save_bacteriums_in_file slot should also not have any parameters. Make sure the save_bacteriums_in_file 
method in your Repository class doesn't take any arguments.

Ensure Repository inherits from QObject and uses the Q_OBJECT macro: In order to use Qt's signals and slots
mechanism, your Repository class must inherit from QObject and include the Q_OBJECT macro at the top of the
class definition.

Ensure save_bacteriums_in_file is a slot: The save_bacteriums_in_file method must be declared as a slot in 
your Repository class. You can do this by placing the method declaration under a public slots: or private
slots: section in your class definition.
*/
