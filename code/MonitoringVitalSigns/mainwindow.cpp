#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "monitoringsystem.h"
#include "hospitalwing.h"
#include "patient.h"
#include "patientmonitorwidget.h" // Incluir nosso novo widget
#include <QTimer>
#include <QGridLayout>
#include <QScrollArea>
#include "newpatientdialog.h"
#include "patientmonitorwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_patientPanelLayout(nullptr) // MUDANÇA: Inicializar o ponteiro como nulo
{
    ui->setupUi(this);
    this->setWindowTitle("Painel de Monitoramento de Sinais Vitais");
    this->resize(800, 600);

    m_system = new MonitoringSystem(this);
    m_system->setupInitialData();

    setupMonitoringPanel();

    m_simulationTimer = new QTimer(this);
    connect(m_simulationTimer, &QTimer::timeout, this, &MainWindow::simulateHospitalTick);
    m_simulationTimer->start(5000);
    connect(ui->buttonNewPatient, &QPushButton::clicked, this, &MainWindow::on_buttonNewPatient_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupMonitoringPanel()
{
    // A lógica aqui estava criando um layout novo sobre o antigo.
    // Vamos usar o layout do .ui para organizar os widgets.
    QVBoxLayout* mainLayout = new QVBoxLayout(ui->centralwidget);

    // Adiciona o botão e a área de rolagem (que já existem no .ui) ao layout
    mainLayout->addWidget(ui->buttonNewPatient);
    mainLayout->addWidget(ui->scrollArea);

    // Configura o conteúdo da área de rolagem
    ui->scrollArea->setWidgetResizable(true);
    QWidget *containerWidget = new QWidget();
    // MUDANÇA: Criamos o layout e o atribuímos ao nosso ponteiro de membro
    m_patientPanelLayout = new QGridLayout(containerWidget);
    ui->scrollArea->setWidget(containerWidget);

    // O resto da função que preenche com os pacientes iniciais...
    HospitalWing* wingToDisplay = m_system->getWings().first();
    if (!wingToDisplay) return;

    const auto& patients = wingToDisplay->getPatients();
    int row = 0, col = 0;
    for (Patient* patient : patients)
    {
        PatientMonitorWidget *monitorWidget = new PatientMonitorWidget();
        monitorWidget->setPatientName(patient->getName());
        // MUDANÇA: Usamos o ponteiro de membro para adicionar os widgets
        m_patientPanelLayout->addWidget(monitorWidget, row, col);

        connect(patient, &Patient::vitalSignUpdated,
                monitorWidget, &PatientMonitorWidget::updateDisplay);

        col++;
        if (col >= 2) {
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

void MainWindow::on_buttonNewPatient_clicked()
{
    NewPatientDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        // ... (código que pega os dados do diálogo)
        QString name = dialog.getName();
        int age = dialog.getAge();
        char sex = dialog.getSex();
        int room = dialog.getRoom();
        QString diagnosis = dialog.getDiagnosis();

        if (name.isEmpty()) return;

        HospitalWing* wing = m_system->getWings().first();
        if (!wing) return;

        Patient* newPatient = new Patient(name, age, sex, room, diagnosis, wing);
        wing->addPatient(newPatient);

        // MUDANÇA: Usamos o ponteiro de membro m_patientPanelLayout, que é garantido de existir
        if (m_patientPanelLayout) {
            int patientCount = m_patientPanelLayout->count();
            int row = patientCount / 2;
            int col = patientCount % 2;

            PatientMonitorWidget *monitorWidget = new PatientMonitorWidget();
            monitorWidget->setPatientName(newPatient->getName());
            m_patientPanelLayout->addWidget(monitorWidget, row, col);

            connect(newPatient, &Patient::vitalSignUpdated,
                    monitorWidget, &PatientMonitorWidget::updateDisplay);

            // Força a primeira atualização
            newPatient->generateAndUpdateVitalSign();
        }
    }
}
