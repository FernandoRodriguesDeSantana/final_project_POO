#include "main.h"
#include "ui_main.h" // importante: inclui a interface gerada

Main::Main(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Main)
{
    ui->setupUi(this); // vincula os widgets da interface
}

Main::~Main()
{
    delete ui; // libera memória alocada com new
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Main window;
    window.setWindowTitle("Sistema de Monitoramento");
    window.show();

    return app.exec();
}
