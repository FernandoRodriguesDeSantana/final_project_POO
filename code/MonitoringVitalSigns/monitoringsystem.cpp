#include "monitoringsystem.h"
#include <QtAlgorithms>
#include "healthprofessional.h"
#include "patient.h"
#include "monitoringsystem.h"

// Construtor.
MonitoringSystem::MonitoringSystem(QObject *parent)
    : QObject(parent), m_authenticatedUser(nullptr)
{}

// Destrutor que libera a memória das listas de alas e usuários.
MonitoringSystem::~MonitoringSystem()
{
    // qDeleteAll é uma função do Qt que chama 'delete' em cada ponteiro da lista.
    qDeleteAll(m_wings);
    qDeleteAll(m_users);
}

// Adiciona uma nova ala à lista do sistema.
void MonitoringSystem::addWing(HospitalWing* wing)
{
    if (wing) {
        m_wings.append(wing);
    }
}

// Adiciona um novo usuário (profissional de saúde) à lista do sistema.
void MonitoringSystem::addUser(HealthProfessional* user)
{
    if (user) {
        m_users.append(user);
    }
}

// Valida as credenciais de um usuário.
bool MonitoringSystem::login(const QString& id, const QString& password)
{
    // Procura o usuário pelo ID.
    for (HealthProfessional* user : m_users) {
        if (user->getId() == id) {
            // Se o usuário for encontrado, verifica a senha.
            if (user->checkPassword(password)) {
                m_authenticatedUser = user; // Armazena o usuário autenticado.
                return true; // Sucesso.
            }
        }
    }
    m_authenticatedUser = nullptr;
    return false; // Falha (usuário não encontrado ou senha incorreta).
}

// Popula o sistema com dados de teste para a demonstração.
void MonitoringSystem::setupInitialData()
{
    // Cria profissionais de saúde com senhas.
    auto* drHouse = new HealthProfessional("Gregory House", 59, 'M', "111", "Infectologista", "senha123", this);
    addUser(drHouse);

    // Cria alas.
    auto* uci = new HospitalWing("UTI", drHouse, 10, this);
    addWing(uci);

    // Cria pacientes e os adiciona à ala.
    uci->addPatient(new Patient("John Doe", 45, 'M', 101, "Desconhecido", uci));
    uci->addPatient(new Patient("Jane Smith", 62, 'F', 102, "Pneumonia", uci));
}

const QList<HospitalWing*>& MonitoringSystem::getWings() const
{
    return m_wings;
}
