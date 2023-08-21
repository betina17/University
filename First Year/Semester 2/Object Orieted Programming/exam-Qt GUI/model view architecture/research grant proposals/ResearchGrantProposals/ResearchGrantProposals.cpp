#include "ResearchGrantProposals.h"
#include <vector>
#include < QStandardItemModel>
#include <QWidget>
#include <QMessageBox>

ResearchGrantProposals::ResearchGrantProposals(Researcher& researcher1, IdeasTableModel* model, QWidget* parent): 
    QMainWindow(parent), ideas_table_model{model}, researcher{researcher1}
{   
    
    ui.setupUi(this);
    connections();
    ui.ideas_tableView->setModel(this->ideas_table_model);
    this->setWindowTitle(QString::fromStdString(researcher.get_name()));
    ui.position_label->setText(QString::fromStdString(researcher.get_position()));
    if (researcher.get_position() != "senior")
        ui.save_button->setVisible(false);
    if (has_accepted_ideas() == false)
        ui.develop_button->setVisible(false);
    

};

ResearchGrantProposals::~ResearchGrantProposals()
{
};

//connections si add merg pe acelasi principiu ca la observer in window
void ResearchGrantProposals::connections()
{
    QObject::connect(ui.add_idea_button, &QPushButton::clicked, this, &ResearchGrantProposals::add_new_idea);
    QObject::connect(ui.save_button, &QPushButton::clicked, ideas_table_model, &IdeasTableModel::write_to_file_ideas_from_model);

}
bool ResearchGrantProposals::has_accepted_ideas()
{
    for (Idea& idea : ideas_table_model->get_ideas_from_model())
    {
        if (idea.get_creator() == researcher.get_name() && idea.get_status() == "accepted")
            return true;
    }
    return false;
}
void ResearchGrantProposals::add_new_idea()
{
    std::string title = ui.title_lineEdit->text().toStdString();
    std::string description = ui.decssription_line_edit->text().toStdString();
    int duration = stoi(ui.duration_line_edit->text().toStdString());
    Idea new_idea(title, description, "proposed", researcher.get_name(), duration);
    if (title == "" || (duration != 1 && duration != 2 && duration != 3))
    {
        QMessageBox::critical(this, "Error", "Introduce a valid input");
        return;
    }
    try
    {
        ideas_table_model->add_idea(new_idea);
    }
    catch (std::exception& e)
    {

        QMessageBox::critical(this, "Error", e.what());
        return;
    }
    ui.title_lineEdit->clear();
    ui.decssription_line_edit->clear();
    ui.duration_line_edit->clear();


}


//aici implementan ui-ul*/
