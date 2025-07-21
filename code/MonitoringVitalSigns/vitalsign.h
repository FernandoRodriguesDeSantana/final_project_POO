// Diretivas de pré-processador (header guards) que garantem que o conteúdo
// deste arquivo seja incluído apenas uma vez durante a compilação, prevenindo erros.
#ifndef VITALSIGN_H
#define VITALSIGN_H

// Inclusão de cabeçalhos de classes do framework Qt.
#include <QObject>      // Classe base para se integrar ao sistema de objetos do Qt.
#include <QDateTime>    // Classe para armazenar e manipular informações de data e hora.
#include <QString>      // Classe para manipulação de texto.

// Declaração da classe VitalSign, que representa um único registro de sinais vitais.
// Herda de QObject para que sua memória possa ser gerenciada pelo sistema de parentesco do Qt.
class VitalSign : public QObject {
    // Macro obrigatório para classes que usam o sistema de meta-objetos do Qt (sinais, slots, etc.).
    Q_OBJECT

public: // Início da seção de membros públicos.
    // Construtor da classe.
    // Recebe todos os valores dos sinais vitais e um ponteiro opcional para um objeto "pai".
    VitalSign(float heartRate, float sys, float dia, float temp, float o2, const QDateTime& dateTime, QObject *parent = nullptr);

    // Métodos "Getters" para acessar os dados privados do objeto.
    // O 'const' no final indica que o método não modifica o estado do objeto.
    float getHeartRate() const;        // Retorna a frequência cardíaca.
    float getSystolicPressure() const; // Retorna a pressão sistólica.
    float getDiastolicPressure() const;// Retorna a pressão diastólica.
    float getBodyTemperature() const;  // Retorna a temperatura corporal.
    float getOxygenSaturation() const; // Retorna a saturação de oxigênio.
    QDateTime getDateTime() const;     // Retorna a data e hora do registro.
    QString toString() const;          // Retorna uma string formatada com os dados, útil para debug.

private: // Início da seção de membros privados.
    // Atributos que armazenam o estado de um registro de sinal vital.
    float m_heartRate;
    float m_systolicPressure;
    float m_diastolicPressure;
    float m_bodyTemperature;
    float m_oxygenSaturation;
    QDateTime m_dateTime;
};

#endif // VITALSIGN_H
