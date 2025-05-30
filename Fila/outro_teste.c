#include <time.h>
#include "fila.h"

int main(){
    t_fila *fila = ConstroiFila(15);
    for(int i = 1; i <= 15; i++) {
        Enfileirar(fila, i);
    }
    ExibirFila(fila);
    printf("\n");

    t_fila *pares = ConstroiFila(15);
    t_fila *impares = ConstroiFila(15);

    ParesImpares(fila, pares, impares);
    ExibirFila(pares);
    printf("\n");
    ExibirFila(impares);
    printf("\n");

    TransferirFila(pares, impares);
    ExibirFila(impares);
    printf("\n");

    DestruirFila(fila);
    DestruirFila(pares);
    DestruirFila(impares);

    return 0;
}