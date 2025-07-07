#include "Person.h"

Person::Person(const QString& name, int age, char sex, QObject *parent)
    : QObject(parent), m_name(name), m_age(age), m_sex(sex) {}

QString Person::getName() const { return m_name; }

int Person::getAge() const { return m_age; }

char Person::getSex() const { return m_sex; }
