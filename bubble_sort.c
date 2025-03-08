#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//declaração das funções, ie, seus protótipos
void preenche_vetor(int[], int);
void exibe_vetor(int[], int, char *);
void bubble_sort (int[], int);

int main () {
    int *v;
    int n;
    srand(time(0));
    printf ("escolha o tamanho do vetor, 0 encerra: ");
    scanf ("%d", &n);
    while (n > 0) {
        v = (int *) malloc (n * sizeof(int));
        preenche_vetor(v, n);
        exibe_vetor(v, n, "vetor original");
        long int ini = time(0);
        bubble_sort(v, n);
        long int fim = time(0);
        exibe_vetor(v, n, "vetor ordenado");
        printf ("\ntempo de ordenacao: %ld\n", fim-ini);
        free(v);
        printf ("\nescolha o novo tamanho, 0 encerra: ");
        scanf ("%d", &n);
    }

    // while (1) {
    //     v = (int *) malloc (4000000);
    //     printf ("endereco alocado: %p\n", v);
    //     free(v);
    // }
    return 0;
}

void preenche_vetor(int v[], int n) {
    for (int i=0; i<n; i++)
        v[i] = rand() % (10 * n);
}
void exibe_vetor(int v[], int n, char *msg) {
    printf ("\n%s\n", msg);
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}
void bubble_sort (int v[], int n) {
    for (int i=1; i < n; i++)
        for (int j=0; j < n-i; j++)
            if (v[j] > v[j+1]) {
                int aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
}