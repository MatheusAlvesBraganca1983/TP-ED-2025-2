#include <stdio.h>
#include "partida.h"

void inicializar_partida(Partida *p, int id, int id_time1, int id_time2, int gols_time1, int gols_time2) {
    p->id = id;
    p->id_time1 = id_time1;
    p->id_time2 = id_time2;
    p->gols_time1 = gols_time1;
    p->gols_time2 = gols_time2;
}

void imprimir_partida(Partida *p) {
    printf("ID: %d | Time1 ID: %d | Time2 ID: %d | Placar: %d x %d\n",
           p->id, p->id_time1, p->id_time2, p->gols_time1, p->gols_time2);
}