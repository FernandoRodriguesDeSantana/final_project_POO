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
    connect(ui->buttonNewPatient, &QPushButton::clicked, this, &MainWindow::on_buttonNewPatient_clicked);
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
    // Damos um nome ao container para encontrá-lo depois
    containerWidget->setObjectName("monitoringPanelContainer");
    QGridLayout *layout = new QGridLayout(containerWidget);
    scrollArea->setWidget(containerWidget);
    // O centralwidget agora é o botão e a área de rolagem, então precisamos de um layout principal
    QVBoxLayout* mainLayout = new QVBoxLayout(ui->centralwidget);
    mainLayout->addWidget(ui->buttonNewPatient); // Adiciona o botão no topo
    mainLayout->addWidget(scrollArea); // Adiciona a área de rolagem abaixo

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

// Slot que abre o diálogo de registro
void MainWindow::on_buttonNewPatient_clicked()
{
    NewPatientDialog dialog(this);
    // Abre o diálogo e para a execução aqui até que ele seja fechado
    if (dialog.exec() == QDialog::Accepted) {
        // Se o usuário clicou em "OK", pegamos os dados
        QString name = dialog.getName();
        int age = dialog.getAge();
        char sex = dialog.getSex();
        int room = dialog.getRoom();
        QString diagnosis = dialog.getDiagnosis();

        // Validação simples para não adicionar pacientes vazios
        if (name.isEmpty() || age == 0) {
            return;
        }

        // Pega a primeira ala para adicionar o paciente
        HospitalWing* wing = m_system->getWings().first();
        if (!wing) return;

        // Cria o novo objeto Patient
        Patient* newPatient = new Patient(name, age, sex, room, diagnosis, wing);
        // Adiciona o paciente à lógica da ala
        wing->addPatient(newPatient);

        // ATUALIZAÇÃO DINÂMICA DA UI: Adiciona o widget do novo paciente à tela
        // Supondo que o layout está no containerWidget dentro do scrollArea
        QGridLayout* layout = qobject_cast<QGridLayout*>(ui->centralwidget->findChild<QWidget*>()->layout());
        if (layout) {
            int patientCount = layout->count();
            int row = patientCount / 2; // Calcula a nova posição no grid
            int col = patientCount % 2;

            PatientMonitorWidget *monitorWidget = new PatientMonitorWidget();
            monitorWidget->setPatientName(newPatient->getName());
            layout->addWidget(monitorWidget, row, col);

            // Conecta o sinal do novo paciente ao seu novo widget
            connect(newPatient, &Patient::vitalSignUpdated,
                    monitorWidget, &PatientMonitorWidget::updateDisplay);
        }
    }
}
