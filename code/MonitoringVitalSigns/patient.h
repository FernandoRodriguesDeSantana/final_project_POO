#ifndef PATIENT_H
#define PATIENT_H

#include "person.h"
#include <QList>

class VitalSign;

class Patient : public Person {
    Q_OBJECT
public:
    Patient(const QString& name, int age, char sex, int room, const QString& diagnosis, QObject *parent = nullptr);
    ~Patient();

    void addVitalSign(VitalSign* sign);
    const QList<VitalSign*>& getVitalSigns() const;
    void generateAndUpdateVitalSign();
    int getRoom() const;
    QString getDiagnosis() const;

signals:
    void vitalSignUpdated(float heartRate, float systolicPressure, float o2sat);

private:
    int m_room;
    QString m_diagnosis; // MUDANÇA: Movido para private
    QList<VitalSign*> m_vitalSigns;
};
#endif // PATIENT_H
