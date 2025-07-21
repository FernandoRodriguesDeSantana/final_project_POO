// Diretivas de pré-processador (header guards) para garantir que este arquivo
// seja incluído apenas uma vez, prevenindo erros de compilação.
#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

// Inclusão de cabeçalhos de classes do Qt e do seu projeto.
#include <QDialog>           // Inclui a classe base para janelas de diálogo do Qt.
#include "monitoringsystem.h" // Inclui a definição do sistema principal para que o diálogo possa interagir com ele.

// Declaração antecipada do namespace 'Ui', que contém a classe gerada pelo Qt Designer.
// Isso permite que o ponteiro 'ui' seja declarado sem a necessidade de incluir "ui_logindialog.h" aqui.
namespace Ui {
class LoginDialog;
}

// Declaração da classe LoginDialog, que representa a janela de login.
// Herda de QDialog, a classe padrão do Qt para diálogos modais (janelas que bloqueiam a principal).
class LoginDialog : public QDialog
{
    // Macro obrigatório para qualquer classe que utilize o sistema de Sinais e Slots do Qt.
    Q_OBJECT

public: // Início da seção de membros públicos.
    // Construtor da classe.
    // 'explicit' previne conversões implícitas.
    // Recebe um ponteiro para o MonitoringSystem para poder chamar a função de login.
    explicit LoginDialog(MonitoringSystem* system, QWidget *parent = nullptr);

    // Destrutor da classe, responsável por liberar a memória.
    ~LoginDialog();

private slots: // Seção especial do Qt para declarar "slots" (funções que reagem a sinais).
    // Slot que será conectado ao sinal de clique do botão de login.
    // Esta função conterá a lógica para verificar as credenciais.
    void on_loginButton_clicked();

private: // Início da seção de membros privados.
    // Ponteiro para a classe de interface do usuário (UI) gerada pelo Qt Designer.
    // É através dele que o código C++ acessa os widgets (botões, campos de texto) da janela.
    Ui::LoginDialog *ui;

    // Ponteiro para o objeto do sistema principal.
    // Armazena a referência ao "backend" para que este diálogo possa validar o login.
    MonitoringSystem* m_system;
};

#endif // LOGINDIALOG_H
