// Diretivas de pré-processador (header guards) para garantir que este arquivo
// seja incluído apenas uma vez, prevenindo erros de compilação.
#ifndef PATIENTMONITORWIDGET_H
#define PATIENTMONITORWIDGET_H

// Inclusão do cabeçalho da classe QWidget, a classe base para todos os componentes visuais no Qt.
#include <QWidget>

// Bloco padrão para a declaração antecipada da classe de interface do usuário (UI).
// Isso permite ao compilador saber que 'Ui::PatientMonitorWidget' existe sem precisar
// incluir o arquivo "ui_patientmonitorwidget.h" completo aqui no cabeçalho.
QT_BEGIN_NAMESPACE
namespace Ui { class PatientMonitorWidget; }
QT_END_NAMESPACE

// Declaração da classe PatientMonitorWidget, que é o painel visual reutilizável para um único paciente.
// Herda de QWidget, o que a torna um componente que pode ser desenhado na tela.
class PatientMonitorWidget : public QWidget
{
    // Macro obrigatório para qualquer classe que utilize o sistema de Sinais e Slots do Qt.
    Q_OBJECT

public: // Início da seção de membros públicos, que formam a interface da classe.
    // Construtor explícito. Recebe um ponteiro opcional para um widget "pai".
    explicit PatientMonitorWidget(QWidget *parent = nullptr);

    // Destrutor da classe.
    ~PatientMonitorWidget();

    // Método público para configurar o nome do paciente que será exibido no painel.
    void setPatientName(const QString& name);

public slots: // Seção especial do Qt para declarar "slots" (funções que podem ser conectadas a sinais).
    // Slot público que será conectado ao sinal 'vitalSignUpdated' do objeto Patient.
    // Ele recebe os novos dados dos sinais vitais e os utiliza para atualizar a interface gráfica.
    void updateDisplay(float heartRate, float systolicPressure, float diastolicPressure, float o2sat);

private: // Início da seção de membros privados.
    // Ponteiro para a classe de interface do usuário (UI) gerada pelo Qt Designer.
    // É através deste ponteiro que o código C++ acessa os widgets (QLabels, QLCDNumbers, etc.)
    // que foram desenhados no arquivo .ui.
    Ui::PatientMonitorWidget *ui;
};

#endif // PATIENTMONITORWIDGET_H
