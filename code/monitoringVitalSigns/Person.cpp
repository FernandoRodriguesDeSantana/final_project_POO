#include "Person.h"

// Builder
Person::Person(const std::string& name, int age, char sex) : name(name), age(age), sex(sex) {};


// Getters
std::string Person::getName() const{
    return name;
}

int Person::getAge(){
    return age;
}

char Person::getSex(){
    return sex;
}


// Setters
void Person::setName(const std::string& name){
    this->name = name;
}

void Person::setAge(int age){
    this->age = age;
}

void Person::setSex(char sex){
    this->sex = sex;
}
