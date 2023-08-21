#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Window.h"
#include "Repository.h"
#include "Table.h"
#include <QAbstractItemModel>
class Window : public QMainWindow
{
    Q_OBJECT

public:
    Window(Table* model, QAbstractItemModel* filter_model, QWidget* parent = nullptr);
    ~Window();
    void connections();

private:
    Ui::WindowClass ui;
    QAbstractItemModel* filter_model;
    Table* model;
    void populate_comobobox();
    void see_only_selected_species();
public slots:
    void add_bacterium();
    
  
};
