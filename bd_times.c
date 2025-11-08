#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bd_times.h"

void carregar_times(BD_Times *bd) {
    FILE *f = fopen("bd_times.csv", "r");
    if (!f) {
        printf("Erro ao abrir bd_times.csv\n");
        exit(1);
    }
    char linha[100];
    bd->quantidade = 0;
    fgets(linha, 100, f);
    while (fgets(linha, 100, f)) {
        int id;
        char nome[50];
        sscanf(linha, "%d,%49[^\n]", &id, nome);
        inicializar_time(&bd->times[bd->quantidade], id, nome);
        bd->quantidade++;
    }
    fclose(f);
}

int buscar_time_por_prefixo(BD_Times *bd, const char *prefixo, int *indices) {
    int count = 0;
    for (int i = 0; i < bd->quantidade; i++) {
        if (strncmp(bd->times[i].nome, prefixo, strlen(prefixo)) == 0) {
            indices[count++] = i;
        }
    }
    return count;
}

void imprimir_tabela_classificacao(BD_Times *bd) {
    printf("ID Nome          V E D GM GS S PG\n");
    for (int i = 0; i < bd->quantidade; i++) {
        imprimir_time(&bd->times[i]);
    }
}