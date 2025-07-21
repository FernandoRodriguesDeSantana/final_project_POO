#include "mainwindow.h"
#include "logindialog.h" // Incluir nosso novo diálogo
#include "monitoringsystem.h" // Incluir o sistema

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 1. Crie o sistema de monitoramento que contém os usuários
    MonitoringSystem system;
    system.setupInitialData(); // Popula com dados de teste

    // 2. Crie e exiba a janela de login
    LoginDialog loginDialog(&system);
    // loginDialog.exec() abre o diálogo e para a execução aqui até que ele seja fechado

    // 3. Verifique se o login foi bem-sucedido (o diálogo foi "aceito")
    if (loginDialog.exec() == QDialog::Accepted) {
        // Se sim, crie e mostre a janela principal
        MainWindow w;
        w.show();
        // E inicie o loop de eventos da aplicação
        return a.exec();
    } else {
        // Se não, a aplicação simplesmente termina
        return 0;
    }
}
