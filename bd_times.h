#ifndef BD_TIMES_H
#define BD_TIMES_H

#include "time.h"

typedef struct {
    Time times[20];
    int quantidade;
} BD_Times;

void carregar_times(BD_Times *bd);
int buscar_time_por_prefixo(BD_Times *bd, const char *prefixo, int *indices);
void imprimir_tabela_classificacao(BD_Times *bd);

#endif