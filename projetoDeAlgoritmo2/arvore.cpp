#include <iostream>
#include "arvore.h"
#include <cstdlib>
#include <iomanip>
#include <string>
#include <math.h>

using namespace std;

Arv cria_arvore(void)
{
    Arv novo;
    novo = (struct arvore *)malloc(sizeof(struct arvore));
    novo->esq = NULL;
    novo->dir = NULL;
    novo->dado = 0;
    novo->altura = -1;
    return novo;
};

Arv rotacao_simples_esquerda(Arv p){
    Arv u, filhoEsquerdoDeU;

    u = p->dir;
    filhoEsquerdoDeU = u->esq;

    u->esq = p;
    p->dir = filhoEsquerdoDeU;

    p->altura = max(get_altura_arvore(p->esq), get_altura_arvore(p->dir)) + 1;
    u->altura = max(get_altura_arvore(u->esq), get_altura_arvore(u->dir)) + 1;
    
    return u;
}

Arv rotacao_simples_direita(Arv p){
    Arv u, filhoDireitoDeU;

    u = p->esq;
    filhoDireitoDeU = u->dir;

    u->dir = p;
    p->esq = filhoDireitoDeU;

    p->altura = max(get_altura_arvore(p->esq), get_altura_arvore(p->dir)) + 1;
    u->altura = max(get_altura_arvore(u->esq), get_altura_arvore(u->dir)) + 1;

    return u;
}

Arv rotacao_dupla_esquerda(Arv p){
    p->dir = rotacao_simples_direita(p->dir);
    return rotacao_simples_esquerda(p);
}

Arv rotacao_dupla_direita(Arv p){
    p->esq = rotacao_simples_esquerda(p->esq);
    return rotacao_simples_direita(p);
}

Arv balancear(Arv t){
    int fb = get_fator_de_balanceamento(t);

    /* Rotacão simples à esquerda */
    if (fb < -1 && get_fator_de_balanceamento(t->dir) <= 0){
        t = rotacao_simples_esquerda(t);
    }
    
    /* Rotacão simples à direita */
    else if (fb > 1 && get_fator_de_balanceamento(t->esq) >= 0)
        t = rotacao_simples_direita(t);
    
    /* Rotacão dupla à esquerda */
    else if (fb < -1 && get_fator_de_balanceamento(t->dir) > 0)
        t = rotacao_dupla_esquerda(t);
    
    /* Rotacão dupla à direita */
    else if (fb > 1 && get_fator_de_balanceamento(t->esq) < 0)
        t = rotacao_simples_direita(t);
    
    return t;
}

int get_altura_arvore(Arv t){

    if (t == nullptr || t->altura == -1)
        return -1;

    return t->altura;
}

void insere_elemento(Arv &t, int D)
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
            Arv novo = cria_arvore();
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
            Arv novo = cria_arvore();
            novo->dado = D;
            novo->altura = 0;
            t->dir = novo;
        }
    }
    else
    {
        cout << "INSERCAO NAO REALIZADA: Elemento" << D << "ja existe...\n";
    }

    int alturaArvoreEsquerda = get_altura_arvore(t->esq);
    int alturaArvoreDireita = get_altura_arvore(t->dir);

    t->altura = 1 + max(alturaArvoreEsquerda, alturaArvoreDireita);

    t = balancear(t);

}

int get_fator_de_balanceamento(Arv t){
    if (t)
        return (get_altura_arvore(t->esq) - get_altura_arvore(t->dir));
    else
        return 0;
}


void printa_arvore(Arv t, int espaco)
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


// temos três casos de REMOÇÃO:
/*
nó sem filho -> Dá o free e apaga o que eu quero e faz o pai do apagado apontar para NULL
nó com 1 filho -> o pai do apagado aponta para o filho do apagado
nó com 2 filhos -> Se o filho à direita não possui subárvore esquerda,é ele quem ocupa o seu lugar
                -> Se possuir uma subárvore esquerda, a raiz desta será movida para cima e assim por diante
                -> a estratégia geral (Mark Allen Weiss) é sempre substituir a chave retirada pela menor chave da subárvore direita.

*/

void remove_elemento(Arv &t, int D){
    if (t == NULL){
        cout << "Valor nao encontrado!\n";
    }else{ // procura o nó que se deseja remover
        if (t->dado == D){
            // remove nó folha (nó sem filho)
            if (t->esq == NULL && t->dir == NULL){
                free(t);
                t = NULL;
                cout << "Elemento removido: " << D << "\n";
            }else{
                // remove nó que possui 2 filhos
                if (t->esq != NULL && t->dir != NULL){
                    Arv aux = t->dir;
                    while (aux->esq != NULL)
                        aux = aux->esq;
                    t->dado = aux->dado;
                    aux->dado = D;
                    cout << "Elemento trocado: " << D << " ↔ " << t->dado << "\n";
                    remove_elemento(t->dir, D);
                }else{
                    // remove nó que possui apenas 1 filho
                    if (t->esq != NULL)
                        t = t->esq;
                    else
                        t = t->dir;
                }
            }
        }else{
            if (D < t->dado)
                remove_elemento(t->esq, D);
            else
                remove_elemento(t->dir, D);
        }
    }
    if (t){
        // recalcula a altura
        t->altura = max(get_altura_arvore(t->esq), get_altura_arvore(t->dir)) + 1;

        // Verifica a necessidade de rebalancear a árvore
        t = balancear(t);
    }
}