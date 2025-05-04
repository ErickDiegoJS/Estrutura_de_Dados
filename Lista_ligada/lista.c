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

// atividade funções de lista
int QtdElementos(t_lista * lista){
    int cont = 0;
    if(!ListaVazia(lista)){
        for(t_no * runner = lista->primeiro; runner != NULL; runner = runner->prox){
            cont++;
        }
    }
    return cont;
}

int MaiorElemento(t_lista * lista){
    if(ListaVazia(lista)){
        return -1;
    }
    else if(lista->primeiro == lista->ultimo){
        return lista->primeiro->info;
    }
    else{
        int maior = 0;
        for(t_no * runner = lista->primeiro; runner != NULL; runner = runner->prox){
            if (maior < runner->info){
                maior = runner->info;
            }
        }
        return maior;
    }
}

int EncontrarElemento(t_lista * lista, int elemento){
    if(ListaVazia(lista)){
        return -1;
    }
    int cont =0;
    for(t_no * runner = lista->primeiro; runner != NULL; runner = runner->prox){
        cont++;
        if(elemento == runner->info){
            return cont;
        }
    }
    return 0;
}

int ContarElemento(t_lista * lista, int elemento){
    if(ListaVazia(lista)){
        return 0;
    }
    int cont = 0;
    for(t_no * runner = lista->primeiro; runner != NULL; runner = runner->prox){
        if(runner->info == elemento){
            cont++;
        }
    }
    return cont;
}

t_lista PosicoesElemento(t_lista * lista, int elemento){
    t_lista novaLista;
    ConstroiLista(&novaLista);
    int cont = 0;
    for(t_no * runner = lista->primeiro; runner != NULL; runner = runner->prox){
        cont++;
        if(runner->info == elemento){
            InsereFim(cont, &novaLista);
        }
    }
    return novaLista;
}