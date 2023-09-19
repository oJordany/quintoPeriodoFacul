#include <iostream>
#include "arvore.h"
#include <cstdlib>
#include <iomanip>
#include <string>
#include <math.h>

using namespace std;

struct arvore *cria_arvore(void)
{
    struct arvore *novo;
    novo = (struct arvore *)malloc(sizeof(struct arvore));
    novo->esq = NULL;
    novo->dir = NULL;
    novo->dado = 0;
    novo->altura = -1;
    return novo;
};

int get_altura_arvore(struct arvore *t){

    if (t == nullptr || t->altura == -1){
        return -1;
    } 
    int alturaEsquerda = get_altura_arvore(t->esq);
    int alturaDireita = get_altura_arvore(t->dir);


    return 1 + max(alturaEsquerda, alturaDireita);
}

void insere_elemento(struct arvore *t, int D)
{
    if (t->altura == -1)
    {   
        t->dado = D;
        t->altura = 0;
        return;
    }
    if (D < t->dado)
    {
        if (t->esq){
            insere_elemento(t->esq, D);
        }else
        { /* Achou a inserção*/
            struct arvore *novo = cria_arvore();
            novo->dado = D;
            novo->altura = 0;
            t->esq = novo;
        }
    }
    else if (D > t->dado)
    {
        if (t->dir){
            insere_elemento(t->dir, D);
        }else
        {
            struct arvore *novo = cria_arvore();
            novo->dado = D;
            novo->altura = 0;
            t->dir = novo;
        }
    }
    else
    {
        cout << "Elementos iguais\n";
    }
    t->altura = 1 + max(get_altura_arvore(t->esq), get_altura_arvore(t->dir));
}

void printa_arvore(struct arvore *t, int espaco)
{
    // Caso base
    if (t == NULL)
        return;
    
    // Aumenta a distância entre os níveis
    espaco += 5;

    // Processa o filho direito primeiro
    printa_arvore(t->dir, espaco);

    // Imprime o nó atual
    cout << endl;
    for (int i = 5; i < espaco; i++)
        cout << " ";
    cout << t->dado << "\n";

    // Processa o filho esquerdo
    printa_arvore(t->esq, espaco);
}

// ↘ ↙

// temos três casos de REMOÇÃO:
/*
nó sem filho -> Dá o free e apaga o que eu quero e faz o pai do apagado apontar para NULL
nó com 1 filho -> o pai do apagado aponta para o filho do apagado
nó com 2 filhos -> Se o filho à direita não possui subárvore esquerda,é ele quem ocupa o seu lugar
                -> Se possuir uma subárvore esquerda, a raiz desta será movida para cima e assim por diante
                -> a estratégia geral (Mark Allen Weiss) é sempre substituir a chave retirada pela menor chave da subárvore direita.

*/

void pre_ordem(struct arvore *f)
{
    if (f == NULL)
    {
        return;
    }
}