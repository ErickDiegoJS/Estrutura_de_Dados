#include "pilha.h"

void LiberaPilha(t_pilha *p) {
    if (p != NULL) {
        free(p->dados); // Libera o vetor interno, se foi alocado dinamicamente
        free(p);        // Libera a estrutura da pilha
    }
}

void Preenche_vetor(t_pilha *p){
    int num;
    while(!PilhaCheia(p)){
        num = rand() % 100;
        Push(num, p);
    }
}

t_pilha *ConverterBaseBI(int num){
    t_pilha *binaria;
    binaria = (t_pilha *) malloc(sizeof(t_pilha));
    ConstroiPilha(30, binaria);
    while (num > 0) {
        Push(num % 2, binaria);
        num = num / 2;
    }
    return binaria;
    
}

void ParOuImpar(t_pilha *p, t_pilha *Par, t_pilha *Impar){
    int aux;
    while (Pop(p, &aux)) {
        if(aux % 2 == 0){
            Push(aux, Par);
        }
        else{
            Push(aux, Impar);
        }
    }
}

int PushInPosition(int i, int posicao, t_pilha *p) {
    if (!PilhaCheia(p)) {
        for (int j = p->topo; j >= posicao; j--) {
        p->dados[j + 1] = p->dados[j];
        }
        p->dados[posicao] = i;
        p->topo++; 
    }
    
    return 1;
}

t_pilha *PilhaDecrescente(t_pilha *p) {
    t_pilha *reserva = (t_pilha *) malloc(sizeof(t_pilha));
    ConstroiPilha(p->capaciade, reserva);
    int aux;
    while (Pop(p, &aux)) {
        int j;
        for (j = reserva->topo - 1; j >= 0; j--) {
            if (reserva->dados[j] >= aux) {
                break;
            }
        }
        PushInPosition(aux, j + 1, reserva);
    }
    return reserva;
}

t_pilha *TransferirPilha(t_pilha *p1, t_pilha *p2){
    t_pilha *reserva = (t_pilha *) malloc(sizeof(t_pilha));
    ConstroiPilha(p1->capaciade, reserva);
    int aux;
    while(Pop(p1, &aux)){
        Push(aux, reserva);
    }
    while(Pop(p2, &aux)){
        Push(aux, p2);
    }
    
    return p2;
}

int Busca(int x, t_pilha *v) {
    for (int i = 0; i < v->topo; i++) {
        if (v->dados[i] == x)
            return i; 
    }
    return -1;  
}


int main(){
    t_pilha pilha;
    int capacidade = 10;
    ConstroiPilha(capacidade, &pilha);
    Preenche_vetor(&pilha);
    ExibePliha(&pilha);
    int escolha;
    printf("\nO que se deseja fazer? ");
    printf("\n1 - Converaoo de base\n2 - Par ou impar\n3 - desempilhar\n4 - Inverter pilha\n5 - Pilha Decresente\n6 - sequencia\n7 - Transferir Pilha\n8 - Busca\n");
    scanf("%d", &escolha);
    int aux;
    switch (escolha)
    {
    case 1:
        printf("\n============ Conversão de Base ============\n");
        int num;
        printf("\nescolha o numero a ser convertido: ");
        scanf("%d", &num);
        pilha = *ConverterBaseBI(num);
        ExibePliha(&pilha);
        LiberaPilha(&pilha);
        break;
    case 2:
        printf("\n============ Par ou Impar ============\n");
        t_pilha *Par = (t_pilha *) malloc(sizeof(t_pilha));
        t_pilha *Impar = (t_pilha *) malloc(sizeof(t_pilha));
        ConstroiPilha(pilha.capaciade, Par);
        ConstroiPilha(pilha.capaciade, Impar);

        ParOuImpar(&pilha, Par, Impar);
        printf("\n============ Par ============\n");
        ExibePliha(Par);
        printf("\n============ Impar ============\n");
        ExibePliha(Impar);
        LiberaPilha(Par);
        LiberaPilha(Impar);

        break;
    case 3:
        printf("\n============ Desempilhar ===========\n");
        while(Pop(&pilha, &aux)){
            printf("%d foi desempilhado!\n", aux);
            ExibePliha(&pilha);
        }
        break;
    case 4:
        printf("============ Inverter Pilha ============\n");
        int i =1;
        while(Pop(&pilha, &aux));    
        printf("============ Pilha Original ============\n");
        while(Push(i++, &pilha));
        ExibePliha(&pilha);
        printf("============ Pilha Invertida ============\n");
        InverterPilha(&pilha);
        ExibePliha(&pilha);
        break;
    case 5:
        printf("============ Ordenar decresentemente ============\n");
        pilha = *PilhaDecrescente(&pilha);
        ExibePliha(&pilha);
        break;
    case 6:
        printf("============ Sequencia ============\n");
        t_pilha *p1 = (t_pilha *) malloc(sizeof(t_pilha));
        t_pilha *p2 = (t_pilha *) malloc(sizeof(t_pilha));
        t_pilha *p3 = (t_pilha *) malloc(sizeof(t_pilha));
        ConstroiPilha(6, p1);
        ConstroiPilha(6, p2);
        ConstroiPilha(6, p3);
        for(int i = 1; i<=4; i++){
            Push(i, p1);
        }
        int aux;
        Pop(p1, &aux);
        int temp = aux;
        Push(temp, p2);
        Pop(p1, &aux);
        Push(aux, p3);
        Pop(p1, &aux);
        Push(aux, p2);
        
        Pop(p1, &aux);
        temp = aux;
        Push(temp, p3);
        Pop(p2, &aux);
        Push(aux, p1);
        Pop(p2, &aux);
        Push(aux, p3);
        Pop(p1, &aux);
        Push(aux, p3);
        if(!PilhaVazia(p1)){
            ExibePliha(p1);
        }
        if(!PilhaVazia(p2)){
            ExibePliha(p2);
        }
        if(!PilhaVazia(p3)){
            ExibePliha(p3);
        }
        LiberaPilha(p1);
        LiberaPilha(p2);
        LiberaPilha(p3);
        break;
    case 7:
        printf("============ Transferir Pilha ============\n");
        t_pilha *p01 = (t_pilha *) malloc(sizeof(t_pilha));
        t_pilha *p02 = (t_pilha *) malloc(sizeof(t_pilha));
        ConstroiPilha(6, p01);
        ConstroiPilha(6, p02);
        TransferirPilha(p01, p02);
        break;
    case 8:
        printf("============ Busca ============\n");
        int nu;
        printf("Digite o numero a ser encontrado: ");
        scanf("%d", &nu);
        int pos = Busca(nu, &pilha);
        if(pos == -1){
            printf("\nO numero %d nao esta presente na pilha!", nu);
        }
        else{
            printf("\nO numero %d se encontra na posicao %d", nu, pos);
        }
        break;
    default:
    printf("\nopcao invalida!"); 
        break;
    }
    return 0;
}
