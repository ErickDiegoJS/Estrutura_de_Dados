// Pneu
#include <stdio.h>

int main(){
    int entrada;
    int pressao = 0;

    scanf("%d", &entrada);
    scanf("%d", &pressao);
    pressao = entrada - pressao;
    printf("%d\n", pressao);

    return 0;
}