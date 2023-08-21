#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Window.h"
#include "Session.h"
class Window : public QMainWindow, Observer
{
    Q_OBJECT

public:
    Window(Person& person, Session& session, QWidget *parent = nullptr);
    ~Window();
    void populate_list();
    void update();
    void hide_add_event_layout();
    void connections();

private:
    Ui::WindowClass ui;
    Person& person;
    Session& session;
public slots:
    void add_new_event();
};
