// Diretivas de pré-processador (header guards) que impedem a inclusão múltipla
// deste arquivo, evitando erros de compilação.
#ifndef PERSON_H
#define PERSON_H

// Inclusão de cabeçalhos de classes do framework Qt.
#include <QObject> // Inclui a classe base QObject, essencial para o sistema de Sinais e Slots.
#include <QString> // Inclui a classe de string do Qt.

// Declaração da classe Person, que serve como uma classe base para outras classes
// mais específicas, como Patient e HealthProfessional.
class Person : public QObject {
    // Macro obrigatório para qualquer classe que utilize o sistema de meta-objetos do Qt.
    Q_OBJECT

public: // Início da seção de membros públicos.
    // Construtor da classe. É usado para criar e inicializar um objeto Person.
    // Recebe nome, idade, sexo e um ponteiro opcional para um objeto "pai" para gerenciamento de memória.
    Person(const QString& name, int age, char sex, QObject *parent = nullptr);

    // Métodos "Getters" para acessar os dados do objeto de forma segura.
    // 'const' no final garante que esses métodos não modificam o estado do objeto.
    QString getName() const; // Retorna o nome da pessoa.
    int getAge() const;      // Retorna a idade da pessoa.
    char getSex() const;     // Retorna o sexo da pessoa.

protected: // Início da seção de membros protegidos.
    // Atributos declarados como 'protected' são privados, mas podem ser acessados
    // diretamente por classes que herdam de Person (como Patient e HealthProfessional).
    QString m_name; // Armazena o nome da pessoa.
    int m_age;      // Armazena a idade da pessoa.
    char m_sex;     // Armazena o sexo da pessoa.
};

#endif // PERSON_H
