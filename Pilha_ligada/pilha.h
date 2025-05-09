#include "no.h"
#include <stdio.h>

typedef struct {
    t_no * topo;
}t_pilha;

void ConstroiPilha(t_pilha *);
int PilhaVazia(t_pilha *);
void Push(int, t_pilha *);
int Pop(t_pilha *, int *);
void ExibirPilha(t_pilha *);