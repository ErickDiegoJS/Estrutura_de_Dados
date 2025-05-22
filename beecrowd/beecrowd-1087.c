// Dama
#include <stdio.h>
#include <stdlib.h>

int main(){
    int inicio[2];
    int destino[2];
    int move = 0;
    while(1){
        scanf("%d %d", &inicio[0], &inicio[1]);
        scanf("%d %d", &destino[0], &destino[1]);
        if (inicio[0] == 0 && inicio[1] == 0 && destino[0] == 0 && destino[1] == 0) {
            break;
        }
        if(inicio[0] == destino[0] && inicio[1] == destino[1]){
            move = 0;
        } else if(inicio[0] == destino[0] || inicio[1] == destino[1] || abs(inicio[0] - destino[0]) == abs(inicio[1] - destino[1])){
            move = 1;
        } else{
            move = 2;
        }
        printf("%d\n", move);
    }
    return 0;
}