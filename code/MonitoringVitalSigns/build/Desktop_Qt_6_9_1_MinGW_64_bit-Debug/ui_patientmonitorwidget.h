/********************************************************************************
** Form generated from reading UI file 'patientmonitorwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATIENTMONITORWIDGET_H
#define UI_PATIENTMONITORWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PatientMonitorWidget
{
public:
    QLCDNumber *lcdO2Sat;
    QLCDNumber *lcdHeartRate;
    QLabel *labelPatientName;
    QLabel *labelPressure;

    void setupUi(QWidget *PatientMonitorWidget)
    {
        if (PatientMonitorWidget->objectName().isEmpty())
            PatientMonitorWidget->setObjectName("PatientMonitorWidget");
        PatientMonitorWidget->resize(400, 300);
        lcdO2Sat = new QLCDNumber(PatientMonitorWidget);
        lcdO2Sat->setObjectName("lcdO2Sat");
        lcdO2Sat->setGeometry(QRect(270, 200, 64, 23));
        lcdHeartRate = new QLCDNumber(PatientMonitorWidget);
        lcdHeartRate->setObjectName("lcdHeartRate");
        lcdHeartRate->setGeometry(QRect(190, 200, 64, 23));
        labelPatientName = new QLabel(PatientMonitorWidget);
        labelPatientName->setObjectName("labelPatientName");
        labelPatientName->setGeometry(QRect(200, 260, 49, 16));
        labelPressure = new QLabel(PatientMonitorWidget);
        labelPressure->setObjectName("labelPressure");
        labelPressure->setGeometry(QRect(290, 270, 49, 16));

        retranslateUi(PatientMonitorWidget);

        QMetaObject::connectSlotsByName(PatientMonitorWidget);
    } // setupUi

    void retranslateUi(QWidget *PatientMonitorWidget)
    {
        PatientMonitorWidget->setWindowTitle(QCoreApplication::translate("PatientMonitorWidget", "Form", nullptr));
        labelPatientName->setText(QCoreApplication::translate("PatientMonitorWidget", "TextLabel", nullptr));
        labelPressure->setText(QCoreApplication::translate("PatientMonitorWidget", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PatientMonitorWidget: public Ui_PatientMonitorWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENTMONITORWIDGET_H
