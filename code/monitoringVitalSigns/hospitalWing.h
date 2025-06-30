#ifndef HOSPITALWING_H
#define HOSPITALWING_H

#include <string>
#include <vector>
#include "Patient.h"
#include "HealthProfessional.h"

class HospitalWing {
public:
    // Builder
    HospitalWing(const std::string& name, const HealthProfessional& responsible, int capacity);

    // Getters
    std::string getName() const;
    HealthProfessional getResponsible() const;
    int getCapacity();
    std::vector<Patient> getPatients() const;

    // Setters
    void setName(const std::string& name);
    void setResponsible(const HealthProfessional& responsible);
    void setCapacity(int capacity);

private:
    std::string name;
    HealthProfessional responsible;
    int capacity;
    std::vector<Patient> patients;
};

#endif // HOSPITALWING_H
