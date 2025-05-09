#include "no.h"

t_no * ConstroiNo (int info){
    t_no * novo = (t_no *) malloc(sizeof(t_no));
    novo->info = info;
    novo->prox = NULL;
    return novo;
}