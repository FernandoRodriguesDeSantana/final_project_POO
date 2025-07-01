#include "HospitalWing.h"

// Builder
HospitalWing::HospitalWing(const std::string& name, const HealthProfessional& responsible, int capacity) : name(name), responsible(responsible), capacity(capacity) {}

// Getters
std::string HospitalWing::getName() const {
    return name;
}

HealthProfessional HospitalWing::getResponsible() const {
    return responsible;
}

int HospitalWing::getCapacity() {
    return capacity;
}

std::vector<Patient> HospitalWing::getPatients() const {
    return patients;
}

// Setters
void HospitalWing::setName(const std::string& name) {
    this->name = name;
}

void HospitalWing::setResponsible(const HealthProfessional& responsible) {
    this->responsible = responsible;
}

void HospitalWing::setCapacity(int capacity) {
    this->capacity = capacity;
}
