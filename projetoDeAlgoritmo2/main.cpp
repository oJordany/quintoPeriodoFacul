#include <iostream>
#include "arvore.h"
using namespace std;

int main()
{
    Arv arvore;
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
        cout << "inserindo nodo " << chaves[i] << endl;
        insere_elemento(arvore, chaves[i]);
        // cout << "nova altura: "<< get_altura_arvore(arvore) << endl;
    }

    // printa_arvore(arvore, 0);

    // cout << "\n" << arvore->altura;
    printa_arvore(arvore);

    // Arv u = rotacao_simples_esquerda(arvore->dir->dir);

    free(chaves);

    return 0;
}