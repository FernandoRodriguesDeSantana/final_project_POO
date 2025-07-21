// Diretivas de pré-processador (header guards) para garantir que este arquivo
// seja incluído apenas uma vez durante a compilação, evitando erros de redefinição.
#ifndef MONITORINGSYSTEM_H
#define MONITORINGSYSTEM_H

// Inclusão de cabeçalhos do framework Qt.
#include <QObject> // Classe base para todos os objetos Qt, necessária para o sistema de sinais e slots.
#include <QList>   // Classe de contêiner do Qt, usada para criar listas dinâmicas.

// Inclusão de cabeçalhos de outras classes do projeto que são usadas por MonitoringSystem.
#include "hospitalwing.h"
#include "healthprofessional.h"

// Declaração da classe MonitoringSystem.
// Ela herda de QObject, o que a torna um objeto Qt.
class MonitoringSystem : public QObject
{
    // Macro obrigatório para qualquer classe que utilize o sistema de meta-objetos do Qt
    // (sinais, slots, propriedades, etc.).
    Q_OBJECT

public: // Início da seção de membros públicos, acessíveis de fora da classe.
    // Construtor explícito para evitar conversões implícitas.
    // Recebe um ponteiro opcional para um objeto "pai", usado pelo sistema de memória do Qt.
    explicit MonitoringSystem(QObject *parent = nullptr);

    // Destrutor, chamado quando o objeto é destruído para liberar recursos.
    ~MonitoringSystem();

    // Métodos públicos que definem a interface da classe (o que ela pode fazer).
    void addWing(HospitalWing* wing);                   // Adiciona uma ala ao sistema.
    void addUser(HealthProfessional* user);             // Adiciona um profissional de saúde (usuário) ao sistema.

    bool login(const QString& id, const QString& password); // Valida as credenciais de login.
    HospitalWing* findWingByName(const QString& name);      // Procura uma ala pelo nome.
    const QList<HospitalWing*>& getWings() const;           // Retorna uma referência constante para a lista de alas.
    void setupInitialData();                            // Popula o sistema com dados de teste iniciais.

private: // Início da seção de membros privados, acessíveis apenas de dentro da classe.
    // Atributos (variáveis de membro) que armazenam o estado do sistema.

    // O sistema é "dono" das alas e dos usuários. Quando o sistema for destruído,
    // ele será responsável por deletar esses objetos.
    QList<HospitalWing*> m_wings;       // Lista de ponteiros para todas as alas do hospital.
    QList<HealthProfessional*> m_users; // Lista de ponteiros para todos os usuários do sistema.

    // Armazena o usuário que está atualmente logado no sistema.
    HealthProfessional* m_authenticatedUser;
};

#endif // MONITORINGSYSTEM_H
