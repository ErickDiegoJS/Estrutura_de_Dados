#include "no.h"
// abb = Árvore Binaria de Busca

typedef struct {
    t_no * raiz;
} t_abb;

void IniciaAroreBinaria (t_abb *);
int ArvoreVazia (t_abb *);
void InserirArvore (int, t_abb *);
void ImprimeArvore(t_abb *);
int BuscaElemento (int, t_abb *);