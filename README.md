"# Estrutura_de_Dados" 
pilha. h:
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


pilha.c:
#include "pilha.h"

void ConstroiPilha(int capacidade, t_pilha *p){
    p->dados =  (int *) malloc(capacidade * sizeof);
    p->topo = 0;
    p ->capaciade = capacidade;
}
int PilhaVazia(t_pilha *p){
    return !p->topo;//retorna o resultado da operacao, ou seja, verdadeiroou falso, 1 ou 0
}
int PilhaCheia(t_pilha *p){
    return p->capaciade == p->topo;
}
int Push(int i, t_pilha *p){
    if(!PilhaCheia(p)){
        //nao é utilizado *p pois a pilha cheia ja espera um ponteiro,
        // caso seja utilizado estaria havendo uma dereferenciacao, 
        //ou seja, estaria sendo passado a pilha, nao sua referencia(endereco).
        p->dados[topo++] = i;//aqui e usadoo o pos-inclemento, apenas apos a atribuicao de valor pelo = que e feito inclemento
        return 1;
    }
    return 0;
}
int Pop(t_pilha *p, int *removido){
    if(PilhaVazia(p)) return 0;
    *removido = p->dados[p->--topo];//e utilizado o * para afetar diretamente conteudo do removido, um ponteiroda pilha.
    //alem disso, o topo e inclementado antes da operacao
    return 1;
}
void ExibePliha(t_pilha *p){

}
