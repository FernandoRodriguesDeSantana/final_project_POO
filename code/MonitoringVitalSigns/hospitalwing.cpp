#include "hospitalwing.h"
#include "patient.h"

HospitalWing::HospitalWing(const QString& name, HealthProfessional* responsible, int capacity, QObject *parent)
    : QObject(parent), m_name(name), m_responsible(responsible), m_capacity(capacity) {}

// O sistema (MonitoringSystem) será "dono" dos pacientes, então a ala não os deleta.
HospitalWing::~HospitalWing() {}

void HospitalWing::addPatient(Patient* patient) {
    if (patient) {
        m_patients.append(patient);
    }
}

QString HospitalWing::getName() const { return m_name; }
const QList<Patient*>& HospitalWing::getPatients() const { return m_patients; }
