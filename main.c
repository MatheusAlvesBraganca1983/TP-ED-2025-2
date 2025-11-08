#include <stdio.h>
#include <stdlib.h>
#include "bd_times.h"
#include "bd_partidas.h"

void limpar_tela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main() {
    BD_Times bd_times;
    BD_Partidas bd_partidas;

    carregar_times(&bd_times);
    carregar_partidas(&bd_partidas);
    atualizar_estatisticas(&bd_times, &bd_partidas);

    char opcao;
    do {
        printf("\n=============================================\n");
        printf("  SISTEMA DE GERENCIAMENTO DE PARTIDAS\n");
        printf("=============================================\n");
        printf("1 - Consultar time\n");
        printf("2 - Consultar partidas\n");
        printf("6 - Imprimir tabela de classificacao\n");
        printf("Q - Sair\n");
        printf("---------------------------------------------\n");
        printf("Escolha uma opcao: ");
        scanf(" %c", &opcao);

        limpar_tela();

        switch (opcao) {
            case '1': {
                printf("\n---------------------------------------------\n");
                printf("Times disponiveis:\n");
                printf("---------------------------------------------\n");
                for (int i = 0; i < bd_times.quantidade; i++) {
                    printf("%d - %s\n", bd_times.times[i].id, bd_times.times[i].nome);
                }
                printf("---------------------------------------------\n");
                int id;
                printf("Digite o numero (ID) do time desejado: ");
                if (scanf("%d", &id) != 1) {
                    int c; while ((c = getchar()) != '\n' && c != EOF);
                    printf("\nEntrada invalida.\n");
                    break;
                }

                if (id < 0 || id >= bd_times.quantidade) {
                    printf("\nID invalido.\n");
                    break;
                }

                limpar_tela();

                printf("\n---------------------------------------------\n");
                printf("Desempenho do time: %s\n", bd_times.times[id].nome);
                printf("---------------------------------------------\n");
                printf("ID  Nome          V  E  D  GM  GS  SG  PG\n");
                printf("---------------------------------------------\n");
                imprimir_time(&bd_times.times[id]);
                printf("---------------------------------------------\n\n");
                printf("*GM = Gols Marcados\n");
                printf("*GS = Gols Sofridos\n");
                printf("*SG = Saldo de Gols\n");
                printf("*PG = Pontos Ganhos\n");
                break;
            }

            case '2':
                limpar_tela();
                consultar_partidas(&bd_partidas, &bd_times);
                break;

            case '6':
                printf("\n=== TABELA DE CLASSIFICACAO ===\n");
                printf("--------------------------------------------------------------\n");
                printf("ID  Nome          V  E  D  GM  GS  SG  PG\n");
                printf("--------------------------------------------------------------\n");
                for (int i = 0; i < bd_times.quantidade; i++) {
                    imprimir_time(&bd_times.times[i]);
                }
                printf("--------------------------------------------------------------\n\n");
                printf("*GM = Gols Marcados\n");
                printf("*GS = Gols Sofridos\n");
                printf("*SG = Saldo de Gols\n");
                printf("*PG = Pontos Ganhos\n");
                break;

            case 'Q':
            case 'q':
                printf("\nSaindo do sistema...\n");
                break;

            default:
                printf("\nOpcao invalida. Tente novamente.\n");
        }

    } while (opcao != 'Q' && opcao != 'q');

    return 0;
}