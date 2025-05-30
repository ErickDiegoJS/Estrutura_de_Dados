# include "no.h"

t_no * ConstroiNo (int i){
    t_no * novo = (t_no *) malloc(sizeof(t_no));
    if(novo != NULL){
        novo->info = i;
        novo->esq = NULL;
        novo->dir = NULL;
    }
    return novo;
}