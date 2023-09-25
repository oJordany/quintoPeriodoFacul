#include <iostream>
#include <string>
#include <map>
#include <cmath>
#include <vector>

using namespace std;
 
typedef struct Time{
    string nomeDoTime;
    int pontos;
    int vitorias;
    int gols;
    int ordem;
} 
Time;

bool comparaTimes(const Time& time1, const Time& time2){
    if (time1.pontos != time2.pontos) return time1.pontos > time2.pontos;
    if (time1.vitorias != time2.vitorias) return time1.vitorias > time2.vitorias;
    if (time1.gols != time2.gols) return time1.gols > time2.gols;
    return time1.ordem < time2.ordem;
}

int main() {
 
    int T, N, M, gols1, gols2;
    string time1, time2, nomeDoTime;


    cin >> T;
    for (int i = 0; i < T; i++){
        map<string, Time> listaDeClassificacao;
        cin >> N >> M;

        for (int i = 0; i < N; i++){
            // cout << "Nome do time: \n";
            cin >> nomeDoTime;
            Time time;
            time.nomeDoTime = nomeDoTime;
            time.gols = 0;
            time.pontos = 0;
            time.vitorias = 0;
            time.ordem = i;
            listaDeClassificacao[nomeDoTime] = time;
        }

        for (int i = 0; i < M; i++){
            cin >> gols1 >> time1 >> gols2 >> time2;
            if (gols1 - gols2 > 0){
                listaDeClassificacao[time1].gols += gols1;
                listaDeClassificacao[time1].pontos += 3;
                listaDeClassificacao[time1].vitorias += 1;
                listaDeClassificacao[time2].gols += gols2;
            }else if (gols1 - gols2 < 0){
                listaDeClassificacao[time2].gols += gols2;
                listaDeClassificacao[time2].pontos += 3;
                listaDeClassificacao[time2].vitorias += 1;
                listaDeClassificacao[time1].gols += gols1;
            }else{
                listaDeClassificacao[time2].gols += gols2;
                listaDeClassificacao[time2].pontos += 1;
                listaDeClassificacao[time1].gols += gols1;
                listaDeClassificacao[time1].pontos += 1;
            }
        }

        vector<Time> timesOrdenados;
        for (auto& par : listaDeClassificacao) {
            timesOrdenados.push_back(par.second);
        }

        int tamanho = timesOrdenados.size();
        for (int i = 0; i < tamanho-1; i++) {
            for (int j = 0; j < tamanho-i-1; j++) {
                if (!(comparaTimes(timesOrdenados[j], timesOrdenados[j+1]))) {
                    Time aux = timesOrdenados[j];
                    timesOrdenados[j] = timesOrdenados[j+1];
                    timesOrdenados[j+1] = aux;
                    // swap(arr[j], arr[j+1]);
                }
            }
        }
        for (int i = 0; i < tamanho; i++){
            cout << timesOrdenados[i].nomeDoTime << "\n";
        }
    }

    return 0;
}