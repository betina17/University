/********************************************************************************
** Form generated from reading UI file 'Window.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_H
#define UI_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExamClass
{
public:
    QWidget *centralWidget;
    QLabel *latitude;
    QLabel *longitude;
    QLabel *score;
    QListWidget *reports_list;
    QListWidget *messages_list;
    QLineEdit *report_description_line;
    QLineEdit *add_message_line;
    QPushButton *add_report_button;
    QPushButton *add_message_button;
    QLineEdit *report_latitude_line;
    QLabel *description;
    QLabel *exact_latitude;
    QLabel *exact_longitude;
    QLineEdit *report_longitude_line;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ExamClass)
    {
        if (ExamClass->objectName().isEmpty())
            ExamClass->setObjectName("ExamClass");
        ExamClass->resize(983, 573);
        centralWidget = new QWidget(ExamClass);
        centralWidget->setObjectName("centralWidget");
        latitude = new QLabel(centralWidget);
        latitude->setObjectName("latitude");
        latitude->setGeometry(QRect(10, 10, 131, 16));
        longitude = new QLabel(centralWidget);
        longitude->setObjectName("longitude");
        longitude->setGeometry(QRect(220, 10, 151, 16));
        score = new QLabel(centralWidget);
        score->setObjectName("score");
        score->setGeometry(QRect(530, 10, 161, 16));
        reports_list = new QListWidget(centralWidget);
        reports_list->setObjectName("reports_list");
        reports_list->setGeometry(QRect(10, 50, 361, 191));
        messages_list = new QListWidget(centralWidget);
        messages_list->setObjectName("messages_list");
        messages_list->setGeometry(QRect(380, 50, 351, 192));
        report_description_line = new QLineEdit(centralWidget);
        report_description_line->setObjectName("report_description_line");
        report_description_line->setGeometry(QRect(100, 260, 271, 21));
        add_message_line = new QLineEdit(centralWidget);
        add_message_line->setObjectName("add_message_line");
        add_message_line->setGeometry(QRect(380, 260, 221, 21));
        add_report_button = new QPushButton(centralWidget);
        add_report_button->setObjectName("add_report_button");
        add_report_button->setGeometry(QRect(180, 390, 75, 24));
        add_message_button = new QPushButton(centralWidget);
        add_message_button->setObjectName("add_message_button");
        add_message_button->setGeometry(QRect(630, 250, 81, 24));
        report_latitude_line = new QLineEdit(centralWidget);
        report_latitude_line->setObjectName("report_latitude_line");
        report_latitude_line->setGeometry(QRect(100, 300, 271, 21));
        description = new QLabel(centralWidget);
        description->setObjectName("description");
        description->setGeometry(QRect(10, 260, 71, 16));
        exact_latitude = new QLabel(centralWidget);
        exact_latitude->setObjectName("exact_latitude");
        exact_latitude->setGeometry(QRect(10, 300, 81, 16));
        exact_longitude = new QLabel(centralWidget);
        exact_longitude->setObjectName("exact_longitude");
        exact_longitude->setGeometry(QRect(10, 340, 91, 20));
        report_longitude_line = new QLineEdit(centralWidget);
        report_longitude_line->setObjectName("report_longitude_line");
        report_longitude_line->setGeometry(QRect(100, 340, 271, 21));
        ExamClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ExamClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 983, 22));
        ExamClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ExamClass);
        mainToolBar->setObjectName("mainToolBar");
        ExamClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ExamClass);
        statusBar->setObjectName("statusBar");
        ExamClass->setStatusBar(statusBar);

        retranslateUi(ExamClass);

        QMetaObject::connectSlotsByName(ExamClass);
    } // setupUi

    void retranslateUi(QMainWindow *ExamClass)
    {
        ExamClass->setWindowTitle(QCoreApplication::translate("ExamClass", "Exam", nullptr));
        latitude->setText(QCoreApplication::translate("ExamClass", "TextLabel", nullptr));
        longitude->setText(QCoreApplication::translate("ExamClass", "TextLabel", nullptr));
        score->setText(QCoreApplication::translate("ExamClass", "TextLabel", nullptr));
        add_report_button->setText(QCoreApplication::translate("ExamClass", "Add report", nullptr));
        add_message_button->setText(QCoreApplication::translate("ExamClass", "Add message", nullptr));
        description->setText(QCoreApplication::translate("ExamClass", "description", nullptr));
        exact_latitude->setText(QCoreApplication::translate("ExamClass", "exact_latitude", nullptr));
        exact_longitude->setText(QCoreApplication::translate("ExamClass", "exact_longitude", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExamClass: public Ui_ExamClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_H
