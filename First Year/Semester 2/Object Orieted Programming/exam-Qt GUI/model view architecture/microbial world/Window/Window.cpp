#include "Window.h"
#include <QMessageBox>
Window::Window(Table* model, QAbstractItemModel* filter_model, QWidget *parent)
    : QMainWindow(parent), filter_model{filter_model}, model{model}
{   
    ui.setupUi(this);
    ui.bacteriums_table->setModel(filter_model);
    connections();
}

Window::~Window()
{}
void Window::connections()
{
    QObject::connect(ui.add_bacterium_button, &QPushButton::clicked, this, &Window::add_bacterium);
}
void Window::populate_comobobox()
{

}
void Window::see_only_selected_species()
{
}
void Window::add_bacterium()
{   
    int valid_input = 1;
    std::string name = ui.name_line_edit->text().toStdString();
    std::string species = ui.species_line_edit->text().toStdString();
    for (Bacterium& bacterium : model->get_bacteriums())
    {
        if(bacterium.get_name()==name && bacterium.get_species()==species)
        {
            QMessageBox::critical(this, "Error", "Invalid Inputs. Try again!");
            ui.name_line_edit->clear();
            ui.species_line_edit->clear();
            ui.size_line_edit->clear();
            ui.diseases_lne_edit->clear();
            valid_input = 0;
        }
    }
    if (valid_input == 1)
    {
        int size = ui.size_line_edit->text().toInt();
        std::string diseases = ui.diseases_lne_edit->text().toStdString();
        Bacterium new_bacterium(name, species, size, diseases);
        model->add_bacterium(new_bacterium);
        ui.name_line_edit->clear();
        ui.species_line_edit->clear();
        ui.size_line_edit->clear();
        ui.diseases_lne_edit->clear();
    }
}
