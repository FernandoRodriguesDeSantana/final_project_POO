#ifndef VITALSIGN_H
#define VITALSIGN_H

#include <QObject>
#include <QDateTime>
#include <QString>

class VitalSign : public QObject { // Herda de QObject
    Q_OBJECT

public:
    // Construtor agora aceita QObject* parent
    VitalSign(float heartRate, float sys, float dia, float temp, float o2, const QDateTime& dateTime, QObject *parent = nullptr);

    // Getters
    float getHeartRate() const;
    float getSystolicPressure() const;
    float getDiastolicPressure() const;
    float getBodyTemperature() const;
    float getOxygenSaturation() const;
    QDateTime getDateTime() const;
    QString toString() const; // Adicionado para facilitar o debug

private:
    float m_heartRate;
    float m_systolicPressure;
    float m_diastolicPressure;
    float m_bodyTemperature;
    float m_oxygenSaturation;
    QDateTime m_dateTime;
};

#endif // VITALSIGN_H
