#include <string>
using namespace std;

typedef int 
    tipo_elem;

typedef struct arv
    *Arv;

struct arvore
{
    struct arvore *esq;
    struct arvore *dir;
    tipo_elem dado;
    int altura;
    int FB;
};

struct arvore *cria_arvore(void);

void insere_elemento(struct arvore *, int);

void printa_arvore(struct arvore *, int);

int get_altura_arvore(struct arvore *);

int get_altura_esquerda(struct arvore *t);

int get_altura_direita(struct arvore *t);
