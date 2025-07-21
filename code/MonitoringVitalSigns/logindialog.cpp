#include "logindialog.h"
#include "ui_logindialog.h"
#include <QPushButton>

// Construtor do diálogo de login.
LoginDialog::LoginDialog(MonitoringSystem* system, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog),
    m_system(system)
{
    ui->setupUi(this);

    // Pega um ponteiro para o botão "OK" da caixa de botões.
    QPushButton *okButton = ui->buttonBox->button(QDialogButtonBox::Ok);
    // Conecta o clique do botão ao nosso slot de validação.
    connect(okButton, &QPushButton::clicked, this, &LoginDialog::on_loginButton_clicked);

    // Desconecta o comportamento padrão do botão "OK" para impedir que ele feche
    // o diálogo automaticamente antes da nossa validação.
    disconnect(ui->buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
}

// Destrutor.
LoginDialog::~LoginDialog()
{
    delete ui;
}

// Slot que executa a lógica de login quando o botão "OK" é clicado.
void LoginDialog::on_loginButton_clicked()
{
    // Pega os dados dos campos de texto.
    QString id = ui->lineEditId->text();
    QString password = ui->lineEditPassword->text();

    // Chama o método de login do sistema.
    if (m_system->login(id, password)) {
        // Se o login for válido, nós mesmos chamamos accept().
        // Isso fecha o diálogo e retorna um resultado positivo (QDialog::Accepted).
        accept();
    } else {
        // Se o login for inválido, exibe uma mensagem de erro.
        // O diálogo permanece aberto para uma nova tentativa.
        ui->errorLabel->setText("ID de usuário ou senha inválidos.");
        ui->lineEditPassword->clear();
    }
}
