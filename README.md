### 1. Descrição Geral

Este projeto foi desenvolvido como parte da disciplina Estrutura de Dados, e tem como objetivo implementar um sistema de gerenciamento de partidas e classificação de um campeonato de futebol utilizando a linguagem C. Nesta primeira parte, o sistema realiza operações de leitura, consulta e exibição de dados baseadas em arquivos .csv.
Todas as informações de times e partidas são carregadas para a memória principal e manipuladas através de TADs (Tipos Abstratos de Dados), com foco na organização, modularização e clareza de código.




## 2. Funcionalidades Implementadas

O sistema oferece três funcionalidades principais:

# 2.1 Consultar time:
Exibe todos os times cadastrados, permite ao usuário selecionar um ID e visualizar o desempenho completo do time escolhido.

# 2.2 Consultar partidas:
Lista os times disponíveis, solicita o ID de um time e mostra todas as partidas que ele disputou (ou informa caso não haja partidas registradas)

# 2.3 Imprimir tabela de classificação:
Exibe a tabela completa de classificação do campeonato, com colunas alinhadas mostrando vitórias, empates, derrotas, gols marcados, sofridos, saldo e pontuação.




## 3. Estrutura do Repositório
```
TP-ED-2025-2/
│
├── main.c                         # Função principal e menu do sistema
│
├── time.c / time.h                # TAD Time
├── bd_times.c / bd_times.h        # TAD BDTimes (gerencia todos os times)
│
├── partida.c / partida.h          # TAD Partida
├── bd_partidas.c / bd_partidas.h  # TAD BDPartidas (gerencia todas as partidas)
│
├── times.csv                      # Banco de dados de times
├── partidas.csv                   # Banco de dados de partidas
│
└── README.md                      # Documentação do projeto

```




Cada módulo possui responsabilidade própria, garantindo clareza e separação entre lógica de dados e lógica de controle.




## 4. Estrutura dos Arquivos CSV

# 4.1 bd_times.csv
```
Contém os times participantes do campeonato.
ID,Nome
0,JAVAlis
1,ESCorpioes
...
```
# 4.2 bd_partidas.csv
```
Contém as partidas realizadas, associando os times por ID.
ID,Time1,Time2,GolsTime1,GolsTime2
0,0,1,2,0
1,0,2,3,1
...
```



## 5. TADs Utilizados

-  Time:  
Representa um time individual e suas estatísticas.

-  BD_Times:  
Estrutura que armazena todos os times carregados do CSV.

-  Partida:  
Armazena informações de uma partida entre dois times.

-  BD_Partida:  
Conjunto de partidas registradas no campeonato.	Partida partidas[200], quantidade. Funções: carregar_partidas, atualizar_estatisticas, consultar_partidas.




## 6. Decisões de Implementação

- Modularização rigorosa: cada TAD possui .h e .c, conforme boas práticas de organização.

- Vetores estáticos: usados para armazenar times e partidas, simplificando a manipulação de dados sem alocação dinâmica.

- Separação de responsabilidades: main.c atua apenas no fluxo de controle e interface; leitura e manipulação de dados ocorrem nos TADs.

- Formatação do output: tabelas impressas com espaçamento fixo (printf("%-15s %4d ...")) garantem alinhamento em terminais.

- Interface simplificada: o usuário escolhe o time pelo ID, evitando problemas com acentuação e espaços em nomes.
  
- Tratamento de erros: verificações de entrada inválida, IDs fora de faixa e mensagens claras quando não há dados disponíveis.




## 7. Instruções de Execução

# 7.1 Requisitos

  1. Compilador GCC (versão 11+)

  2. Utilitário make (GNU Make)

# 7.2 Passo a passo

  1. Acesse a pasta do projeto no terminal:

    cd /caminho/para/TP-ED-2025-2 (Exemplo)

  2. Compile e execute:  
    make



## 8. Considerações Finais

O projeto cumpre os requisitos da Parte I do Trabalho Prático de Estrutura de Dados, implementando corretamente as três funcionalidades obrigatórias, com código modularizado, comentado e executável.
