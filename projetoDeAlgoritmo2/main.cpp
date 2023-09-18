#include <iostream>
#include "arvore.h"
using namespace std;

int main()
{
    struct arvore *arvore;
    int *chaves;
    chaves = (int *)malloc(sizeof(int) * 9);

    chaves[0] = 30;
    chaves[1] = 15;
    chaves[2] = 60;
    chaves[3] = 10;
    chaves[4] = 20;
    chaves[5] = 40;
    chaves[6] = 80;
    chaves[7] = 90;
    chaves[8] = 91;

    arvore = cria_arvore();

    for (int i = 0; i < 9; i++)
    {
        cout << get_altura_arvore(arvore) << endl;
        insere_elemento(arvore, chaves[i]);
    }

    cout << get_altura_arvore(arvore) << endl;
    cout << arvore->dado << endl;
    cout << arvore->dir->dir->altura << endl;
    // printa_arvore(arvore);

    free(chaves);
}