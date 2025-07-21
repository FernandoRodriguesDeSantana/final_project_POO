// Inclui o arquivo de cabeçalho correspondente, que contém a declaração da classe Person.
#include "Person.h"

// Implementação do construtor da classe Person.
// A lista de inicializadores (após os dois-pontos) é a maneira mais eficiente de inicializar os membros.
// - QObject(parent): Chama o construtor da classe base QObject, passando o ponteiro do objeto "pai".
// - m_name(name), m_age(age), m_sex(sex): Inicializa os atributos da classe com os valores recebidos.
Person::Person(const QString& name, int age, char sex, QObject *parent)
    : QObject(parent), m_name(name), m_age(age), m_sex(sex) {}

// Implementação do método "getter" para o nome.
// Retorna o valor do atributo privado m_name.
QString Person::getName() const { return m_name; }

// Implementação do método "getter" para a idade.
// Retorna o valor do atributo privado m_age.
int Person::getAge() const { return m_age; }

// Implementação do método "getter" para o sexo.
// Retorna o valor do atributo privado m_sex.
char Person::getSex() const { return m_sex; }
