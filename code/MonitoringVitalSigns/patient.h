#ifndef PATIENT_H
#define PATIENT_H

#include "Person.h"
#include <string>

class Patient : public Person {
public:
    // Builder
    Patient(const std::string& name, int age, char sex, int room, std::string& diagnosis);

    // Getters
    int getRoom();
    std::string getDiagnosis() const;

    // Setters
    void setRoom(int room);
    void setDiagnosis(const std::string& diagnosis);

private:
    int room;
    std::string diagnosis;
};

#endif // PATIENT_H
