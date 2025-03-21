#include <stdio.h>

//Ler uma sequencia de numeros até encontrar o EOF(end-of-file)

int main(){
    int a, b, n;

    // printf("Digite dois numeros: ");
    // n = scanf("%d%d", &a, &b);
    // printf("\nn = %d\n", n);
    // printf("numeros: %d %d", a, b);

    while((scanf("%d", &a)) != EOF){
        printf("%d ", a);
    }
    
    printf("\nAcabou o arquivo");
    return 0;
}
