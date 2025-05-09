#include "lista.h"

int main(){
    t_lista lista;
    ConstroiLista(&lista);
    // for(int i =1; i<=10; i++){
    //     InsereInicio(i, &lista);
    // }

    int entrada;
    while(scanf("%d", &entrada) != EOF){
        InsereFim(entrada, &lista);
    }
    
    ExibirLista(&lista);

    // while(!ListaVazia(&lista)){
    //     printf("%d saiu do inicio\n", RemoveInicio(&lista));
    //     ExibirLista(&lista);
    // }

    // for(int i=1;i<=10 ; i++){
    //     InsereFim(i, &lista);
    // }

    // ExibirLista(&lista);

    // while(!ListaVazia(&lista)){
    //     printf("%d saiu do final\n", RemoveFim(&lista));
    //     ExibirLista(&lista);
    // }

    printf("\nA qtd de elementos na lista e %d", QtdElementos(&lista));

    printf("\nO maior elemento da lista e %d", MaiorElemento(&lista));

    int ele = 76;
    printf("\nO elemento %d esta na posicao %d da lista", ele, EncontrarElemento(&lista, ele));

    ele = 35;
    printf("\nO elemento %d aparece %dx na lista", ele, ContarElemento(&lista, ele));

    t_lista listaElementos;
    ConstroiLista(&listaElementos);
    listaElementos = PosicoesElemento(&lista, ele);
    printf("\nAs posicoes em que %d aparece sao: ", ele);
    ExibirLista(&listaElementos);

    return 0;
}