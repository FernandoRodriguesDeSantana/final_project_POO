#include "patientmonitorwidget.h"
#include "ui_patientmonitorwidget.h"

PatientMonitorWidget::PatientMonitorWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PatientMonitorWidget)
{
    ui->setupUi(this);
}

PatientMonitorWidget::~PatientMonitorWidget()
{
    delete ui;
}

void PatientMonitorWidget::setPatientName(const QString& name)
{
    ui->labelPatientName->setText(name); // Supondo que o nome do objeto no .ui é labelPatientName
}

// Slot que atualiza os valores na tela
void PatientMonitorWidget::updateDisplay(float heartRate, float systolicPressure, float diastolicPressure, float o2sat)
{
    ui->lcdHeartRate->display(heartRate); // Supondo que o nome do objeto é lcdHeartRate
    ui->lcdO2Sat->display(o2sat);
    ui->labelPressure->setText(QString("%1 / %2").arg(systolicPressure, 0, 'f', 0).arg(diastolicPressure, 0, 'f', 0));
}
