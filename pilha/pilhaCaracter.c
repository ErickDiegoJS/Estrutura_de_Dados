#include "pilhaCaracter.h"

void ConstroiPilha(int capacidade, t_pilha_caracter *p){
    p->dados =  (char *) malloc(capacidade);
    p->topo = 0;
    p ->capacidade = capacidade;
}
int PilhaVazia(t_pilha_caracter *p){
    return !p->topo;//retorna o resultado da operacao, ou seja, verdadeiroou falso, 1 ou 0
}
int PilhaCheia(t_pilha_caracter *p){
    return p->capacidade == p->topo;
}
int Push(char i, t_pilha_caracter *p){
    if(!PilhaCheia(p)){
        //nao é utilizado *p pois a pilha cheia ja espera um ponteiro,
        // caso seja utilizado estaria havendo uma dereferenciacao, 
        //ou seja, estaria sendo passado a pilha, nao sua referencia(endereco).
        p->dados[p->topo++] = i;//aqui e usadoo o pos-inclemento, apenas apos a atribuicao de valor pelo = que e feito inclemento
        return 1;
    }
    return 0;
}
int Pop(t_pilha_caracter *p, char *removido){
    if(PilhaVazia(p)) return 0;
    *removido = p->dados[--p->topo];//e utilizado o * para afetar diretamente conteudo do removido, um ponteiroda pilha.
    //alem disso, o topo e inclementado antes da operacao
    return 1;
}
void ExibePliha(t_pilha_caracter *p){
    if(PilhaVazia(p)){
        printf("Pilha esta vazia\n");
    }
    else{
        for(int i= p-> topo-1; i>=0; i--){
        printf("%c\n", p->dados[i]);
        }
    }
}

void InverterPilha(t_pilha_caracter *p){
    t_pilha_caracter *invertida;
    invertida = (t_pilha_caracter *) malloc(sizeof(t_pilha_caracter));
    ConstroiPilha(p->capacidade, invertida);
    char aux;
    while(Pop(p, &aux)){
        Push(aux, invertida);
    }
    p->dados = invertida->dados;
    p->topo = invertida->topo;

}
void DestroiPilha(t_pilha_caracter *p){
    free(p->dados);
    p->topo = 0;
    p->capacidade = 0;
}