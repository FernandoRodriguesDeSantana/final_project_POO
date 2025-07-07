#ifndef PATIENTMONITORWIDGET_H
#define PATIENTMONITORWIDGET_H

#include <QWidget>

namespace Ui {
class PatientMonitorWidget;
}

class PatientMonitorWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PatientMonitorWidget(QWidget *parent = nullptr);
    ~PatientMonitorWidget();

    void setPatientName(const QString& name);

public slots:
    // Este slot receberá os dados emitidos pelo sinal do Paciente
    void updateDisplay(float heartRate, float systolicPressure, float diastolicPressure, float o2sat);

private:
    Ui::PatientMonitorWidget *ui;
};

#endif // PATIENTMONITORWIDGET_H
