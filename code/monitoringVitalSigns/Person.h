#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person{
public:
    // Class builder
    Person(const std::string& name, int age, char sex);

    // Getters
    std::string getName() const;
    int getAge();
    char getSex();

    // Setters
    void setName(const std::string& name);
    void setAge(int age);
    void setSex(char sex);

protected:
    std::string name;
    int age;
    char sex;
};

#endif // PERSON_H
