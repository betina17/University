#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Window.h"
#include "Services.h"
#include "Session.h"
class Window : public QMainWindow, Observer
{
    Q_OBJECT

public:
    Window(Services& services1, Session& session1, Driver& driver1, QWidget *parent = nullptr);
    ~Window();
    

private:
    Ui::ExamClass ui;
    Driver& driver;
    Session& session;
    Services& services;
    void populate_reports_list();
    void populate_messages_list();
    void update() override;
    void connections();
public slots:
    void send_message();
    void add_report();
    

};
//fiecare window e observerul. subiectul e baza de date, care va fi vectorul de rapoarte si vectorul de mesaje(ca astea 
//apar pe fiecare window, asta afiseaza fiecare observer, cu datele astea lucreaza)
//pt ca fiecare window e observer, window-ul e GUI-ul, de asta am denumit GUi-ul Window
