#include "mainwindow.h"
#include "logindialog.h"      // Inclui a definição da janela de login
#include "monitoringsystem.h" // Inclui a definição do sistema de gerenciamento

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 1. Cria o "backend" da aplicação, que gerencia todos os dados.
    MonitoringSystem system;
    system.setupInitialData(); // Popula o sistema com dados de teste (médicos, alas, pacientes).

    // 2. Cria e exibe a janela de login, passando o sistema para ela.
    LoginDialog loginDialog(&system);
    // O método .exec() abre a janela de forma "modal", ou seja, a execução do código
    // para aqui e só continua quando a janela de login for fechada.

    // 3. Verifica o resultado da janela de login.
    if (loginDialog.exec() == QDialog::Accepted) {
        // Se o login foi bem-sucedido (o diálogo foi "aceito"),
        // então cria e mostra a janela principal.
        MainWindow w;
        w.show();
        // Inicia o loop de eventos principal da aplicação.
        return a.exec();
    } else {
        // Se o login falhou ou foi cancelado, a aplicação encerra.
        return 0;
    }
}
