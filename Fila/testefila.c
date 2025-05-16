#include "fila.h"

int main(){
    t_fila * fila;
    int * intPont = ( int *) malloc(sizeof(int));
    fila = ConstroiFila(5);
    printf("Fila construida\n");
    ExibirFila(fila);

    if (Enfileirar(fila, 10))
        printf("insercao realizada com sucesso\n");
    else
        printf("Falha na insercao, fila cheia\n");
    
    if (Enfileirar(fila, 20))
        printf("insercao realizada com sucesso\n");
    else
        printf("Falha na insercao, fila cheia\n");
    printf("10 e 20 enfilairados\n");
    ExibirFila(fila);
    
    if (Desenfileirar(fila, intPont))
        printf("%d saiu da fila\n", intPont);
    else
        printf("falha no desenfileiramento\n");

    ExibirFila(fila);
    if (Enfileirar(fila, 30))
        printf("insercao realizada com sucesso\n");
    else
        printf("Falha na insercao, fila cheia\n");
    
    if (Enfileirar(fila, 40))
        printf("insercao realizada com sucesso\n");
    else
        printf("Falha na insercao, fila cheia\n");

    printf("30 e 40 enfileirados\n");
    ExibirFila(fila);
    return 0;
}