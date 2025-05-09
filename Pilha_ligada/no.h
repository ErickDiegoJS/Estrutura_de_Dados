#include <stdlib.h>

// struct no é uma tag utilizada para fazer a recursão
// da pra chamar o t_no e a struct no
typedef struct no{
    int info;
    struct no * prox;
} t_no;

// a função controi no retorna um ponteiro
t_no * ConstroiNo (int);