#ifndef BD_PARTIDAS_H
#define BD_PARTIDAS_H
#include "partida.h"
#include "bd_times.h"

typedef struct {
    Partida partidas[200];
    int quantidade;
} BD_Partidas;

void carregar_partidas(BD_Partidas *bd);
void atualizar_estatisticas(BD_Times *bd_times, BD_Partidas *bd_partidas);
void consultar_partidas(BD_Partidas *bd_partidas, BD_Times *bd_times);

#endif