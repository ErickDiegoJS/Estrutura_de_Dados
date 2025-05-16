#include "lista.h"

void RemoverElementos(int ele, t_lista * lista){
    if(ele > QtdElementos(lista)){
        printf("Ha menos elementos que o necessario\n");
        return;
    }
    for(int i = 0; i < ele; i++){
        RemoveFim(lista);
    }
}

t_lista RetornaPares(t_lista *lista) {
    t_lista pares;
    ConstroiLista(&pares);
    for (t_no *runner = lista->primeiro; runner != NULL; runner = runner->prox) {
        if (runner->info % 2 == 0) {
            InsereFim(runner->info, &pares);
        }
    }
    return pares;
}

t_lista RetornaImpares(t_lista *lista) {
    t_lista impares;
    ConstroiLista(&impares);
    for (t_no *runner = lista->primeiro; runner != NULL; runner = runner->prox) {
        if (runner->info % 2 != 0) {
            InsereFim(runner->info, &impares);
        }
    }
    return impares;
}

int main() {
    t_lista l1, pares, impares;
    int valor;

    ConstroiLista(&l1);

    // Leitura da lista 1 até EOF
    while (scanf("%d", &valor) != EOF) {
        InsereFim(valor, &l1);
    }

    // Testa RemoverElementos: remove 2 elementos do fim de l1
    RemoverElementos(2, &l1);

    // Testa RetornaPares e RetornaImpares
    pares = RetornaPares(&l1);
    impares = RetornaImpares(&l1);

    printf("Lista original (após remoção): ");
    ExibirLista(&l1);

    printf("Pares: ");
    ExibirLista(&pares);

    printf("Impares: ");
    ExibirLista(&impares);

    // Libera memória
    while (!ListaVazia(&l1)) RemoveFim(&l1);
    while (!ListaVazia(&pares)) RemoveFim(&pares);
    while (!ListaVazia(&impares)) RemoveFim(&impares);

    return 0;
}