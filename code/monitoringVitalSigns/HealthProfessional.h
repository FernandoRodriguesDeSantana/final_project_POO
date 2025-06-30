#ifndef HEALTHPROFESSIONAL_H
#define HEALTHPROFESSIONAL_H
#include "Person.h"
#include <string>

class HealthProfessional : public Person {
public:
    // Builder
    HealthProfessional(const std::string& name, int age, char sex, const std::string& id, const std::string& jobPosition);

    // Getters
    std::string getId() const;
    std::string getJobPosition() const;

    // Setters
    void setId(const std::string& id);
    void setJobPosition(const std::string& jobPosition);

private:
    std::string id;
    std::string jobPosition;
};

#endif // HEALTHPROFESSIONAL_H
