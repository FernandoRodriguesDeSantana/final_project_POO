// Inclui o arquivo de cabeçalho correspondente, que contém a declaração da classe NewPatientDialog.
#include "newpatientdialog.h"
// Inclui o arquivo de cabeçalho gerado pelo Qt Designer, que define a classe Ui::NewPatientDialog.
#include "ui_newpatientdialog.h"

// Implementação do construtor da classe.
NewPatientDialog::NewPatientDialog(QWidget *parent) :
    QDialog(parent),                    // Chama o construtor da classe base QDialog.
    ui(new Ui::NewPatientDialog)        // Inicializa o ponteiro 'ui' com uma nova instância da classe da interface.
{
    // O método setupUi() constrói a interface gráfica (widgets, layouts, etc.)
    // que foi desenhada no arquivo .ui e a aplica a este diálogo.
    ui->setupUi(this);
}

// Implementação do destrutor.
NewPatientDialog::~NewPatientDialog()
{
    // Deleta o objeto 'ui' para liberar a memória alocada para os componentes da interface.
    delete ui;
}

// Implementação dos métodos "getters".
// Estes métodos são chamados pela MainWindow para obter os dados inseridos no formulário.

// Retorna o texto do campo de nome.
QString NewPatientDialog::getName() const {
    // Acessa o widget 'lineEditName' através do ponteiro 'ui' e retorna seu texto.
    return ui->lineEditName->text();
}

// Retorna o texto do campo de idade, convertido para um número inteiro.
int NewPatientDialog::getAge() const {
    // O método toInt() converte a string (texto) em um número.
    return ui->lineEditAge->text().toInt();
}

// Retorna o texto do campo de sexo como um único caractere.
char NewPatientDialog::getSex() const {
    // Usa um operador ternário: se o campo de texto estiver vazio, retorna um espaço (' ').
    // Caso contrário, pega o primeiro caractere (.at(0)) do texto e o converte para o formato char.
    return ui->lineEditSex->text().isEmpty() ? ' ' : ui->lineEditSex->text().at(0).toLatin1();
}

// Retorna o texto do campo de leito, convertido para um número inteiro.
int NewPatientDialog::getRoom() const {
    return ui->lineEditRoom->text().toInt();
}

// Retorna o texto do campo de diagnóstico.
QString NewPatientDialog::getDiagnosis() const {
    return ui->lineEditDiagnosis->text();
}
