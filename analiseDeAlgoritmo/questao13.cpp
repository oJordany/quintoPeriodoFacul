#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct pessoa *Circulo;

struct pessoa{
    struct pessoa *prox;
    int numeracao;
    int salto;
};

Circulo cria_pessoa(int numeracao, int salto){
    Circulo novaPessoa;
    novaPessoa = (struct pessoa *)malloc(sizeof(struct pessoa));
    novaPessoa->prox = novaPessoa; // Inicializa o próximo como ele mesmo
    novaPessoa->numeracao = numeracao;
    novaPessoa->salto = salto;

    return novaPessoa;
}

void add_pessoa(Circulo ultimo, int numeracao, int salto){
    Circulo novaPessoa = cria_pessoa(numeracao, salto);
    Circulo proxUltimo = ultimo->prox;

    novaPessoa->prox = proxUltimo;
    ultimo->prox = novaPessoa;
}

void remover_pessoa(Circulo circ){
    Circulo pessoaRemovida = circ->prox;
    circ->prox = pessoaRemovida->prox;
    free(pessoaRemovida);
}

int main (){
    int NC;
    int n;
    int k;
    int numeracaoFinal;
    cin >> NC;

    for (int i = 0; i < NC; i++){
        cin >> n >> k;

        Circulo circulo = cria_pessoa(1, k); // Começando a numeracao de 1

        for (int i = 2; i <= n; i++){
            add_pessoa(circulo, i, k);
            circulo = circulo->prox;
        }

        while (circulo->prox != circulo) {
            for (int i = 1; i < k; i++) {
                circulo = circulo->prox;
            }
            remover_pessoa(circulo);
        }
        
        cout << "Case " << i+1 << ": " << circulo->numeracao << "\n";
        free(circulo); // Liberando a última pessoa

    }

    return 0;
}