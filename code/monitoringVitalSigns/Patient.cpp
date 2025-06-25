#include "Patient.h"

// Builder
Patient::Patient(const std::string& name, int age, char sex, int room, std::string& diagnosis) : Person(name, age, sex), room(room), diagnosis(diagnosis){}

// Getters
int Patient::getRoom(){
    return room;
}

std::string Patient::getDiagnosis() const{
    return diagnosis;
}

// Setters
void Patient::setRoom(int room){
    this->room = room;
}

void Patient::setDiagnosis(const std::string& diagnosis){
    this->diagnosis = diagnosis;
}
