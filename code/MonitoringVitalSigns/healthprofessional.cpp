#include "HealthProfessional.h"

// Builder
HealthProfessional::HealthProfessional(const QString& name, int age, char sex, const QString& id, const QString& jobPosition, QObject *parent)
    : Person(name, age, sex, parent), m_id(id), m_jobPosition(jobPosition) {}

// Getters
QString HealthProfessional::getId() const { return m_id; }
QString HealthProfessional::getJobPosition() const { return m_jobPosition; }

// Setters
void HealthProfessional::setId(const QString& id) { this->m_id = id; }

void HealthProfessional::setJobPosition(const QString & jobPosition) { this->m_jobPosition = jobPosition; }
