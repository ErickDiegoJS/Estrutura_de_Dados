"# Estrutura_de_Dados" 
gcc testePalavra.c pilha.o
gcc testePilha.c pilha.o

estrutura do projeto:
t_carro{
  char placa;
}
t_carro_estacionado{
  t_carro palio;
  int manobras -1;
}

tipo de entrada:
0 estacionou/1 saiu

0 abc1234
0 jhg3456
1 abc1234
==========================================
Recursão
-Utiliz-se quando precisa-se de uma repetição sem laço.
-Caracterza-se pela cahamda de uma função por ela mesma.
-Não é possivel utilizar laços em estruturas ramificadas ou em algoritimos que utilizam tecnicas não comuns como o Back Tracking.
-Arvores são estruturas ramificadas.
-A "volta" no Back Tracking é possivel pelo desempilhamento.
===================================
#include <stdio.h>
//Exemplo 1: Fatorial

long fat_iterativo(int n){
    long f = 1;
    // for(int i=2; i<=n; i++){
    //     f = f * i;
    // }
    while(n>1) f = f+n--;
    return f;
}

long fat_recursivo(int n){
    if(n<=1) return 1;
    return n * fat_recursivo(n-1);
}

//Exemplo 2;; Fibonacci

long fibonacci(int n){
    if(n<=1) return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}

void exibe_rec1(int i,int n){
    printf("%d ", i);
    if(i < n) exibe_rec1(i+1, n);
}

void exibe_rec2(int i,int n){
    if(i < n) exibe_rec2(i+1, n);
    printf("%d ", i);
}

void exibe_rec3(int n){
    printf("%d ", n);
    if(n>1) exibe_rec3(n-1);
}

void exibe_rec4(int n){
    if(n>1) exibe_rec4(n-1);
    printf("%d ", n);
}

int main(){
    //Fatrial
    for(int i=0; i<=13; i++){
        printf("fatorial de %d: %0.ld\n", i, fat_iterativo(i));
    }
    printf("\n");
    for(int i=0; i<=13; i++){
        printf("fatorial de %d: %0.ld\n", i, fat_recursivo(i));
    }
    printf("\n");
    // Fibonacci
    // estoura em 46
    for(int i=0; i<=13; i++){
        printf("fibonacci de %d: %0.ld\n", i, fibonacci(i));
    }
    printf("\n");
    exibe_rec1(1, 5);
    printf("\n");
    exibe_rec2(1, 5);
    printf("\n");
    exibe_rec3(5);
    printf("\n");
    exibe_rec4(5);
    return 0;
}
