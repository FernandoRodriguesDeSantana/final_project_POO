#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include "monitoringsystem.h" // Incluir para poder verificar o login

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    // O construtor recebe o sistema para poder chamar a função de login
    explicit LoginDialog(MonitoringSystem* system, QWidget *parent = nullptr);
    ~LoginDialog();

private slots:
    // Slot que será chamado quando o botão de login for clicado
    void on_loginButton_clicked();

private:
    Ui::LoginDialog *ui;
    MonitoringSystem* m_system; // Ponteiro para o sistema principal
};

#endif // LOGINDIALOG_H
