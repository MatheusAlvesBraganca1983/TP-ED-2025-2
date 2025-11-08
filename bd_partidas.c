#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bd_partidas.h"

void carregar_partidas(BD_Partidas *bd) {
    FILE *f = fopen("bd_partidas.csv", "r");
    if (!f) {
        printf("Erro ao abrir bd_partidas.csv\n");
        exit(1);
    }
    char linha[100];
    bd->quantidade = 0;
    fgets(linha, 100, f);
    while (fgets(linha, 100, f)) {
        sscanf(linha, "%d,%d,%d,%d,%d",
               &bd->partidas[bd->quantidade].id,
               &bd->partidas[bd->quantidade].id_time1,
               &bd->partidas[bd->quantidade].id_time2,
               &bd->partidas[bd->quantidade].gols_time1,
               &bd->partidas[bd->quantidade].gols_time2);
        bd->quantidade++;
    }
    fclose(f);
}

void atualizar_estatisticas(BD_Times *bd_times, BD_Partidas *bd_partidas) {
    for (int i = 0; i < bd_partidas->quantidade; i++) {
        Partida *p = &bd_partidas->partidas[i];
        Time *t1 = &bd_times->times[p->id_time1];
        Time *t2 = &bd_times->times[p->id_time2];

        t1->gols_marcados += p->gols_time1;
        t1->gols_sofridos += p->gols_time2;
        t2->gols_marcados += p->gols_time2;
        t2->gols_sofridos += p->gols_time1;

        if (p->gols_time1 > p->gols_time2) {
            t1->vitorias++;
            t2->derrotas++;
        } else if (p->gols_time2 > p->gols_time1) {
            t2->vitorias++;
            t1->derrotas++;
        } else {
            t1->empates++;
            t2->empates++;
        }
    }
}

void consultar_partidas(BD_Partidas *bd_partidas, BD_Times *bd_times) {
    int id;
    printf("\n---------------------------------------------\n");
    printf("Lista de times:\n");
    printf("---------------------------------------------\n");
    for (int i = 0; i < bd_times->quantidade; i++) {
        printf("%d - %s\n", bd_times->times[i].id, bd_times->times[i].nome);
    }
    printf("---------------------------------------------\n");
    printf("Digite o numero (ID) do time desejado: ");
    if (scanf("%d", &id) != 1) {

        int c; while ((c = getchar()) != '\n' && c != EOF);
        printf("\nEntrada invalida.\n");
        return;
    }

    if (id < 0 || id >= bd_times->quantidade) {
        printf("\nID invalido.\n");
        return;
    }

    int encontrou = 0;
    printf("\n--------------------------------------------------------------\n\n");
    printf("Partidas de %s (ID %d)\n", bd_times->times[id].nome, id);
    printf("--------------------------------------------------------------\n");
    printf("ID  Mandante     Visitante     Placar\n");
    printf("--------------------------------------------------------------\n");

    for (int i = 0; i < bd_partidas->quantidade; i++) {
        Partida *p = &bd_partidas->partidas[i];
        if (p->id_time1 == id || p->id_time2 == id) {
            encontrou = 1;
            Time *t1 = &bd_times->times[p->id_time1];
            Time *t2 = &bd_times->times[p->id_time2];
            printf("%-3d %-12s %-12s %2d x %d\n",
                   p->id, t1->nome, t2->nome, p->gols_time1, p->gols_time2);
        }
    }

    if (!encontrou) {
        printf("Nenhuma partida encontrada para esse time.\n");
    }
    printf("--------------------------------------------------------------\n");
}