#pragma once
#include "Service.h"
#include <QtWidgets/QMainWindow>
#include "ui_CarManagerApp.h"

class CarManagerApp : public QMainWindow
{
    Q_OBJECT

public:
    CarManagerApp(QWidget *parent = nullptr);
    ~CarManagerApp();

private:
    Service service; //asta tine de cute, iar eu in CarManagerApp.cpp trebe sa folosesc functii din Service, deci includ Service aici. imi zice ca service 
    //must be initialized, pt ca e REFERENCE
    Ui::CarManagerAppClass ui;
    void populate_list();
};
