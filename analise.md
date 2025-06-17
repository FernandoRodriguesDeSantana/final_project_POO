# Análise orientada a objeto
> [!NOTE]
> A **análise** orientada a objeto consiste na descrição do problema a ser tratado, duas primeiras etapas da tabela abaixo, a definição de casos de uso e a definição do domínio do problema.

## Descrição Geral do domínio do problema

Em ambientes hospitalares, o acompanhamento dos sinais vitais dos pacientes é essencial para a tomada de decisões clínicas eficazes. O processo tradicional, muitas vezes feito de forma manual ou com sistemas isolados, pode levar a atrasos, falhas de registro e dificuldade no acesso às informações em tempo real. Este projeto propõe um sistema digital integrado de monitoramento de pacientes, que permite que profissionais de saúde realizem cadastro de pacientes, atribuição de leitos, monitoramento individual ou por ala e visualização de sinais vitais de forma centralizada, rápida e segura.
O sistema tem como foco o apoio à rotina hospitalar, melhorando o controle e o acompanhamento clínico, com acesso autenticado e visualização intuitiva.

## Requisitos Funcionais do Projeto

- Cadastrar pacientes
- Associar paciente a uma ala
- Atualizar informações de pacientes
- Monitorar sinais vitais de pacientes individualmente
- Monitorar sinais vitais de uma ala
- Gerar alertas em tempo real
- Autenticar profissional da saúde

## Diagrama de Casos de Uso
O sistema de monitoramento de pacientes permite a interação principal dos profissionais da saúde (como médicos e enfermeiros), que acessam o sistema para realizar ações relacionadas aos pacientes e seus sinais vitais. Os casos de uso identificados são:

![image](https://github.com/user-attachments/assets/3d4666ce-8c84-4e48-9501-1b4a8dfd35a0)
 
## Diagrama de Domínio do problema
O sistema é modelado com base em conceitos da orientação a objetos. As principais classes são:

![image](https://github.com/user-attachments/assets/42984018-bd5b-4568-9cb0-1b583d46fdd2)

## Diagrama de Sequências
Esse diagrama mostra como o sistema recupera os sinais vitais dos pacientes de uma ala específica e apresenta essas informações ao profissional de saúde, destacando o fluxo de chamadas entre os objetos e a ordem temporal dessas interações.

![image](https://github.com/user-attachments/assets/3581568f-8e86-45ba-abe1-e5ae30b09435)

<div align="center">

[Retroceder](README.md) | [Avançar](projeto.md)

</div>
