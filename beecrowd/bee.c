#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int inicio, fim;
    int id;
} Estante;

void bubble_sort(int v[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (v[j] > v[j + 1]) {
                int aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
}

void InserirIntervalo(Estante *caixa, int qtd) {
    for (int i = 0; i < qtd; i++) {
        scanf("%d %d", &caixa[i].inicio, &caixa[i].fim);
        caixa[i].id = i + 1;
    }
}

void BuscaCaixa(Estante *caixa, int qtd) {
    int num;
    scanf("%d", &num);
    
    int menor = -1, maior = -1;
    
    for (int i = 0; i < qtd; i++) {
        if (num >= caixa[i].inicio && num <= caixa[i].fim) {
            if (menor == -1) menor = caixa[i].id;
            maior = caixa[i].id;
        }
    }

    if (menor == -1)
        printf("%d not found\n", num);
    else
        printf("%d found from %d to %d\n", num, menor, maior);
}

int main() {
    int qtdcaixas;
    
    while (scanf("%d", &qtdcaixas) != EOF) {
        Estante *caixa = (Estante *)malloc(qtdcaixas * sizeof(Estante));
        if (caixa == NULL) {
            printf("Erro de memória\n");
            return 1;
        }

        InserirIntervalo(caixa, qtdcaixas);
        BuscaCaixa(caixa, qtdcaixas);

        free(caixa);
    }

    return 0;
}
