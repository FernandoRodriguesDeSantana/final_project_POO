#include "monitoringsystem.h"
#include <QtAlgorithms> // To use qDeleteAll

MonitoringSystem::MonitoringSystem(QObject *parent)
    : QObject(parent), m_authenticatedUser(nullptr)
{
    // Constructor is ready to have wings and users added.
}

// The destructor ensures there are no memory leaks.
MonitoringSystem::~MonitoringSystem()
{
    // qDeleteAll is a Qt utility function that iterates over the list and calls 'delete' on each pointer.
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

bool MonitoringSystem::login(const QString& id)
{
    // Example logic to find a user and authenticate them
    for (HealthProfessional* user : m_users) {
        if (user->getId() == id) { // Assuming HealthProfessional has a getId() method
            m_authenticatedUser = user;
            return true;
        }
    }
    return false;
}
