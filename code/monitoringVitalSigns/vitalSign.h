#ifndef SINALVITAL_H
#define SINALVITAL_H

#include <string>

class VitalSign {
public:
    VitalSign(float heartRate, float systolicPressure, float diastolicPressure, float bodyTemperature, float oxygenSaturation, const std::string& dataTime);

    // Getters
    float getHeartRate() const;
    float getSystolicPressure() const;
    float getDiastolicPressure() const;
    float getBodyTemperature() const;
    float getOxygenSaturation() const;
    std::string getDataTime() const;

    // Método estático para gerar sinais aleatórios
    static VitalSign randomGeneration();

private:
    float heartRate;
    float systolicPressure;
    float diastolicPressure;
    float bodyTemperature;
    float oxygenSaturation;
    std::string dataTime;
};

#endif // SINALVITAL_H
