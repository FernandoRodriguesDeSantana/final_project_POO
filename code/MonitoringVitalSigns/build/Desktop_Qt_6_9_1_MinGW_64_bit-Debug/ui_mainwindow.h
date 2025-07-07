/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLCDNumber *lcdO2Sat;
    QLCDNumber *lcdHeartRate;
    QLabel *labelPatientName;
    QLabel *labelPressure;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        lcdO2Sat = new QLCDNumber(centralwidget);
        lcdO2Sat->setObjectName("lcdO2Sat");
        lcdO2Sat->setGeometry(QRect(80, 0, 64, 23));
        lcdHeartRate = new QLCDNumber(centralwidget);
        lcdHeartRate->setObjectName("lcdHeartRate");
        lcdHeartRate->setGeometry(QRect(0, 0, 64, 23));
        labelPatientName = new QLabel(centralwidget);
        labelPatientName->setObjectName("labelPatientName");
        labelPatientName->setGeometry(QRect(10, 60, 49, 16));
        labelPressure = new QLabel(centralwidget);
        labelPressure->setObjectName("labelPressure");
        labelPressure->setGeometry(QRect(100, 70, 49, 16));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        labelPatientName->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        labelPressure->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
