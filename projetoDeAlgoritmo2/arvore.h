#include <string>
using namespace std;

struct arvore
{
    struct arvore *esq;
    struct arvore *dir;
    int dado;
    int altura;
};

struct arvore *cria_arvore(void);

void insere_elemento(struct arvore *, int);

void printa_arvore(struct arvore *, int);

int get_altura_arvore(struct arvore *);