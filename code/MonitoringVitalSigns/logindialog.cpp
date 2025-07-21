#include "logindialog.h"
#include "ui_logindialog.h"
#include <QPushButton> // Adicionar este include para acessar o botão

LoginDialog::LoginDialog(MonitoringSystem* system, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog),
    m_system(system)
{
    ui->setupUi(this);

    // MUDANÇA: Vamos nos conectar diretamente ao clique do botão OK.
    // Isso nos dá controle total e evita o fechamento automático do diálogo.
    QPushButton *okButton = ui->buttonBox->button(QDialogButtonBox::Ok);
    connect(okButton, &QPushButton::clicked, this, &LoginDialog::on_loginButton_clicked);

    // MUDANÇA: Desconectamos o sinal 'accepted' para garantir que ele não feche a janela sozinho.
    disconnect(ui->buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_loginButton_clicked()
{
    QString id = ui->lineEditId->text();
    QString password = ui->lineEditPassword->text();

    if (m_system->login(id, password)) {
        // Se o login for bem-sucedido, NÓS chamamos accept().
        // Isso fecha a janela e retorna QDialog::Accepted.
        accept();
    } else {
        // Se o login falhar, mostramos um erro e a janela permanece aberta,
        // pois não estamos chamando accept() nem reject().
        ui->errorLabel->setText("ID de usuário ou senha inválidos.");
        ui->lineEditPassword->clear();
    }
}
