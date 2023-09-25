#include <iostream>
#include <cstdlib>
#include <chrono>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;
using namespace std::chrono;

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
    vector<vector<double>> test_cases = {{10, 9}, {100, 99}, {1000, 999}, {10000, 9999}, {20000, 19999}, {30000, 29999}, {40000, 39999}, {50000, 49999}, {60000, 59999}, {100000, 99999}};
    vector<vector<double>> results;

    for (const auto& test_case : test_cases) {
        double n = test_case[0];
        double k = test_case[1];

        auto start = high_resolution_clock::now();

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
        
        cout << "Case " << ": " << circulo->numeracao << "\n";
        free(circulo); // Liberando a última pessoa)

        auto end = high_resolution_clock::now();
        duration<double> duration = end - start;
        results.push_back({n, duration.count()});
    }

    // Escrever os resultados no arquivo JSON
    ofstream output_file("resultados.json");
    output_file << fixed << setprecision(6);
    output_file << "[\n";
    for (size_t i = 0; i < results.size(); i++) {
        output_file << "    [" << results[i][0] << ", " << results[i][1] << "]";
        if (i != results.size() - 1) {
            output_file << ",";
        }
        output_file << "\n";
    }
    output_file << "]\n";

    return 0;
}