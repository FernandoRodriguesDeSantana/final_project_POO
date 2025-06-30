#include "VitalSign.h"
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <iomanip>

// Builder
VitalSign::VitalSign(float heartRate, float systolicPressure, float diastolicPressure, float bodyTemperature, float oxygenSaturation, const std::string& dataTime) : heartRate(heartRate), systolicPressure(systolicPressure), diastolicPressure(diastolicPressure), bodyTemperature(bodyTemperature), oxygenSaturation(oxygenSaturation), dataTime(dataTime) {};

// Getters
float VitalSign::getHeartRate() const {
    return heartRate;
}

float VitalSign::getSystolicPressure() const {
    return systolicPressure;
}

float VitalSign::getDiastolicPressure() const {
    return diastolicPressure;
}

float VitalSign::getBodyTemperature() const {
    return bodyTemperature;
}

float VitalSign::getOxygenSaturation() const {
    return oxygenSaturation;
}

std::string VitalSign::getDataTime() const {
    return dataTime;
}


VitalSign VitalSign::randomGeneration() {
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

    std::ostringstream dataTime;
    dataTime << "30/06/2025 14:" << std::setw(2) << std::setfill('0') << (rand() % 60);

    return VitalSign(bpm, sys, dia, temp, sat, dataTime.str());
}
