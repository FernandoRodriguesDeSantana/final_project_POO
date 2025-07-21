# Implementação

>[!NOTE] 
 Relatar o processo de implementação do problemas, incluindo as
 ferramentas e bibliotecas utilizadas
>
# Sistema de Monitoramento de Sinais Vitais

  

## Visão Geral

Este projeto é uma aplicação de desktop desenvolvida em C++ com o framework Qt, que simula um painel de monitoramento de sinais vitais em tempo real para um ambiente hospitalar. O sistema permite a autenticação de usuários (profissionais de saúde), visualização de múltiplos pacientes, registro dinâmico de novos pacientes e uma simulação realista de sinais vitais com atualização automática na interface.

## Funcionalidades Principais

  * **Autenticação de Usuário:** Acesso ao sistema protegido por uma tela de login que valida o ID e a senha do profissional de saúde.
  * **Monitoramento em Tempo Real:** Painel centralizado que exibe os dados de múltiplos pacientes simultaneamente.
  * **Simulação Realista:** Os sinais vitais não são puramente aleatórios; eles evoluem de forma linear a partir do último registro, criando uma simulação mais crível.
  * **Adição Dinâmica de Pacientes:** O profissional autenticado pode registrar novos pacientes através de um formulário, e o painel de monitoramento é atualizado instantaneamente para incluir o novo paciente.
  * **Interface Gráfica Intuitiva:** A interface foi construída com componentes do Qt Widgets, organizados em layouts para uma experiência de usuário clara e funcional.

## Ferramentas e Tecnologias

  * **IDE:** Qt Creator
  * **Linguagem:** C++
  * **Framework Principal:** Qt 6
  * **Módulos Qt:**
      * **`QtCore`**: Utilizado para a estrutura base de objetos (`QObject`), sistema de Sinais e Slots, `QTimer`, `QString`, e `QList`.
      * **`QtWidgets`**: Utilizado para todos os componentes da interface gráfica (`QMainWindow`, `QDialog`, `QPushButton`, `QLabel`, etc.).
  * **Ferramenta de Build:** qmake
  * **UI Designer:** Qt Designer

## Arquitetura e Modelagem de Dados

A aplicação segue uma arquitetura **Orientada a Objetos**, com uma clara separação entre a lógica de negócio (modelo) e a interface gráfica (visão).

As principais classes do sistema são:

  * **`MonitoringSystem`**: A classe central que atua como o "backend", gerenciando todos os dados da aplicação.
  * **`MainWindow`**: A janela principal que orquestra a interface e a simulação.
  * **`Patient`**: Modela um paciente e contém a lógica de simulação de seus próprios sinais vitais.
  * **`HealthProfessional`**: Modela um usuário do sistema, com credenciais para autenticação.
  * **`HospitalWing`**: Agrupa um conjunto de pacientes sob a responsabilidade de um profissional.
  * **`PatientMonitorWidget`**: Componente de UI reutilizável que exibe os dados de um único paciente.
  * **`LoginDialog`** e **`NewPatientDialog`**: Diálogos modais para as funcionalidades de login e registro, respectivamente.

Uma decisão de design crucial foi o uso de **ponteiros** (ex: `QList<Patient*>`) para gerenciar as relações entre os objetos. Isso garante a existência de uma única instância para cada paciente, evitando problemas de inconsistência de dados e melhorando a eficiência do sistema.

## Como Executar

1.  **Pré-requisitos:**

      * Ter o Qt 6 e o Qt Creator instalados.
      * Um compilador C++ (MinGW ou MSVC, geralmente incluído com o Qt).

2.  **Passos:**

      * Clone ou baixe este repositório.
      * Abra o arquivo de projeto (`.pro`) no Qt Creator.
      * O Qt Creator pedirá para configurar o projeto. Selecione um "Kit" compatível (ex: Desktop Qt 6.x MinGW 64-bit).
      * No menu, vá em **Build \> Run qmake**.
      * Compile e execute o projeto clicando no botão de "Play" verde ou pressionando `Ctrl+R`.

3.  **Credenciais de Teste:**

      * **Usuário:** `111`
      * **Senha:** `senha123`

<div align="center">

[Retroceder](projeto.md) | [Início](analise.md)

</div>
