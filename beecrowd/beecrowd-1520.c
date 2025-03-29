#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int inicio, fim;
    int id;
}Estante;

void bubble_sort (int v[], int n) {
    for (int i=1; i < n; i++)
        for (int j=0; j < n-i; j++)
            if (v[j] > v[j+1]) {
                int aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
}

void InserirIntervalo(Estante *caixa, int *enumeracao){
    fgets(caixa[*enumeracao]->inicio, sizeof(caixa->inicio), stdin);
    fgets(caixa[*enumeracao]->fim, sizeof(caixa->fim), stdin);
    *enumeracao++;
    caixa->id = *enumeracao;
}

void preenche_vetor(Estante *caixa, int *enumeracao, int vetor[], int *qtd) {
    vetor[*qtd];
    for(int i = 0; i < enumeracao; i++){
        for(int j = caixa[j]->inicio; j <= caixa[j]->fim; j++){
            vetor[i] = j;
        }        
    }
    bubble_sort(vetor, *qtd);
}

void BuscaCaixa(Estante *caixa, int *enumeracao){
    int num;
    int qtd = 0;
    int vetor[]
    scanf("%d", &num);
    for(int i = 0; i < enumeracao; i++){
        for(int j = caixa[j]->inicio; j <= caixa[j]->fim; j++){
            qtd++;
        }
    }
    for(int i = 0; i<qtd; i++){
        preenche_vetor(int vetor[], int qtd, int );
    }
    printf("%d found from %d to %d\n", num, );
    printf("%d not found\n", num);
}

int main(){
    int qtdcaixas;
    int enumeracao = 1;
    
    while(!EOF){
        scanf("%d", &qtdcaixas);
        Estante caixa[(int *) malloc(qtdcaixas * sizeof)];
        InserirIntervalo(caixa, &enumeracao);
        BuscaCaixa(caixa, &enumeracao);
    }
    
    
    return 0;
}