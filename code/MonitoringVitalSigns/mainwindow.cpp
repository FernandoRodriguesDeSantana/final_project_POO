#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "monitoringsystem.h"
#include "hospitalwing.h"
#include "patient.h"
#include "patientmonitorwidget.h" // Incluir nosso novo widget
#include <QTimer>
#include <QGridLayout>
#include <QScrollArea>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Painel de Monitoramento de Sinais Vitais");
    this->resize(800, 600);

    // 1. Cria e popula o sistema com dados de teste
    m_system = new MonitoringSystem(this);
    m_system->setupInitialData();

    // 2. Monta a interface gráfica
    setupMonitoringPanel();

    // 3. Inicia o "coração" da simulação
    m_simulationTimer = new QTimer(this);
    connect(m_simulationTimer, &QTimer::timeout, this, &MainWindow::simulateHospitalTick);
    m_simulationTimer->start(5000); // Gera novos dados a cada 5 segundos
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupMonitoringPanel()
{
    // Usa uma área de rolagem para o caso de haver muitos pacientes
    QScrollArea *scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true);
    QWidget *containerWidget = new QWidget();
    QGridLayout *layout = new QGridLayout(containerWidget);
    scrollArea->setWidget(containerWidget);
    this->setCentralWidget(scrollArea);

    HospitalWing* wingToDisplay = m_system->getWings().first();
    if (!wingToDisplay) return;

    const auto& patients = wingToDisplay->getPatients();
    int row = 0, col = 0;
    for (Patient* patient : patients)
    {
        PatientMonitorWidget *monitorWidget = new PatientMonitorWidget();
        monitorWidget->setPatientName(patient->getName());
        layout->addWidget(monitorWidget, row, col);

        connect(patient, &Patient::vitalSignUpdated,
                monitorWidget, &PatientMonitorWidget::updateDisplay);

        // Avança a posição no grid para o próximo widget
        col++;
        if (col >= 2) { // 2 painéis por linha
            col = 0;
            row++;
        }
    }
}

void MainWindow::simulateHospitalTick()
{
    // Este método é chamado a cada 5 segundos pelo timer
    HospitalWing* wingToDisplay = m_system->getWings().first();
    if (wingToDisplay) {
        for (Patient *patient : wingToDisplay->getPatients()) {
            patient->generateAndUpdateVitalSign();
        }
    }
}
