// Diretivas de pré-processador (header guards) para garantir que este arquivo
// seja incluído apenas uma vez durante a compilação, evitando erros de redefinição.
#ifndef HEALTHPROFESSIONAL_H
#define HEALTHPROFESSIONAL_H

// Inclusão de cabeçalhos de outras classes necessárias.
#include "Person.h"      // Inclui a definição da classe base 'Person'.
#include <QString>       // Inclui a classe de string do Qt.
#include <QObject>       // Inclui a classe base QObject, fundamental para o sistema do Qt.

// Declaração da classe HealthProfessional, que representa um profissional de saúde.
// A classe herda de 'Person', o que significa que um HealthProfessional é um tipo de Person
// e possui todos os seus atributos e métodos.
class HealthProfessional : public Person {
    // Macro obrigatório para qualquer classe que utilize o sistema de meta-objetos do Qt
    // (sinais, slots, propriedades, etc.).
    Q_OBJECT;

public: // Início da seção de membros públicos, que formam a interface da classe.
    // Construtor da classe. É chamado quando um novo objeto HealthProfessional é criado.
    // Recebe todos os dados necessários para inicializar o objeto e sua classe base.
    HealthProfessional(const QString& name, int age, char sex, const QString& id, const QString& jobPosition, const QString& password, QObject *parent = nullptr);

    // Métodos "Getters" - Funções para obter (ler) os valores dos atributos privados.
    // 'const' no final indica que o método não modifica o estado do objeto.
    QString getId() const;
    QString getJobPosition() const;
    bool checkPassword(const QString& password) const; // Verifica se a senha fornecida é correta.

    // Métodos "Setters" - Funções para modificar os valores dos atributos privados.
    void setId(const QString& id);
    void setJobPosition(const QString& jobPosition);

private: // Início da seção de membros privados, acessíveis apenas de dentro da classe.
    // Atributos (variáveis de membro) que armazenam o estado de um objeto HealthProfessional.
    QString m_id;          // Armazena o ID de identificação do profissional.
    QString m_jobPosition; // Armazena o cargo do profissional (ex: "Infectologista").
    QString m_password;    // Armazena a senha para autenticação no sistema.
};

#endif // HEALTHPROFESSIONAL_H
