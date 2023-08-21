#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ResearchGrantProposals.h"

#include <QMainWindow>
#include "IdeasTableModel.h"

class ResearchGrantProposals : public QMainWindow
{
    Q_OBJECT

public:
    ResearchGrantProposals(Researcher& researcher, IdeasTableModel* model, QWidget *parent = nullptr);
    //IdeasTableModel trebe cu * pt ca acest model e obiect de tip qt, adica e alocat dinamic
    ~ResearchGrantProposals();

private:
    Ui::ResearchGrantProposalsClass ui;
    IdeasTableModel* ideas_table_model;
    Researcher& researcher;
    void connections();
    bool has_accepted_ideas();
public slots:
    void add_new_idea();
    
    
    //aici vom avea toate fct pe care le apelam in ui, de ex la modelu de la test3 aveam populate_list, ce apelam
    //in ui in cpp
};

//asta e ui-ul nostru
