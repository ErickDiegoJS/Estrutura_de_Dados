#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int tempo = time(0);
    printf("Valor retornado pelo time(o): %d\n", tempo); 
    srand(10);
    int m = rand();
    int n = rand();
    printf("m = %d\n", m);

    printf("de 0 a 10: %d\n", rand()%11);
    return 0;
}