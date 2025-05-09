#include "pilha.h"

t_pilha ConverterBaseBI(int num){
    t_pilha *binaria;
    binaria = (t_pilha *) malloc(sizeof(t_pilha));
    ConstroiPilha(&binaria);
    while(num>1){
        Push(num%2, &binaria);

        num = num/2;
    }
    Push(num, &binaria);
    return *binaria;
    
}

int main(){
    t_pilha pilha;
    ConstroiPilha(&pilha);
    ExibePliha(&pilha);
    Push(10, &pilha);
    Push(20, &pilha);
    Push(30, &pilha);
    ExibePliha(&pilha);
    int aux;
    while(!PilhaVazia(&pilha)){
        if(Pop(&pilha, &aux)){
            printf("\n%d desempilhado", aux);
        }
    }
    pilha = ConverterBaseBI(64);
    ExibePliha(&pilha);
    return 0;
}