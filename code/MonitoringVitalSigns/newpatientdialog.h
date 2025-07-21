// Diretivas de pré-processador (header guards) para garantir que este arquivo
// seja incluído apenas uma vez durante a compilação.
#ifndef NEWPATIENTDIALOG_H
#define NEWPATIENTDIALOG_H

// Inclusão de cabeçalhos de classes do framework Qt.
#include <QDialog>  // Inclui a classe base para janelas de diálogo.
#include <QString>  // Inclui a classe de string do Qt.

// Declaração antecipada do namespace 'Ui', que conterá a classe da interface gráfica
// gerada a partir do arquivo .ui pelo Qt Designer.
namespace Ui {
class NewPatientDialog;
}

// Declaração da classe NewPatientDialog, que representa a janela de formulário
// para registrar um novo paciente. Ela herda de QDialog.
class NewPatientDialog : public QDialog
{
    // Macro obrigatório para qualquer classe que utilize o sistema de Sinais e Slots do Qt.
    Q_OBJECT

public: // Início da seção de membros públicos, a interface da classe.
    // Construtor explícito da classe.
    explicit NewPatientDialog(QWidget *parent = nullptr);

    // Destrutor da classe.
    ~NewPatientDialog();

    // Métodos "getter" públicos que permitem que a MainWindow (ou outra classe)
    // recupere os dados que foram inseridos nos campos do formulário.
    // 'const' indica que estes métodos não alteram o estado do diálogo.
    QString getName() const;       // Retorna o nome do paciente digitado.
    int getAge() const;          // Retorna a idade do paciente digitada.
    char getSex() const;         // Retorna o sexo do paciente digitado.
    int getRoom() const;         // Retorna o número do leito digitado.
    QString getDiagnosis() const;  // Retorna o diagnóstico digitado.

private: // Início da seção de membros privados.
    // Ponteiro para a classe de interface do usuário (UI) gerada pelo Qt Designer.
    // É através deste ponteiro que o código C++ acessa os widgets (QLineEdit, etc.)
    // que foram desenhados na tela.
    Ui::NewPatientDialog *ui;
};

#endif // NEWPAT-IENTDIALOG_H
