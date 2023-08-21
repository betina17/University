#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Window.h"
#include "Repository.h"
#include "Session.h"
class Window : public QMainWindow, Observer
{
    Q_OBJECT

public:
    Window(DepartmentsRepository& departments_repo, VolunteersRepository& volunteers_repo, Session& session1, Department& department1, QWidget* parent = nullptr);
    ~Window();

private:
    Ui::WindowClass ui;
    DepartmentsRepository& departments_repository;
    VolunteersRepository& volunteers_repository;
    Session& session;
    Department& department;
    void populate_departments_volunteers_list();
    void populate_unassigned_volunteers_list();
    void update() override;
    void connections();
public slots:
    void add_new_volunteer();
};

