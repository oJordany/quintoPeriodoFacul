#include <string>
using namespace std;

typedef int 
    tipo_elem;

typedef struct arvore
    *Arv;

struct arvore
{
    struct arvore *esq;
    struct arvore *dir;
    tipo_elem dado;
    int altura;
};

struct arvore *cria_arvore(void);

void insere_elemento(Arv &, int);

void printa_arvore(struct arvore *, int = 0);

int get_fator_de_balanceamento(Arv);

int get_altura_arvore(struct arvore *);

Arv rotacao_simples_esquerda(Arv);

Arv rotacao_simples_direita(Arv);

Arv rotacao_dupla_esquerda(Arv);

Arv rotacao_dupla_direita(Arv);

Arv balancear(Arv);
