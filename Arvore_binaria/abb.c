#include "abb.h"

void IniciaAroreBinaria (t_abb * arvore){
    arvore->raiz = NULL;
}
int ArvoreVazia (t_abb * arvore){
    return !arvore->raiz;
}

void InserirArvoreRec(t_no * novo, t_no * atual){
    if(novo->info > atual->info){ //para direita
        if(atual->dir == NULL){ //se direita vazia
            atual->dir = novo;
        } else { // se direita com elemento: chamada recursiva
            InserirArvoreRec(novo, atual->dir);
        }
    } else { // para esquerda
        if(atual->esq == NULL){ // se direita vazia
            atual->esq = novo;
        } else { 
            InserirArvoreRec(novo, atual->esq);
        }
    }
}

void InserirArvore (int e, t_abb * arvore){
    t_no * novo = ConstroiNo(e);
    if(ArvoreVazia(arvore))
        arvore->raiz = novo;
    else
        InserirArvoreRec(novo, arvore->raiz);
}

void ImprimeArvoreRec(t_no * atual){
    if(atual != NULL){
        ImprimeArvoreRec(atual->esq);
        printf("%d ", atual->info);
        ImprimeArvoreRec(atual->dir);
    }
}


void ImprimeArvore(t_abb * arvore){
    if (ArvoreVazia(arvore)) printf("Arvore vazia");
    else ImprimeArvoreRec(arvore->raiz);
}

int BuscaElementoRec (int elemento, t_no * atual) {
    if (atual != NULL) return 0;
    if (atual->info == elemento) return 1;
    if (elemento > atual->info) return BuscaElementoRec(elemento, atual->dir);
    return BuscaElementoRec(elemento, atual->esq);
}

int BuscaElemento (int elemento, t_abb * arvore) {
    // devolver 1 (verdadeiro) se elemento estiver na arvore, ou 0 (falso) caso contrario
    if(ArvoreVazia(arvore)) return 0;
    return BuscaElementoRec (elemento, arvore->raiz); 
}