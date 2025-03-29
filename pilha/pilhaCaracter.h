#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *dados;
    int topo;
    int capacidade;
}t_pilha_caracter;

void ConstroiPilha(int capacidade, t_pilha_caracter *p);
int Push(char i, t_pilha_caracter *p);
int Pop(t_pilha_caracter *p, char *removido);
int PilhaVazia(t_pilha_caracter *p);
int PilhaCheia(t_pilha_caracter *p);
void ExibePliha(t_pilha_caracter *p);
void InverterPilha(t_pilha_caracter *p);