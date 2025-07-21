#include "Patient.h"
#include "VitalSign.h"
#include <QtAlgorithms>
#include <QDebug>

// Construtor da classe Patient, que chama o construtor da classe base Person.
Patient::Patient(const QString& name, int age, char sex, int room, const QString& diagnosis, QObject *parent)
    : Person(name, age, sex, parent), m_room(room), m_diagnosis(diagnosis) {}

// Destrutor que garante a liberação da memória de todos os VitalSign associados.
Patient::~Patient() {
    qDeleteAll(m_vitalSigns);
}

// Adiciona um ponteiro de VitalSign à lista de histórico do paciente.
void Patient::addVitalSign(VitalSign* sign) {
    if (sign) {
        sign->setParent(this); // Define este paciente como "pai" do sinal, para gerenciamento de memória do Qt.
        m_vitalSigns.append(sign);
    }
}

// Retorna uma referência constante à lista de sinais vitais.
const QList<VitalSign*>& Patient::getVitalSigns() const {
    return m_vitalSigns;
}

// Método principal da simulação: gera o próximo sinal vital e notifica a UI.
void Patient::generateAndUpdateVitalSign()
{
    // Função auxiliar (lambda) para gerar uma pequena variação aleatória a partir de um valor base.
    auto smallChange = [](float base, float range) {
        float halfRange = range / 2.0f;
        float delta = -halfRange + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / range));
        return base + delta;
    };

    float newBpm, newSys, newDia, newO2;

    if (m_vitalSigns.isEmpty()) {
        // CASO BASE: Se for o primeiro sinal vital, gera valores iniciais aleatórios dentro de uma faixa normal.
        newBpm = static_cast<float>(rand() % 20 + 70); // Entre 70-90
        newSys = static_cast<float>(rand() % 10 + 110); // Entre 110-120
        newDia = static_cast<float>(rand() % 10 + 70);  // Entre 70-80
        newO2  = static_cast<float>(rand() % 2 + 97);   // Entre 97-99
    } else {
        // LÓGICA LINEAR: Pega o último sinal vital registrado como base para o próximo.
        VitalSign* lastSign = m_vitalSigns.last();

        // Gera novos valores com uma pequena variação a partir dos últimos, tornando a simulação mais realista.
        newBpm = smallChange(lastSign->getHeartRate(), 3.0f);
        newSys = smallChange(lastSign->getSystolicPressure(), 4.0f);
        newDia = smallChange(lastSign->getDiastolicPressure(), 4.0f);
        newO2  = smallChange(lastSign->getOxygenSaturation(), 0.8f);
    }

    // Garante que os valores gerados permaneçam dentro de limites médicos realistas.
    newBpm = std::clamp(newBpm, 50.0f, 130.0f);
    newSys = std::clamp(newSys, 90.0f, 160.0f);
    newDia = std::clamp(newDia, 60.0f, 100.0f);
    newO2  = std::clamp(newO2, 92.0f, 100.0f);

    // Cria o novo objeto VitalSign com os valores calculados.
    VitalSign* newSign = new VitalSign(newBpm, newSys, newDia, 36.5f, newO2, QDateTime::currentDateTime(), this);

    this->addVitalSign(newSign);
    qDebug() << "Paciente:" << this->getName() << "Novos Sinais (Linear):" << newSign->toString();

    // Emite o sinal 'vitalSignUpdated' para que a interface gráfica (PatientMonitorWidget) possa se atualizar.
    emit vitalSignUpdated(
        newSign->getHeartRate(),
        newSign->getSystolicPressure(),
        newSign->getDiastolicPressure(),
        newSign->getOxygenSaturation()
        );
}
