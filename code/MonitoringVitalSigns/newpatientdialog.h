#ifndef NEWPATIENTDIALOG_H
#define NEWPATIENTDIALOG_H

#include <QDialog>
#include <QString>

namespace Ui {
class NewPatientDialog;
}

class NewPatientDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewPatientDialog(QWidget *parent = nullptr);
    ~NewPatientDialog();

    // Funções "getter" para a MainWindow poder pegar os dados preenchidos
    QString getName() const;
    int getAge() const;
    char getSex() const;
    int getRoom() const;
    QString getDiagnosis() const;

private:
    Ui::NewPatientDialog *ui;
};

#endif // NEWPATIENTDIALOG_H
