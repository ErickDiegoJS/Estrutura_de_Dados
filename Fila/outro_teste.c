#include <time.h>
#include "fila.h"

int main(){
    t_fila *fila = ConstroiFila(8);
    int a;
    srand(time(0));
    do{
        if(rand() % 2){
            Enfileirar(fila ,rand() % 10);
        } else{
            Desenfileirar(fila, &a);
        }
        printf("\n");
        ExibirFila(fila);
        printf("\n");
        ExibirVetor(fila);

    }while(!FilaVazia(fila));

    return 0;
}