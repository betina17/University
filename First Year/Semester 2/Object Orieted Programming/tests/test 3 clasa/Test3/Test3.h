#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Test3.h"
#include "Service.h"

class Test3 : public QMainWindow
{
    Q_OBJECT

public:
    Test3(QWidget *parent = nullptr);
    ~Test3();

private:
    Ui::Test3Class ui;
    Service service;
    void populate_list();
    
};
