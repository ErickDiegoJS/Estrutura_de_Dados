#include "pilha.h"

void ConstroiPilha(int capacidade, t_pilha *p){
    p->dados =  (int *) malloc(capacidade * sizeof(t_pilha));
    p->topo = 0;
    p ->capaciade = capacidade;
}
void DestruirPilha(t_pilha *p){
    free(p->dados);
    free(p);
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
        p->dados[p->topo++] = i;//aqui e usadoo o pos-inclemento, apenas apos a atribuicao de valor pelo = que e feito inclemento
        return 1;
    }
    return 0;
}
int Pop(t_pilha *p, int *removido){
    if(PilhaVazia(p)) return 0;
    *removido = p->dados[--p->topo];//e utilizado o * para afetar diretamente conteudo do removido, um ponteiroda pilha.
    //alem disso, o topo e inclementado antes da operacao
    return 1;
}
void ExibePliha(t_pilha *p){
    if(PilhaVazia(p)){
        printf("Pilha esta vazia\n");
    }
    else{
        for(int i= p-> topo-1; i>=0; i--){
        printf("%d\n", p->dados[i]);
        }
    }
}

void InverterPilha(t_pilha *p) {
    t_pilha *invertida;
    invertida = (t_pilha *)malloc(sizeof(t_pilha));
    ConstroiPilha(p->capaciade, invertida);
    int aux;
    while (Pop(p, &aux)) {
        Push(aux, invertida);
    }
    free(p->dados); // Libera a memória antiga antes de substituir
    p->dados = invertida->dados;
    p->topo = invertida->topo;
    p->capaciade = invertida->capaciade;
    free(invertida); // Libera a estrutura auxiliar
}

