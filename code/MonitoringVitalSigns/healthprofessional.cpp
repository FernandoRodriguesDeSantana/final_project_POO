#include "HealthProfessional.h"

// Builder
HealthProfessional::HealthProfessional(const std::string& name, int age, char sex, const std::string& id, const std::string& jobPosition) : Person(name, age, sex), id(id), jobPosition(jobPosition) {}

// Getters
std::string HealthProfessional::getId() const {
    return id;
}

std::string HealthProfessional::getJobPosition() const {
    return jobPosition;
}

// Setters
void HealthProfessional::setId(const std::string& id) {
    this->id = id;
}

void HealthProfessional::setJobPosition(const std::string & jobPosition) {
    this->jobPosition = jobPosition;
}
