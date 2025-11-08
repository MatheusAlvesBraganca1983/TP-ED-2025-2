#include <stdio.h>
#include <string.h>
#include "time.h"

void inicializar_time(Time *t, int id, char *nome) {
    t->id = id;
    strcpy(t->nome, nome);
    t->vitorias = t->empates = t->derrotas = 0;
    t->gols_marcados = t->gols_sofridos = 0;
}

int calcular_pontos(Time *t) {
    return (t->vitorias * 3) + t->empates;
}

int calcular_saldo(Time *t) {
    return t->gols_marcados - t->gols_sofridos;
}

void imprimir_time(Time *t) {
    printf("%-3d %-12s %2d %2d %2d %2d %3d %3d %3d\n",
           t->id,
           t->nome,
           t->vitorias,
           t->empates,
           t->derrotas,
           t->gols_marcados,
           t->gols_sofridos,
           calcular_saldo(t),
           calcular_pontos(t));
}