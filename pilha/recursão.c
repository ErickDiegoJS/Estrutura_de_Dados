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
