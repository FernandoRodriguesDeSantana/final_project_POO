#ifndef PERSON_H
#define PERSON_H

#include <QObject>
#include <QString>

class Person : public QObject {
    Q_OBJECT

public:
    Person(const QString& name, int age, char sex, QObject *parent = nullptr);

    // Getters
    QString getName() const;
    int getAge() const;
    char getSex() const;

protected:
    QString m_name;
    int m_age;
    char m_sex;
};

#endif // PERSON_H
