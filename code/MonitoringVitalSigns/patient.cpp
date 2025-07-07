#include "Patient.h"
#include "VitalSign.h"
#include <QtAlgorithms>
#include <QDebug>

Patient::Patient(const QString& name, int age, char sex, int room, const QString& diagnosis, QObject *parent)
    : Person(name, age, sex, parent), m_room(room), m_diagnosis(diagnosis) {}

Patient::~Patient() {
    qDeleteAll(m_vitalSigns);
}

int Patient::getRoom() const { return m_room; }
QString Patient::getDiagnosis() const { return m_diagnosis; }

void Patient::addVitalSign(VitalSign* sign) {
    if (sign) {
        sign->setParent(this);
        m_vitalSigns.append(sign);
    }
}

const QList<VitalSign*>& Patient::getVitalSigns() const {
    return m_vitalSigns;
}

void Patient::generateAndUpdateVitalSign() {
    VitalSign* newSign = VitalSign::randomGeneration();
    this->addVitalSign(newSign);

    qDebug() << "Paciente:" << this->getName() << "Novos Sinais:" << newSign->toString();

    emit vitalSignUpdated(
        newSign->getHeartRate(),
        newSign->getSystolicPressure(),
        newSign->getDiastolicPressure(),
        newSign->getOxygenSaturation()
        );
}
