#include "pilha.h"

t_pilha ConverterBaseBI(int num){
    t pilha *binaria;
    binaria = (t_pilha *) malloc(sizeof(t_pilha));
    ConstroiPilha(30, &binaria);
    while(n>1){
        Push(num%2, &binaria);

        num = num/2;
    }
    Push(num, &binaria)
    return binaria;
    
}

int main(){
    t_pilha pilha;
    ConstroiPilha(10, &pilha);
    ExibePliha(&pilha);
    
    // Push(10, &pilha);
    // Push(20, &pilha);
    // if(Push(30, &pilha)){
    //     printf("30 empilhado com sucesso\n");
    // }
    // else{
    //     printf("Pilha cheia! Nao foi possivel empilhar");
    // }
    // ExibePliha(&pilha);

    int aux;
    // if(Pop(&pilha, &aux)){
    //     printf("30 desempilhado com sucesso!\n");
    // }
    // else{
    //     printf("Nao foi possivel desempilhar");
    // }
    // ExibePliha(&pilha);
    int i =1;
    while(Pop(&pilha, &aux));
    //Empilhar
    printf("============\nPilha Original\n============\n");
    while(Push(i++, &pilha));
    ExibePliha(&pilha);
    printf("============\nPilha Invertida\n============\n");
    InverterPilha(&pilha);
    ExibePliha(&pilha);
    printf("============\nConversão de Base\n============\n");
    
    // printf("============\nDesempilhar\n===========\n");
    // printf("========================\n");
    // while(Pop(&pilha, &aux)){
    //     printf("%d foi desempilhado!\n", aux);
    //     ExibePliha(&pilha);
    // }


    return 0;
}
