// Identificando o Chá
#include <stdio.h>

int main(){
    int tipoCha;
    int respostas[5];
    int acertos = 0;

    scanf("%d", &tipoCha);

    for(int i = 0; scanf("%d", &respostas[i]) != EOF && i<5; i++){
        if(respostas[i] == tipoCha)
            acertos++;
    }
    printf("%d\n", acertos);
    return 0;
}