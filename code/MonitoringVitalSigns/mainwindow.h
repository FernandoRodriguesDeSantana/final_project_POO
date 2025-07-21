#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>

// Declarações antecipadas (forward declarations) para evitar includes pesados no .h
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QTimer;
class MonitoringSystem;

// A classe MainWindow é a janela principal da aplicação, que exibe o painel de monitoramento.
class MainWindow : public QMainWindow
{
    Q_OBJECT // Macro necessário para usar Sinais e Slots

public:
    // Construtor padrão
    MainWindow(QWidget *parent = nullptr);
    // Destrutor
    ~MainWindow();

private slots:
    // Slot chamado periodicamente pelo QTimer para atualizar os sinais vitais.
    void simulateHospitalTick();
    // Slot chamado quando o botão "Registrar Novo Paciente" é clicado.
    void on_buttonNewPatient_clicked();

private:
    // Método auxiliar para configurar a interface do painel de monitoramento.
    void setupMonitoringPanel();

    // Ponteiro para os componentes da UI criados no Qt Designer.
    Ui::MainWindow *ui;
    // Ponteiro para o timer que controla a simulação.
    QTimer *m_simulationTimer;
    // Ponteiro para o sistema de gerenciamento de dados ("backend").
    MonitoringSystem* m_system;
    // Ponteiro para o layout onde os painéis dos pacientes são adicionados.
    QGridLayout* m_patientPanelLayout;
};
#endif // MAINWINDOW_H
