// Diretivas de pré-processador para evitar a inclusão múltipla do mesmo arquivo de cabeçalho.
// Isso previne erros de "redefinição" durante a compilação.
#ifndef HOSPITALWING_H
#define HOSPITALWING_H

// Inclui os cabeçalhos das classes do framework Qt que serão utilizadas.
#include <QObject> // Classe base para todos os objetos Qt, permitindo o uso de sinais e slots.
#include <QString> // Classe para manipulação de texto (strings).
#include <QList>   // Classe de contêiner (lista dinâmica) do Qt.

// Declarações antecipadas (forward declarations).
// Informam ao compilador que essas classes existem, sem a necessidade de incluir
// seus cabeçalhos completos. Isso acelera a compilação e evita dependências circulares.
class Patient;
class HealthProfessional;

// Declaração da classe HospitalWing, que representa uma ala do hospital.
// Ela herda de QObject para se integrar ao sistema de meta-objetos do Qt.
class HospitalWing : public QObject {
    // Macro obrigatório para qualquer classe que utilize sinais, slots ou o sistema de propriedades do Qt.
    Q_OBJECT

public: // Início da seção de membros públicos da classe.
    // Construtor da classe.
    // Recebe o nome da ala, um ponteiro para o profissional responsável, a capacidade e um ponteiro opcional para o objeto "pai".
    HospitalWing(const QString& name, HealthProfessional* responsible, int capacity, QObject *parent = nullptr);

    // Destrutor da classe, chamado quando um objeto HospitalWing é destruído.
    ~HospitalWing();

    // Método para adicionar um novo paciente (através de um ponteiro) à lista de pacientes da ala.
    void addPatient(Patient* patient);

    // Método "getter" que retorna o nome da ala.
    // 'const' indica que este método não modifica o estado do objeto.
    QString getName() const;

    // Método "getter" que retorna a lista de pacientes.
    // Retorna uma referência constante (&) para evitar a cópia desnecessária e custosa da lista inteira.
    const QList<Patient*>& getPatients() const;

private: // Início da seção de membros privados da classe.
    // Atributos (variáveis de membro) que armazenam o estado de um objeto HospitalWing.
    QString m_name;                     // Armazena o nome da ala.
    HealthProfessional* m_responsible;  // Ponteiro para o profissional de saúde responsável.
    int m_capacity;                     // Capacidade máxima de pacientes da ala.
    QList<Patient*> m_patients;         // Lista de ponteiros para os pacientes atualmente na ala.
};

#endif // Fim da diretiva de pré-processador.
