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
    if (get_altura_arvore(t) == -1)
    {   
        cout << "Reinicializou com " << D << endl;
        t->dado = D;
        t->altura = 0;
        return;
    }
    if (D < t->dado)
    {
        cout <<  "passou: ";
        if (t->esq){
            insere_elemento(t->esq, D);
        }else
        { /* Achou a inserção*/
            struct arvore *novo = cria_arvore();
            cout << "Inserindo (esquerda): " << D << "\n";
            novo->dado = D;
            int alturaAnterior = t->altura;
            t->esq = novo;
            // if (t->dir)  t->dir->altura -= 1;
            int alturaAtual = get_altura_arvore(t); 
            // if (t->dir) t->dir->altura += 1;
            alturaAnterior < alturaAtual ? t->altura += 1 : t->altura = t->altura;
            novo->altura = alturaAtual;
        }
    }
    else if (D > t->dado)
    {
        if (t->dir){
            insere_elemento(t->dir, D);
        }else
        {
            struct arvore *novo = cria_arvore();
            cout << "Inserindo (direita): " << D << "\n";
            novo->dado = D;
            int alturaAnterior = t->altura;
            t->dir = novo;
            // if (t->esq)  t->esq->altura -= 1;
            int alturaAtual = get_altura_arvore(t); 
            // if (t->esq->altura) t->esq->altura += 1;
            alturaAnterior < alturaAtual ? t->altura += 1 : t->altura = t->altura;
            novo->altura = alturaAtual;
        }
    }
    else
    {
        cout << "elemento ja existe na arvore\n";
    }
}

void printa_arvore(struct arvore *t, string prefixo, bool esq)
{
    if(get_altura_arvore(t) == 0) return;

    cout << prefixo << (esq ? "├── ": "└── ") << t->dado << "\n";
    
    if (t->esq && t->dir){
        printa_arvore(t->dir, prefixo + (esq ? "|   " : "    "), esq=true);
        printa_arvore(t->esq, prefixo + (esq ? "    " : "|   "), esq=false);
    }
    else if (t->dir){
        printa_arvore(t->dir, prefixo + (esq ? "|   " : "    "), esq=false);
    }
    else if (t->esq){
        printa_arvore(t->esq, prefixo + (esq ? "|   " : "    "), esq=true);
    }
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