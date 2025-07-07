#ifndef HOSPITALWING_H
#define HOSPITALWING_H

#include <QObject>
#include <QString>
#include <QList>

class Patient;
class HealthProfessional;

class HospitalWing : public QObject {
    Q_OBJECT
public:
    HospitalWing(const QString& name, HealthProfessional* responsible, int capacity, QObject *parent = nullptr);
    ~HospitalWing();

    void addPatient(Patient* patient);
    QString getName() const;
    const QList<Patient*>& getPatients() const;

private:
    QString m_name;
    HealthProfessional* m_responsible;
    int m_capacity;
    QList<Patient*> m_patients;
};
#endif // HOSPITALWING_H
