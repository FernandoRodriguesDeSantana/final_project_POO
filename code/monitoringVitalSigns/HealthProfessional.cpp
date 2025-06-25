#include "HealthProfessional.h"

// Builder
HealthProfessional::HealthProfessional(const std::string& name, int age, char sex, std::string& id, std::string& jobPosition) : Person(name, age, sex), id(id), jobPosition(jobPosition) {}

// Getters
std::string HealthProfessional::getId const(){
    return id;
}
// Setters
