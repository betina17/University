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
#include <QtWidgets/QFormLayout>
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

class Ui_WindowClass
{
public:
    QWidget *centralWidget;
    QLabel *latitude_label;
    QLabel *longitude_label;
    QListWidget *events_list;
    QWidget *widget;
    QFormLayout *add_data_layout;
    QLabel *label;
    QLineEdit *name_line_edit;
    QLabel *label_2;
    QLineEdit *descriptio_line_edit;
    QLabel *label_3;
    QLineEdit *latitude_line_edit;
    QLabel *label_4;
    QLineEdit *longitude_line_edit;
    QLabel *label_5;
    QLineEdit *date_line_edit;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *WindowClass)
    {
        if (WindowClass->objectName().isEmpty())
            WindowClass->setObjectName("WindowClass");
        WindowClass->resize(1217, 600);
        centralWidget = new QWidget(WindowClass);
        centralWidget->setObjectName("centralWidget");
        latitude_label = new QLabel(centralWidget);
        latitude_label->setObjectName("latitude_label");
        latitude_label->setGeometry(QRect(20, 10, 131, 16));
        longitude_label = new QLabel(centralWidget);
        longitude_label->setObjectName("longitude_label");
        longitude_label->setGeometry(QRect(260, 10, 131, 16));
        events_list = new QListWidget(centralWidget);
        events_list->setObjectName("events_list");
        events_list->setGeometry(QRect(20, 50, 511, 321));
        widget = new QWidget(centralWidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(550, 60, 341, 301));
        add_data_layout = new QFormLayout(widget);
        add_data_layout->setSpacing(6);
        add_data_layout->setContentsMargins(11, 11, 11, 11);
        add_data_layout->setObjectName("add_data_layout");
        add_data_layout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName("label");

        add_data_layout->setWidget(0, QFormLayout::LabelRole, label);

        name_line_edit = new QLineEdit(widget);
        name_line_edit->setObjectName("name_line_edit");

        add_data_layout->setWidget(0, QFormLayout::FieldRole, name_line_edit);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        add_data_layout->setWidget(1, QFormLayout::LabelRole, label_2);

        descriptio_line_edit = new QLineEdit(widget);
        descriptio_line_edit->setObjectName("descriptio_line_edit");

        add_data_layout->setWidget(1, QFormLayout::FieldRole, descriptio_line_edit);

        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");

        add_data_layout->setWidget(2, QFormLayout::LabelRole, label_3);

        latitude_line_edit = new QLineEdit(widget);
        latitude_line_edit->setObjectName("latitude_line_edit");

        add_data_layout->setWidget(2, QFormLayout::FieldRole, latitude_line_edit);

        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");

        add_data_layout->setWidget(3, QFormLayout::LabelRole, label_4);

        longitude_line_edit = new QLineEdit(widget);
        longitude_line_edit->setObjectName("longitude_line_edit");

        add_data_layout->setWidget(3, QFormLayout::FieldRole, longitude_line_edit);

        label_5 = new QLabel(widget);
        label_5->setObjectName("label_5");

        add_data_layout->setWidget(4, QFormLayout::LabelRole, label_5);

        date_line_edit = new QLineEdit(widget);
        date_line_edit->setObjectName("date_line_edit");

        add_data_layout->setWidget(4, QFormLayout::FieldRole, date_line_edit);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");

        add_data_layout->setWidget(5, QFormLayout::FieldRole, pushButton);

        WindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(WindowClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1217, 22));
        WindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(WindowClass);
        mainToolBar->setObjectName("mainToolBar");
        WindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(WindowClass);
        statusBar->setObjectName("statusBar");
        WindowClass->setStatusBar(statusBar);

        retranslateUi(WindowClass);

        QMetaObject::connectSlotsByName(WindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *WindowClass)
    {
        WindowClass->setWindowTitle(QCoreApplication::translate("WindowClass", "Window", nullptr));
        latitude_label->setText(QString());
        longitude_label->setText(QCoreApplication::translate("WindowClass", ":", nullptr));
        label->setText(QCoreApplication::translate("WindowClass", "name", nullptr));
        label_2->setText(QCoreApplication::translate("WindowClass", "description", nullptr));
        label_3->setText(QCoreApplication::translate("WindowClass", "latitude", nullptr));
        label_4->setText(QCoreApplication::translate("WindowClass", "longitude", nullptr));
        label_5->setText(QCoreApplication::translate("WindowClass", "date", nullptr));
        pushButton->setText(QCoreApplication::translate("WindowClass", "add event", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WindowClass: public Ui_WindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_H
