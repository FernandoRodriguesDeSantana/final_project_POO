#include "monitoringsystem.h"
#include <QtAlgorithms>
#include "healthprofessional.h"
#include "patient.h"

MonitoringSystem::MonitoringSystem(QObject *parent)
    : QObject(parent), m_authenticatedUser(nullptr)
{}

MonitoringSystem::~MonitoringSystem()
{
    qDeleteAll(m_wings);
    qDeleteAll(m_users);
}

void MonitoringSystem::addWing(HospitalWing* wing)
{
    if (wing) {
        m_wings.append(wing);
    }
}

void MonitoringSystem::addUser(HealthProfessional* user)
{
    if (user) {
        m_users.append(user);
    }
}

HospitalWing* MonitoringSystem::findWingByName(const QString& name)
{
    for (HospitalWing* wing : m_wings) {
        if (wing->getName() == name) { // Assuming HospitalWing has a getName() method
            return wing;
        }
    }
    return nullptr; // Return null if not found
}

const QList<HospitalWing*>& MonitoringSystem::getWings() const
{
    return m_wings;
}

bool MonitoringSystem::login(const QString& id, const QString& password)
{
    for (HealthProfessional* user : m_users) {
        if (user->getId() == id) {
            if (user->checkPassword(password)) {
                m_authenticatedUser = user;
                return true; // Login bem-sucedido!
            }
        }
    }
    m_authenticatedUser = nullptr;
    return false; // Usuário não encontrado ou senha incorreta
}

void MonitoringSystem::setupInitialData()
{
    // Criar profissionais com senhas
    auto* drHouse = new HealthProfessional("Gregory House", 59, 'M', "111", "Infectologista", "senha123", this);
    addUser(drHouse);

    // Criar alas
    auto* uci = new HospitalWing("UTI", drHouse, 10, this);
    addWing(uci);

    // Criar pacientes e adicioná-los diretamente à ala
    uci->addPatient(new Patient("John Doe", 45, 'M', 101, "Desconhecido", uci));
    uci->addPatient(new Patient("Jane Smith", 62, 'F', 102, "Pneumonia", uci));
    uci->addPatient(new Patient("Peter Jones", 75, 'M', 103, "Infarto", uci));
    uci->addPatient(new Patient("Mary Williams", 55, 'F', 104, "Pós-operatório", uci));
}
