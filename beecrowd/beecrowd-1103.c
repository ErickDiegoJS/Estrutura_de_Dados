// Alarme Despertador
#include <stdio.h>

int main(){
    int horas[4];
    int saida;
    while(1){
        for(int i=0; i<4; i++){
            scanf("%d", &horas[i]);
        }
        if (horas[0] == 0 && horas[1] == 0 && horas[2] == 0 && horas[3] == 0) {
            break;
        }
        int saida = (horas[2] * 60 + horas[3]) - (horas[0] * 60 + horas[1]);
        if (saida <= 0) {
            saida += 24 * 60;
        }
        printf("%d\n", saida);
    }
    return 0;
}