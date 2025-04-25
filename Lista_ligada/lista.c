#include "lista.h"

void ConstroiLista(t_lista *lista){
    // atribui a primeiro e a ultimo como NULL
    //o ultimo recebe NULL e o primeiro recebe o ultimo
    lista->primeiro = lista->ultimo = NULL;

}

int ListaVazia(t_lista *lista){
    // se o primeiro já é NULL, logo a negação de primeiro é true ou 1
    // return lista->primeiro == NULL;
    return !lista->primeiro;
}
void InsereInicio(int i, t_lista *lista){
    t_no * novo = ConstroiNo(i);
    if(ListaVazia(lista)){
        lista->ultimo = novo;
    }
    else{
        novo->prox = lista->primeiro;
    }
    lista->primeiro = novo;
}

int RemoveInicio(t_lista * lista){
    if(ListaVazia(lista)) return -1;
    int temp = lista->primeiro->info;
    t_no * aux = lista->primeiro;
    lista->primeiro = lista->primeiro->prox;
    if(lista->primeiro == NULL){// esvaziou a lista
        lista->ultimo = NULL;
    }
    free(aux);
    return temp;
}

void ExibirLista(t_lista * lista){
    if(ListaVazia(lista)){
        printf("Lista vazia!");
    }
    else{
        // t_no * runner = lista->primeiro;
        // while(runner != NULL){
        //     printf("[%d] -> ", runner->info);
        //     runner = runner->prox;
        // }

        for(t_no * runner = lista->primeiro; runner != NULL; runner = runner->prox){
            printf("[%d] -> ", runner->info);
        }
        printf("\\\\\n");
    }
}

void InsereFim(int i, t_lista * lista){
    t_no * novo = ConstroiNo(i);
    if(ListaVazia(lista)){
        lista->primeiro = novo;
    }
    else{
        lista->ultimo->prox = novo;
    }
    lista->ultimo = novo;
}

int RemoveFim(t_lista * lista){
    //cenario 1: lista vazia
    if(ListaVazia(lista)){
        return -1;
    }
    int temp;
    //cenario 2: lista tem um elemento só
    if(lista->primeiro == lista->ultimo){
        temp = lista->primeiro->info;
        free(lista->primeiro);
        lista->primeiro = lista->ultimo = NULL;
    }
    else{
        //cenario 3: lista com varios elementos
        t_no * runner = lista->primeiro;
        while(runner->prox != lista->ultimo){// encontra o penultimo
            runner = runner->prox;
        }
        temp = lista->ultimo->info;
        free(lista->ultimo);
        runner->prox = NULL;
        lista->ultimo = runner;
    }
    return temp;
}