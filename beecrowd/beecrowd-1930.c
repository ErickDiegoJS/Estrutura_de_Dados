// Tomadas
#include <stdio.h>

int main(){
    int entrada;
    int totalTomadas = 0;

    while(scanf("%d", &entrada) != EOF){
        totalTomadas += entrada-1;
    }
    totalTomadas++;
    printf("%d\n", totalTomadas);

    return 0;
}