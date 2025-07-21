// Inclui o arquivo de cabeçalho correspondente, que contém a declaração da classe VitalSign.
#include "VitalSign.h"
// Includes das bibliotecas padrão de C++ para geração de números aleatórios.
#include <cstdlib>
#include <ctime>

// Implementação do construtor da classe VitalSign.
// A lista de inicializadores (após os dois-pontos) atribui os valores recebidos como parâmetros
// aos respectivos atributos (variáveis de membro) da classe.
VitalSign::VitalSign(float heartRate, float sys, float dia, float temp, float o2, const QDateTime& dateTime, QObject *parent)
    : QObject(parent), m_heartRate(heartRate), m_systolicPressure(sys), m_diastolicPressure(dia),
    m_bodyTemperature(temp), m_oxygenSaturation(o2), m_dateTime(dateTime) {}

// Implementação dos métodos "Getters".
// Cada método simplesmente retorna o valor do atributo privado correspondente.
float VitalSign::getHeartRate() const { return m_heartRate; }
float VitalSign::getSystolicPressure() const { return m_systolicPressure; }
float VitalSign::getDiastolicPressure() const { return m_diastolicPressure; }
float VitalSign::getBodyTemperature() const { return m_bodyTemperature; }
float VitalSign::getOxygenSaturation() const { return m_oxygenSaturation; }
QDateTime VitalSign::getDateTime() const { return m_dateTime; }

// Implementação do método toString, útil para depuração e logs.
// Retorna uma string (QString) formatada com os principais sinais vitais.
QString VitalSign::toString() const {
    // O método .arg() substitui os marcadores (%1, %2, etc.) pelos valores das variáveis,
    // criando uma string única e legível.
    return QString("HR: %1, BP: %2/%3, SpO2: %4").arg(m_heartRate).arg(m_systolicPressure).arg(m_diastolicPressure).arg(m_oxygenSaturation);
}
