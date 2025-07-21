// Inclui o arquivo de cabeçalho correspondente, que contém a declaração da classe HospitalWing.
#include "hospitalwing.h"
// Inclui o cabeçalho de Patient, necessário para o método addPatient.
#include "patient.h"

// Implementação do construtor da classe HospitalWing.
// A lista de inicializadores (após os dois-pontos) atribui os valores recebidos
// aos membros da classe e chama o construtor da classe base QObject.
HospitalWing::HospitalWing(const QString& name, HealthProfessional* responsible, int capacity, QObject *parent)
    : QObject(parent), m_name(name), m_responsible(responsible), m_capacity(capacity) {}

// Implementação do destrutor.
// Ele está vazio porque a responsabilidade de deletar os objetos Patient
// é da classe MonitoringSystem, para evitar que um mesmo objeto seja deletado duas vezes.
HospitalWing::~HospitalWing() {}

// Implementação do método para adicionar um paciente à ala.
void HospitalWing::addPatient(Patient* patient) {
    // Verifica se o ponteiro do paciente não é nulo antes de adicioná-lo à lista.
    if (patient) {
        // Adiciona o ponteiro do paciente ao final da lista m_patients.
        m_patients.append(patient);
    }
}

// Implementação dos métodos "Getters".
// Retorna o nome da ala.
QString HospitalWing::getName() const { return m_name; }

// Retorna uma referência constante à lista de ponteiros de pacientes.
// A referência (&) evita a criação de uma cópia da lista, o que é mais eficiente.
const QList<Patient*>& HospitalWing::getPatients() const { return m_patients; }
