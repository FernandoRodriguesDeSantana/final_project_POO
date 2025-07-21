#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

// MUDANÇA: Adicione este include para a classe de layout em grid
#include <QGridLayout>

// Declarações padrão e antecipadas
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

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

    // Esta linha agora funcionará porque QGridLayout foi incluído
    QGridLayout* m_patientPanelLayout;
};

#endif // MAINWINDOW_H
