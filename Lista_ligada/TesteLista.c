#include "lista.h"

int main(){
    t_lista lista;
    ConstroiLista(&lista);
    for(int i =1; i<=10; i++){
        InsereInicio(i, &lista);
    }

    ExibirLista(&lista);

    while(!ListaVazia(&lista)){
        printf("%d saiu do inicio\n", RemoveInicio(&lista));
        ExibirLista(&lista);
    }

    for(int i=1;i<=10 ; i++){
        InsereFim(i, &lista);
    }

    ExibirLista(&lista);

    while(!ListaVazia(&lista)){
        printf("%d saiu do final\n", RemoveFim(&lista));
        ExibirLista(&lista);
    }
    return 0;
}