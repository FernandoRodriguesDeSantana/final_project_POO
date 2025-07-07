#ifndef MONITORINGSYSTEM_H
#define MONITORINGSYSTEM_H

#include <QObject>
#include <QList>
#include "hospitalwing.h"
#include "healthprofessional.h"

class MonitoringSystem : public QObject
{
    Q_OBJECT
public:
    explicit MonitoringSystem(QObject *parent = nullptr);
    ~MonitoringSystem();

    void addWing(HospitalWing* wing);
    void addUser(HealthProfessional* user);

    bool login(const QString& id);
    HospitalWing* findWingByName(const QString& name);
    const QList<HospitalWing*>& getWings() const;

private:
    // Composition Relationship: The System "owns" the Wings and Users
    QList<HospitalWing*> m_wings;
    QList<HealthProfessional*> m_users;

    // Currently authenticated user
    HealthProfessional* m_authenticatedUser;
};

#endif // MONITORINGSYSTEM_H
