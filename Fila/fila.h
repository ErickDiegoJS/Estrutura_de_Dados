#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int * dados;
    int primeiro, ultimo, quantidade, capacidade;
} t_fila;

t_fila * ConstroiFila(int);
int FilaCheia(t_fila *);
int FilaVazia(t_fila *);
int Enfileirar(t_fila *, int);
int Desenfileirar(t_fila *, int *);
void ExibirFila(t_fila *);
void ExibirVetor(t_fila * fila);