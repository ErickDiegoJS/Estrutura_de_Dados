#include "fila.h"

t_fila * ConstroiFila(int capacidade){
    t_fila * fila = (t_fila *) malloc(sizeof(t_fila));
    fila->capacidade = capacidade;
    fila->primeiro = 0;
    fila->ultimo = 0;
    fila->quantidade = 0;
    fila->dados = (int *) malloc(capacidade * sizeof(int));
    return fila;
}

int FilaCheia(t_fila * fila){
    return fila->capacidade == fila->quantidade;
}

int FilaVazia(t_fila * fila){
    return fila->quantidade == 0;
}

int Proxima(int pos, int capacidade) {
    return (pos+1) % capacidade;
}

int Enfileirar(t_fila * fila, int elemento){
    if(!FilaCheia(fila)){
        fila->dados[fila->ultimo] = elemento;
        fila->ultimo = Proxima(fila->ultimo, fila->capacidade);
        fila->quantidade++;
        return 1;
    } else{
        return 0;
    }
}

int Desenfileirar(t_fila * fila, int * elemento){
    if(!FilaVazia(fila)){
        * elemento = fila->dados[fila->primeiro];
        fila->primeiro = Proxima(fila->primeiro, fila->capacidade);
        fila->quantidade--;
        return 1;
    } else{
        return 0;
    }
}

void ExibirFila(t_fila * fila){
    if(!FilaVazia(fila)){
        int i = fila->primeiro;
        do{
            printf("%d ", fila->dados[i]);
            i = Proxima(i, fila->capacidade);
        } while (i != fila->ultimo);
        
    }
    else{
        printf("Fila esta vazia!\n");
    }
}

void ExibirVetor(t_fila * fila){
    if(FilaCheia(fila)){
        for(int i = 0; i<fila->capacidade; i++){
            printf(" %d", fila->dados[i]);
        }
    } else if(FilaVazia(fila)){
        for(int i = 0; i<fila->capacidade; i++){
            printf("_ ");
        }
    } else if(fila->primeiro < fila->ultimo){
        for(int i = 0; i<fila->primeiro; i++){
            printf("_ ");
        }
        for(int i=fila->primeiro; i<fila->ultimo; i++){
            printf("%d ", fila->dados[i]);
        }
        for(int i=fila->ultimo;i<fila->capacidade; i++){
            printf("_ ");
        }
    } else{
        for(int i = 0; i<fila->ultimo; i++){
            printf("_ ");
        }
        for(int i = fila->ultimo; i<fila->primeiro; i++){
            printf("%d ", fila->dados[i]);
        }
        for(int i = fila->primeiro;i<fila->capacidade; i++){
            printf("_ ");
        }
    }
}

void ParesImpares(t_fila *orig, t_fila *pares, t_fila *impares) {
    int aux;
    while (Desenfileirar(orig, &aux)) {
        if (aux % 2 == 0) {
            Enfileirar(pares, aux);
        } else {
            Enfileirar(impares, aux);
        }
    }
}

void TransferirFila(t_fila *f1, t_fila *f2) {
    int aux;
    if (f1->quantidade <= f2->quantidade) {
        int qtd = f1->quantidade;
        for (int i = 0; i < qtd; i++) {
            if (Desenfileirar(f1, &aux)) {
                Enfileirar(f2, aux);
            }
        }
    } else {
        int qtd = f2->quantidade;
        for (int i = 0; i < qtd; i++) {
            if (Desenfileirar(f2, &aux)) {
                Enfileirar(f1, aux);
            }
        }
    }
}

void DestruirFila(t_fila *fila) {
    if (fila != NULL) {
        if (fila->dados != NULL) {
            free(fila->dados);
        }
        free(fila);
    }
}