#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main() {
    vector<int> tamanhos = {10, 100, 1000, 10000, 100000};
    vector<vector<int>> resultados;

    for (int tamanho : tamanhos) {
        vector<int> vetor(tamanho);

        // Inicializa o vetor com números aleatórios
        for (int i = 0; i < tamanho; i++) {
            vetor[i] = rand() % 10000;
        }

        // Mede o tempo de execução
        auto inicio = chrono::high_resolution_clock::now();
        bubbleSort(vetor);
        auto fim = chrono::high_resolution_clock::now();

        // Calcula o tempo decorrido
        chrono::duration<double> tempo = chrono::duration_cast<chrono::duration<double>>(fim - inicio);

        // Adiciona o resultado à lista de resultados
        resultados.push_back({tamanho, static_cast<int>(tempo.count())});
    }

    // Salva os resultados em um arquivo JSON
    json jsonResultados = resultados;
    ofstream arquivo("resultados.json");
    arquivo << jsonResultados.dump(4); // Aumenta a legibilidade do JSON
    arquivo.close();

    return 0;
}