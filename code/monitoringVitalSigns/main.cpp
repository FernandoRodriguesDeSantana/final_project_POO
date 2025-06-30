#include "main.h"
#include "ui_main.h" // inclui o arquivo gerado pelo Qt Designer

Main::Main(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Main)
{
    ui->setupUi(this); // vincula os widgets da interface
}

Main::~Main()
{
    delete ui; // desaloca a memória da UI
}

// Função principal com os argumentos corretos
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Main window;
    window.setWindowTitle("Sistema de Monitoramento");
    window.show();

    return app.exec();
}
