#include <string.h>
#include "pilhaCaracter.h"

int main(){
    char palavra[20];
    t_pilha_caracter pc;
    ConstroiPilha(strlen(palavra),&pc);
    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    for (int i =0; i<strlen(palavra); i++){
        Push(palavra[i], &pc);
    }

    int Spalindromo = 1;
    int i =0;
    char aux;
    while(!PilhaVazia(&pc) && Spalindromo){
        Pop(&pc, &aux);
        if(palavra[i] != aux){
            Spalindromo = 0;
        }
        else{
            i++;
        }
    }

    if(Spalindromo){
        printf("%s e palindromo", palavra);
    }
    else{
        printf("%s nao e palindromo", palavra);
    }

    return 0;
}