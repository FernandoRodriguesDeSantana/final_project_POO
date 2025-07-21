#include "newpatientdialog.h"
#include "ui_newpatientdialog.h"

NewPatientDialog::NewPatientDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewPatientDialog)
{
    ui->setupUi(this);
}

NewPatientDialog::~NewPatientDialog()
{
    delete ui;
}

// Implementação dos getters que leem os dados dos QLineEdits
QString NewPatientDialog::getName() const {
    return ui->lineEditName->text();
}

int NewPatientDialog::getAge() const {
    return ui->lineEditAge->text().toInt();
}

char NewPatientDialog::getSex() const {
    // Pega o primeiro caractere, ou ' ' se estiver vazio
    return ui->lineEditSex->text().isEmpty() ? ' ' : ui->lineEditSex->text().at(0).toLatin1();
}

int NewPatientDialog::getRoom() const {
    return ui->lineEditRoom->text().toInt();
}

QString NewPatientDialog::getDiagnosis() const {
    return ui->lineEditDiagnosis->text();
}
