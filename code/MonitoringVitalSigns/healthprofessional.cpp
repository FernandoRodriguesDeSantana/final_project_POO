// Inclui o arquivo de cabeçalho correspondente, que contém a declaração da classe HealthProfessional.
#include "HealthProfessional.h"

// Implementação do construtor da classe HealthProfessional.
// A sintaxe ': Person(...)' é a lista de inicializadores.
// Ela primeiro chama o construtor da classe base (Person) para inicializar os atributos herdados.
// Em seguida, inicializa os atributos próprios desta classe (m_id, m_jobPosition, m_password).
HealthProfessional::HealthProfessional(const QString& name, int age, char sex, const QString& id, const QString& jobPosition, const QString& password, QObject *parent)
    : Person(name, age, sex, parent), m_id(id), m_jobPosition(jobPosition), m_password(password) {}

// Implementação dos métodos "Getters".
// Retorna o valor do atributo correspondente.
QString HealthProfessional::getId() const { return m_id; }
QString HealthProfessional::getJobPosition() const { return m_jobPosition; }

// Implementação dos métodos "Setters".
// Atribui um novo valor ao atributo correspondente.
void HealthProfessional::setId(const QString& id) { this->m_id = id; }
void HealthProfessional::setJobPosition(const QString & jobPosition) { this->m_jobPosition = jobPosition; }

// Implementação do método de verificação de senha.
// Compara a senha armazenada (m_password) com a senha fornecida como argumento.
// Retorna 'true' se forem iguais, e 'false' caso contrário.
bool HealthProfessional::checkPassword(const QString& password) const {
    return m_password == password;
}
