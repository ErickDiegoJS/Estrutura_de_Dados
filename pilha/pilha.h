#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *dados;
    int topo;
    int capaciade;
}t_pilha;

void ConstroiPilha(int capacidade, t_pilha *p);
int Push(int i, t_pilha *p);
int Pop(t_pilha *p, int *removido);
int PilhaVazia(t_pilha *p);
int PilhaCheia(t_pilha *p);
void ExibePliha(t_pilha *p);
void InverterPilha(t_pilha *p);