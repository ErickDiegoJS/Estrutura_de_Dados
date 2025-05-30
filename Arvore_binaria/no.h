#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int info;
    struct no * esq;
    struct no * dir;
} t_no;

t_no * ConstroiNo (int);