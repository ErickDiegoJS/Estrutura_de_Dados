//1.passo: construir uma struct representando a pilha
//dados é um vetor(*) de inteiros(int), pois ele vai armazenar um conjunto de numeros
//topo é um ponteiro que aponta para o topo da pilha e capacidade é um numero fixo que delimita o tamanho
typedef struct{
    int *dados;
    int topo;
    int capacidade;
}Tpilha;

//2.passo: Elabora uma função construtor para pilha, pique java
void ConstruirPilha(int capacidade, Tpilha *p){
    p->dados = (int*) malloc(sizeof(Tpilha));
    p->topo = 0;
    p->capacidade = capacidade;
}

//3.passo: Elaborar verificações para pilha vazia e pilha cheia
int PilhaCheia(Tpilha *p){
    return p->topo == p->capacidade;// retorna 1 para caso estiver cheia e 0 para caso contrario
}
int PilhaVazia(Tpilha *p){
    return !p->topo;// se topo = 0, pilh vazia, retorna 1, se maior que 0, pilha com dados, retorna 0;
}

//4.passo: Fazer as funções Push e Pop
int Push(int n, Tpilha *p){
    if(!PilhaCheia(p)){
        p->dados[p->topo++] = n;
        return 1;
    }
    return 0;// para saber se a pilha está cheia
} 

int Pop(Tpilha *p, int *removido){
    if(!PilhaVazia(p)){
        *removido = p->dados[--p->topo];
        return *removido;// retorna o numero desempilhado
    }
    return 0;
}
