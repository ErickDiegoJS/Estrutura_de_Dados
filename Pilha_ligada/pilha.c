#include "pilha.h"

void ConstroiPilha(t_pilha *pilha){
    pilha->topo = NULL;

}

int PilhaVazia(t_pilha *pilha){
    return !pilha->topo;
}
void Push(int i, t_pilha *pilha){
    t_no * novo = ConstroiNo(i);
    if(!PilhaVazia(pilha)){
        novo->prox = pilha->topo;
    }
    pilha->topo = novo;
}

int Pop(t_pilha * pilha, int * temp){
    if(PilhaVazia(pilha)) return 0;
    *temp = pilha->topo->info;
    t_no * aux = pilha->topo;
    pilha->topo = pilha->topo->prox;
    free(aux);
    return 1;
}

void ExibirPilha(t_pilha * pilha){
    if(PilhaVazia(pilha)){
        printf("pilha vazia!");
    }
    else{
        for(t_no * runner = pilha->topo; runner != NULL; runner = runner->prox){
            printf("[%d] -> ", runner->info);
        }
        printf("\\\\\n");
    }
}