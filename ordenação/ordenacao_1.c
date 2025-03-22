#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preenche_vetor(int v[], int n){
    for(int i=0; i<n; i++){
        v[i] = rand();
    }
}
void exibe_vetor(int v[], int n){
    for(int i =0; i < n; i++){
        printf("%d, ", v[i]);
    }
    printf("\n");
}

int main(){
    int *V;
    int n;
    srand(time(0));
    printf("escolha o tamanho do vetor: ");
    scanf("%d", &n);
    V = (int *) malloc (n * sizeof(int));
    preenche_vetor(V, n);
    exibe_vetor(V, n);

    return 0;
}