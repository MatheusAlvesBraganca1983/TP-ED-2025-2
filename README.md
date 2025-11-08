## 📘 1. Descrição Geral

Este projeto foi desenvolvido como parte da disciplina Estrutura de Dados, e tem como objetivo implementar um sistema de gerenciamento de partidas e classificação de um campeonato de futebol utilizando a linguagem C. Nesta primeira parte, o sistema realiza operações de leitura, consulta e exibição de dados baseadas em arquivos .csv.
Todas as informações de times e partidas são carregadas para a memória principal e manipuladas através de TADs (Tipos Abstratos de Dados), com foco na organização, modularização e clareza de código.




## ⚙️ 2. Funcionalidades Implementadas

O sistema oferece três funcionalidades principais:

### ⚙️ 2.1 Consultar time:
Exibe todos os times cadastrados, permite ao usuário selecionar um ID e visualizar o desempenho completo do time escolhido.

### ⚙️ 2.2 Consultar partidas:
Lista os times disponíveis, solicita o ID de um time e mostra todas as partidas que ele disputou (ou informa caso não haja partidas registradas)

### ⚙️ 2.3 Imprimir tabela de classificação:
Exibe a tabela completa de classificação do campeonato, com colunas alinhadas mostrando vitórias, empates, derrotas, gols marcados, sofridos, saldo e pontuação.




## 🧩 3. Estrutura do Repositório
TrabalhoED/
main.c                 # Função principal e menu do sistema
time.c / time.h        # TAD Time: representa e imprime estatísticas de cada time
partida.c / partida.h  # TAD Partida: representa os dados de uma partida
bd_times.c / bd_times.h         # TAD BD_Times: banco de dados de times
bd_partidas.c / bd_partidas.h   # TAD BD_Partidas: banco de dados de partidas
bd_times.csv           # Arquivo base de times
bd_partidas.csv        # Arquivo base de partidas
Makefile               # Script de compilação automatizada
README.md              # Documentação do projeto



Cada módulo possui responsabilidade própria, garantindo clareza e separação entre lógica de dados e lógica de controle.




## 🧱 4. Estrutura dos Arquivos CSV

### 🧱 4.1 bd_times.csv

Contém os times participantes do campeonato.
ID,Nome
0,JAVAlis
1,ESCorpioes
2,SemCTRL
3,GOrilas
...

### 🧱 4.2 bd_partidas.csv

Contém as partidas realizadas, associando os times por ID.

ID,Time1,Time2,GolsTime1,GolsTime2
0,0,1,2,0
1,0,2,3,1
2,2,3,2,2
...




## 🧮 5. TADs Utilizados

### 🧮 5.1 Time	
Representa um time individual e suas estatísticas.

### 🧮 5.2 BD_Times	
Estrutura que armazena todos os times carregados do CSV.

### 🧮 5.3 Partida	
Armazena informações de uma partida entre dois times.

### 🧮 5.4 BD_Partidas	
Conjunto de partidas registradas no campeonato.	Partida partidas[200], quantidade. Funções: carregar_partidas, atualizar_estatisticas, consultar_partidas.




## 🧠 6. Decisões de Implementação

### 🧠 6.1 Modularização rigorosa: cada TAD possui .h e .c, conforme boas práticas de organização.

### 🧠 6.2 Vetores estáticos: usados para armazenar até 200 times e partidas, simplificando a manipulação de dados sem alocação dinâmica.

### 🧠 6.3 Separação de responsabilidades: main.c atua apenas no fluxo de controle e interface; leitura e manipulação de dados ocorrem nos TADs.

### 🧠 6.4 Formatação do output: tabelas impressas com espaçamento fixo (printf("%-15s %4d ...")) garantem alinhamento em terminais.

### 🧠 6.5 Interface simplificada: o usuário escolhe o time pelo ID, evitando problemas com acentuação e espaços em nomes.

### 🧠 6.6 Tratamento de erros: verificações de entrada inválida, IDs fora de faixa e mensagens claras quando não há dados disponíveis.




## 🧾 7. Instruções de Execução

### 🔹 7.1 Requisitos

Compilador GCC (versão 11+)

Utilitário make (GNU Make)

### 🔹 7.2 Passo a passo

  Acesse a pasta do projeto:

  cd /caminho/para/TP-ED-2025-2

  Compile e execute:
    make



## 🏁 8. Considerações Finais

O projeto cumpre todos os requisitos da Parte I do Trabalho Prático de Estrutura de Dados, implementando corretamente as três funcionalidades obrigatórias, com código modularizado, comentado e executável em múltiplos sistemas operacionais.
A documentação está detalhada e estruturada para facilitar tanto a execução quanto a compreensão das decisões de projeto.
