#include "no.h"
#include <stdio.h>

typedef struct {
    t_no * primeiro;
    t_no * ultimo;
}t_lista;

void ConstroiLista(t_lista *);
int ListaVazia(t_lista *);
void InsereInicio(int, t_lista *);
int RemoveInicio(t_lista *);
void ExibirLista(t_lista *);
void InsereFim(int, t_lista *);
int RemoveFim(t_lista *);
// atividade funções de lista
int QtdElementos(t_lista *);
void ExibirElemento(t_no *);
int MaiorElemento(t_lista *);
int EncontrarElemento(t_lista *, int);
int ContarElemento(t_lista *, int);
t_lista PosicoesElemento(t_lista *, int);
