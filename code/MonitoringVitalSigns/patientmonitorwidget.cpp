#include "patientmonitorwidget.h"
#include "ui_patientmonitorwidget.h"

// Construtor que inicializa o widget e seus componentes de UI.
PatientMonitorWidget::PatientMonitorWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PatientMonitorWidget)
{
    ui->setupUi(this);
}

// Destrutor que libera a memória da UI.
PatientMonitorWidget::~PatientMonitorWidget()
{
    delete ui;
}

// Define o texto do QLabel que exibe o nome do paciente.
void PatientMonitorWidget::setPatientName(const QString& name)
{
    ui->labelPatientName->setText(name);
}

// Este slot é chamado pelo sinal 'vitalSignUpdated' do objeto Patient.
void PatientMonitorWidget::updateDisplay(float heartRate, float systolicPressure, float diastolicPressure, float o2sat)
{
    // Atualiza os visores de LCD com os novos valores.
    ui->lcdHeartRate->display(heartRate);
    ui->lcdO2Sat->display(o2sat);

    // Formata a string da pressão (ex: "120 / 80") e atualiza o QLabel.
    QString pressureText = QString("%1 / %2")
                               .arg(systolicPressure, 0, 'f', 0)
                               .arg(diastolicPressure, 0, 'f', 0);
    ui->labelPressure->setText(pressureText);
}
