#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "monitoringsystem.h"
#include "hospitalwing.h"
#include "patient.h"
#include "patientmonitorwidget.h"
#include "newpatientdialog.h"
#include <QTimer>
#include <QGridLayout>
#include <QScrollArea>
#include <QPushButton>
#include <QVBoxLayout>

// Construtor da MainWindow, responsável por inicializar a janela e a aplicação.
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_patientPanelLayout(nullptr)
{
    // Carrega e configura os componentes da UI desenhados no Qt Designer.
    ui->setupUi(this);
    this->setWindowTitle("Painel de Monitoramento de Sinais Vitais");
    this->resize(800, 600);

    // Cria a instância do sistema de gerenciamento de dados.
    m_system = new MonitoringSystem(this);
    // Popula o sistema com dados de teste iniciais.
    m_system->setupInitialData();

    // Chama o método para construir o painel de pacientes na tela.
    setupMonitoringPanel();

    // Configura e inicia o timer que controlará a simulação.
    m_simulationTimer = new QTimer(this);
    // Conecta o sinal de 'timeout' do timer ao nosso slot que atualiza os dados.
    connect(m_simulationTimer, &QTimer::timeout, this, &MainWindow::simulateHospitalTick);
    m_simulationTimer->start(5000); // O timer dispara a cada 5000 milissegundos (5 segundos).

    // Conecta o sinal de clique do botão de registro ao slot correspondente.
    connect(ui->buttonNewPatient, &QPushButton::clicked, this, &MainWindow::on_buttonNewPatient_clicked);
}

// Destrutor padrão.
MainWindow::~MainWindow()
{
    delete ui;
}

// Constrói a interface visual do painel de monitoramento.
void MainWindow::setupMonitoringPanel()
{
    // Organiza os widgets principais (botão e área de rolagem) em um layout vertical.
    QVBoxLayout* mainLayout = new QVBoxLayout(ui->centralwidget);
    mainLayout->addWidget(ui->buttonNewPatient);
    mainLayout->addWidget(ui->scrollArea);

    // Configura a área de rolagem para conter os painéis dos pacientes.
    ui->scrollArea->setWidgetResizable(true);
    QWidget *containerWidget = new QWidget();
    // Cria o layout em grid e o armazena no ponteiro de membro para acesso futuro.
    m_patientPanelLayout = new QGridLayout(containerWidget);
    ui->scrollArea->setWidget(containerWidget);

    // Pega a primeira ala do sistema para exibir os pacientes iniciais.
    HospitalWing* wingToDisplay = m_system->getWings().first();
    if (!wingToDisplay) return;

    // Itera sobre os pacientes existentes e cria um widget de monitoramento para cada um.
    const auto& patients = wingToDisplay->getPatients();
    int row = 0, col = 0;
    for (Patient* patient : patients)
    {
        PatientMonitorWidget *monitorWidget = new PatientMonitorWidget();
        monitorWidget->setPatientName(patient->getName());
        m_patientPanelLayout->addWidget(monitorWidget, row, col);

        // Conecta o sinal de atualização do paciente ao slot de exibição do widget.
        connect(patient, &Patient::vitalSignUpdated,
                monitorWidget, &PatientMonitorWidget::updateDisplay);

        // Lógica para organizar os painéis no grid.
        col++;
        if (col >= 2) {
            col = 0;
            row++;
        }
    }
}

// Este slot é o "coração" da simulação, sendo chamado a cada 5 segundos.
void MainWindow::simulateHospitalTick()
{
    HospitalWing* wingToDisplay = m_system->getWings().first();
    if (wingToDisplay) {
        // Manda cada paciente na ala gerar um novo conjunto de sinais vitais.
        for (Patient *patient : wingToDisplay->getPatients()) {
            patient->generateAndUpdateVitalSign();
        }
    }
}

// Slot chamado para registrar um novo paciente.
void MainWindow::on_buttonNewPatient_clicked()
{
    // Cria e abre o diálogo de registro de novo paciente.
    NewPatientDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        // Se o usuário preencheu e clicou em "OK", coleta os dados.
        QString name = dialog.getName();
        int age = dialog.getAge();
        char sex = dialog.getSex();
        int room = dialog.getRoom();
        QString diagnosis = dialog.getDiagnosis();

        if (name.isEmpty()) return; // Validação simples

        // Adiciona o novo paciente ao modelo de dados do sistema.
        HospitalWing* wing = m_system->getWings().first();
        if (!wing) return;
        Patient* newPatient = new Patient(name, age, sex, room, diagnosis, wing);
        wing->addPatient(newPatient);

        // Atualiza a interface gráfica DINAMICAMENTE.
        if (m_patientPanelLayout) {
            int patientCount = m_patientPanelLayout->count();
            int row = patientCount / 2;
            int col = patientCount % 2;

            // Cria um novo widget de monitoramento para o novo paciente.
            PatientMonitorWidget *monitorWidget = new PatientMonitorWidget();
            monitorWidget->setPatientName(newPatient->getName());
            m_patientPanelLayout->addWidget(monitorWidget, row, col);

            // Conecta o sinal do novo paciente ao seu respectivo widget na tela.
            connect(newPatient, &Patient::vitalSignUpdated,
                    monitorWidget, &PatientMonitorWidget::updateDisplay);

            // Força a primeira geração de sinais para que o painel não apareça vazio.
            newPatient->generateAndUpdateVitalSign();
        }
    }
}
