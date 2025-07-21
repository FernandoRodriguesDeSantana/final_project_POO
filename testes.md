# Testes

>[!NOTE]
> Relatar o processo de testes do sistema, especificando quais testes foram realizados e os resultados obtidos.

<div align="center">

## Processo de Testes

Os testes do sistema foram realizados de forma **manual e funcional**, focando em validar os principais casos de uso e os requisitos funcionais do projeto. Cada funcionalidade principal foi verificada para garantir que o comportamento da aplicação correspondesse ao esperado.

### Casos de Teste Realizados

| Caso de Teste | Passos para Reprodução | Resultado Esperado | Resultado Obtido | Status |
| :--- | :--- | :--- | :--- | :--- |
| **1. Autenticação de Usuário (Válido)** | 1. Executar a aplicação.\<br\>2. Inserir um ID (`111`) e senha (`senha123`) válidos.\<br\>3. Clicar em "OK". | A janela de login deve fechar e a `MainWindow` (painel de monitoramento) deve ser exibida. | Conforme esperado. A lógica em `logindialog.cpp` valida as credenciais com o `MonitoringSystem` e abre a janela principal. | ✅ Aprovado |
| **2. Autenticação de Usuário (Inválido)** | 1. Executar a aplicação.\<br\>2. Inserir um ID ou senha inválidos (ex: `999`, `errado`).\<br\>3. Clicar em "OK". | Uma mensagem de erro deve ser exibida no diálogo de login. A janela de login deve permanecer aberta para uma nova tentativa. | Conforme esperado. A lógica de controle no `logindialog.cpp` impede que o diálogo seja "aceito" em caso de falha na autenticação. | ✅ Aprovado |
| **3. Visualização Inicial de Pacientes** | 1. Realizar um login bem-sucedido. | O painel de monitoramento deve exibir os pacientes que foram pré-carregados pelo método `setupInitialData` do `MonitoringSystem`. | Conforme esperado. O método `setupMonitoringPanel` na `MainWindow` constrói a UI com os dados iniciais. | ✅ Aprovado |
| **4. Simulação em Tempo Real** | 1. Após o login, observar os painéis dos pacientes. | Os sinais vitais em cada `PatientMonitorWidget` devem ser atualizados a cada 5 segundos. Os valores devem variar de forma suave e linear, não de forma abrupta. | Conforme esperado. O `QTimer` em `MainWindow` dispara `simulateHospitalTick`, que chama `generateAndUpdateVitalSign` de cada paciente. | ✅ Aprovado |
| **5. Registro Dinâmico de Novo Paciente** | 1. Clicar no botão "Registrar Novo Paciente".\<br\>2. Preencher o formulário no `NewPatientDialog` com dados válidos e clicar em "OK". | Um novo painel de `PatientMonitorWidget` deve aparecer instantaneamente na tela, e seus primeiros sinais vitais devem ser exibidos imediatamente. | Conforme esperado. O slot `on_buttonNewPatient_clicked` adiciona o widget ao layout e chama `generateAndUpdateVitalSign` uma vez. | ✅ Aprovado |
| **6. Validação de Formulário de Registro** | 1. Clicar em "Registrar Novo Paciente".\<br\>2. Deixar o campo de nome em branco e clicar em "OK". | O diálogo deve fechar, mas nenhum novo paciente deve ser adicionado à interface, conforme a lógica de validação. | Conforme esperado. O código verifica se o nome está vazio antes de prosseguir com a criação do paciente. | ✅ Aprovado |

### Conclusão dos Testes

Todos os casos de teste funcionais para os requisitos principais da aplicação foram executados com sucesso. O sistema está se comportando conforme o esperado, com a autenticação de usuário funcionando corretamente, a simulação de dados ocorrendo em tempo real e a interface sendo atualizada de forma dinâmica e robusta. A aplicação é considerada **estável** para o escopo definido.

[Retroceder](implementacao.md) | [Início](README.md)

</div>
