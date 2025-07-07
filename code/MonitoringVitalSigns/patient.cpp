#include "Patient.h"
#include "VitalSign.h"
#include <QtAlgorithms>
#include <QDebug>

Patient::Patient(const QString& name, int age, char sex, int room, const QString& diagnosis, QObject *parent)
    : Person(name, age, sex, parent), m_room(room), m_diagnosis(diagnosis) {}

Patient::~Patient() {
    qDeleteAll(m_vitalSigns);
}

int Patient::getRoom() const { return m_room; }
QString Patient::getDiagnosis() const { return m_diagnosis; }

void Patient::addVitalSign(VitalSign* sign) {
    if (sign) {
        sign->setParent(this);
        m_vitalSigns.append(sign);
    }
}

const QList<VitalSign*>& Patient::getVitalSigns() const {
    return m_vitalSigns;
}

void Patient::generateAndUpdateVitalSign()
{
    // Função auxiliar para gerar uma pequena variação
    auto smallChange = [](float base, float range) {
        float halfRange = range / 2.0f;
        // Gera um número aleatório entre -halfRange e +halfRange
        float delta = -halfRange + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / range));
        return base + delta;
    };

    float newBpm, newSys, newDia, newO2;

    if (m_vitalSigns.isEmpty()) {
        // CASO BASE: Se for o primeiro sinal vital, gera um valor aleatório inicial.
        newBpm = static_cast<float>(rand() % 20 + 70); // Entre 70-90
        newSys = static_cast<float>(rand() % 10 + 110); // Entre 110-120
        newDia = static_cast<float>(rand() % 10 + 70);  // Entre 70-80
        newO2  = static_cast<float>(rand() % 2 + 97);   // Entre 97-99
    } else {
        // LÓGICA LINEAR: Pega o último sinal como base para o próximo.
        VitalSign* lastSign = m_vitalSigns.last();

        // Gera novos valores com uma pequena variação a partir dos últimos
        newBpm = smallChange(lastSign->getHeartRate(), 3.0f);          // Varia no máximo +/- 1.5
        newSys = smallChange(lastSign->getSystolicPressure(), 4.0f);   // Varia no máximo +/- 2.0
        newDia = smallChange(lastSign->getDiastolicPressure(), 4.0f);  // Varia no máximo +/- 2.0
        newO2  = smallChange(lastSign->getOxygenSaturation(), 0.8f);  // Varia no máximo +/- 0.4
    }

    // Garante que os valores não saiam de limites realistas (muito importante!)
    newBpm = std::clamp(newBpm, 50.0f, 130.0f);
    newSys = std::clamp(newSys, 90.0f, 160.0f);
    newDia = std::clamp(newDia, 60.0f, 100.0f);
    newO2  = std::clamp(newO2, 92.0f, 100.0f);

    // Cria o novo objeto VitalSign com os valores calculados
    VitalSign* newSign = new VitalSign(
        newBpm,
        newSys,
        newDia,
        36.5f, // Temperatura pode ser fixa por enquanto
        newO2,
        QDateTime::currentDateTime(),
        this // Define o paciente como "pai" do objeto para gerenciamento de memória
        );

    this->addVitalSign(newSign);
    qDebug() << "Paciente:" << this->getName() << "Novos Sinais (Linear):" << newSign->toString();

    // Emite o sinal para a UI se atualizar, como antes
    emit vitalSignUpdated(
        newSign->getHeartRate(),
        newSign->getSystolicPressure(),
        newSign->getDiastolicPressure(),
        newSign->getOxygenSaturation()
        );
}
