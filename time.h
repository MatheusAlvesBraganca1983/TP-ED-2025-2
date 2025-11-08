#ifndef TIME_H
#define TIME_H

typedef struct {
    int id;
    char nome[50];
    int vitorias;
    int empates;
    int derrotas;
    int gols_marcados;
    int gols_sofridos;
} Time;

void inicializar_time(Time *t, int id, char *nome);
int calcular_pontos(Time *t);
int calcular_saldo(Time *t);
void imprimir_time(Time *t);

#endif