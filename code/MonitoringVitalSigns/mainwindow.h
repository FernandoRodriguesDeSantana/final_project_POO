#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui { class MainWindow; }
class QTimer;
class MonitoringSystem;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void simulateHospitalTick();
    void on_buttonNewPatient_clicked();

private:
    void setupMonitoringPanel();

    Ui::MainWindow *ui;
    QTimer *m_simulationTimer;
    MonitoringSystem* m_system;
};
#endif // MAINWINDOW_H
