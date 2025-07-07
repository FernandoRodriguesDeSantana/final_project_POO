#include "VitalSign.h"
#include <cstdlib>
#include <ctime>

VitalSign::VitalSign(float heartRate, float sys, float dia, float temp, float o2, const QDateTime& dateTime, QObject *parent)
    : QObject(parent), m_heartRate(heartRate), m_systolicPressure(sys), m_diastolicPressure(dia),
    m_bodyTemperature(temp), m_oxygenSaturation(o2), m_dateTime(dateTime) {}

// Getters...
float VitalSign::getHeartRate() const { return m_heartRate; }
float VitalSign::getSystolicPressure() const { return m_systolicPressure; }
float VitalSign::getDiastolicPressure() const { return m_diastolicPressure; }
float VitalSign::getBodyTemperature() const { return m_bodyTemperature; }
float VitalSign::getOxygenSaturation() const { return m_oxygenSaturation; }
QDateTime VitalSign::getDateTime() const { return m_dateTime; }

QString VitalSign::toString() const {
    return QString("HR: %1, BP: %2/%3, SpO2: %4").arg(m_heartRate).arg(m_systolicPressure).arg(m_diastolicPressure).arg(m_oxygenSaturation);
}

VitalSign* VitalSign::randomGeneration() {
    static bool started = false;
    if (!started) {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        started = true;
    }

    auto generate = [](float min, float max) {
        return min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (max - min)));
    };

    float bpm = generate(60.0f, 100.0f);
    float sys = generate(100.0f, 130.0f);
    float dia = generate(60.0f, 90.0f);
    float temp = generate(36.0f, 37.5f);
    float sat = generate(95.0f, 100.0f);

    QDateTime currentTime = QDateTime::currentDateTime();

    return new VitalSign(bpm, sys, dia, temp, sat, currentTime);
}
