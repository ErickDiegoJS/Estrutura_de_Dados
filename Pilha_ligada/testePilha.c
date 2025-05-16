#include "pilha.h"

t_pilha ConverterBaseBI(int num){
    t_pilha binaria;
    ConstroiPilha(&binaria);
    while(num > 1){
        Push(num % 2, &binaria);
        num = num / 2;
    }
    Push(num, &binaria);
    return binaria;
}

t_pilha PilhaInvertida(t_pilha *pilha){
    t_pilha aux;
    ConstroiPilha(&aux);
    int temp;
    while(!PilhaVazia(pilha)){
        Pop(pilha, &temp);
        Push(temp, &aux);
    }
    return aux;
}

void TransferirPilha(t_pilha *p1, t_pilha *p2){
    t_pilha aux;
    ConstroiPilha(&aux);
    int temp;
    while(!PilhaVazia(p1)){
        Pop(p1, &temp);
        Push(temp, &aux);
    }
    while(!PilhaVazia(&aux)){
        Pop(&aux, &temp);
        Push(temp, p2);
    }
}

int main(){
    t_pilha pilha;
    ConstroiPilha(&pilha);
    printf("Pilha inicial: \n");
    int num;
    while(scanf("%d", &num) != EOF){
        Push(num, &pilha);
    }
    ExibirPilha(&pilha);
    printf("Pilha Invertida: \n");
    t_pilha aux;
    ConstroiPilha(&aux);
    pilha = PilhaInvertida(&pilha);
    ExibirPilha(&pilha);
    printf("Trnasferir: \n");
    TransferirPilha(&pilha, &aux);
    printf("P1: \n");
    ExibirPilha(&pilha);
    printf("\nP2: \n");
    ExibirPilha(&aux);
    // Push(10, &pilha);
    // Push(20, &pilha);
    // Push(30, &pilha);
    // printf("\n");
    // ExibirPilha(&pilha);
    // int aux;
    // while(!PilhaVazia(&pilha)){
    //     if(Pop(&pilha, &aux)){
    //         printf("\n%d desempilhado", aux);
    //     }
    // }
    // printf("\n");
    // pilha = ConverterBaseBI(64);
    // ExibirPilha(&pilha); // Nome corrigido
    int temp;
    while(!PilhaVazia(&pilha)){
        Pop(&pilha, &temp);
    }
    return 0;
}