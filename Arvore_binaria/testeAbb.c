#include "abb.h"
#include <time.h>

int main (){
    t_abb abb;
    IniciaAroreBinaria(&abb);
    srand(time(0));
    // if(ArvoreVazia(&abb))
    //     printf("Arvore inicializada esta vazia!");
    // else
    //     printf("Arvoreinicializadanao esta vazia.");
    for(int i=1; i<=12; i++){
        int n = rand() % 20;
        printf("%d ", n);
        InserirArvore(n, &abb);
    }
    printf("\n");
    ImprimeArvore(&abb);
    int ele = 10;
    if(BuscaElemento(ele, &abb)) printf("\n%d esta na arvore", ele);
    else printf("\n%d nao esta na arvore", ele);
    return 0;
}