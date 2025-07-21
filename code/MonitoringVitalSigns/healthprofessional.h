#ifndef HEALTHPROFESSIONAL_H
#define HEALTHPROFESSIONAL_H
#include "Person.h"
#include <QString>
#include <QObject>

class HealthProfessional : public Person {
    Q_OBJECT;

public:
    // Builder
    HealthProfessional(const QString& name, int age, char sex, const QString& id, const QString& jobPosition, const QString& password, QObject *parent = nullptr);

    // Getters
    QString getId() const;
    QString getJobPosition() const;
    bool checkPassword(const QString& password) const;

    // Setters
    void setId(const QString& id);
    void setJobPosition(const QString& jobPosition);

private:
    QString m_id;
    QString m_jobPosition;
    QString m_password;
};

#endif // HEALTHPROFESSIONAL_H
