#include <iostream>
#include "arvore.h"
using namespace std;

int main()
{
    Arv arvore;
    int *chaves;
    int op;
    int valor;
    arvore = cria_arvore();
/*
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


    for (int i = 0; i < 9; i++)
    {
        cout << "inserindo nodo " << chaves[i] << endl;
        insere_elemento(arvore, chaves[i]);
    }
*/

    while(1){
        cout << "\n1 - Inserir elemento\n";
        cout << "2 - Remover Elemento\n";
        cout << "3 - Printar árvore\n";
        cout << "4 - Sair\n";
        cout << "Opcao: ";
        cin >> op;

        switch (op)
        {
        case 1:
            cout << "Qual o valor a ser inserido? ";
            cin >> valor;
            insere_elemento(arvore, valor);
            break;
        case 2:
            cout << "Qual o valor a ser removido? ";
            cin >> valor;
            remove_elemento(arvore, valor);
            break;
        case 3:
            printa_arvore(arvore);
            break;
        case 4:
            exit(0);
            break;
        default:
            cout << "Insira uma opcao válida...\n";
            break;
        }

    }
    

    return 0;
}