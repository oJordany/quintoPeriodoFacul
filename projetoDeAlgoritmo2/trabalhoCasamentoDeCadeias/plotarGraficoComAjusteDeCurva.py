import json
import matplotlib.pyplot as plt
import numpy as np

# def plotar_grafico(json_file):
#   with open(json_file, "r", encoding="utf-8") as file:
#       dados = json.load(file)

#   tamanhos = [d["input"] for d in dados]
#   tempos = [d["time"] for d in dados]

#   # Gerar gráfico
#   plt.plot(tamanhos, tempos, marker='o')
#   plt.title('Análise de Complexidade no Tempo - Força Bruta')
#   plt.xlabel('Tamanho da Entrada (Texto)')
#   plt.ylabel('Tempo de Execução (s)')
#   plt.show()

# # Nome do arquivo JSON gerado anteriormente
# json_file = "analise_complexidade.json"

# # Chamar a função para plotar o gráfico
# plotar_grafico(json_file)



def plotar_grafico(json_file):
    with open(json_file, "r", encoding="utf-8") as file:
        dados = json.load(file)

    tamanhos = np.array([d["input"] for d in dados])
    tempos = np.array([d["time"] for d in dados])

    #sem ajuste de curva
    plt.plot(tamanhos, tempos, label="Curva de complexidade O((n-m+1)*m)")

    # Realizar ajuste linear
    coeficientes = np.polyfit(tamanhos, tempos, 1)
    curva_ajustada = np.polyval(coeficientes, tamanhos)

    # Gerar gráfico
    plt.scatter(tamanhos, tempos, label='Pontos de Dados')
    plt.plot(tamanhos, curva_ajustada, color='red', label='Curva Ajustada (Linear)')
    plt.xlabel('Tamanho da Entrada (Texto)')
    plt.ylabel('Tempo de Execução (s)')
    plt.legend()
    # plt.show()

# Nome do arquivo JSON gerado anteriormente
json_files = ["analise_complexidade_NotFound.json", "analise_complexidade_RandomWord.json"]

# Chamar a função para plotar o gráfico
fig = plt.figure(figsize = (18,8))
plt.rcParams.update({'font.size': 14})
fig.suptitle("Análise da Complexidade do Algoritmo Casamento de Cadeia por Força Bruta ")
for i, json_file in enumerate(json_files): 
    fig.add_subplot(120+i+1)
    plotar_grafico(json_file)
    plt.title('Análise para padrão não encontrado (padrão = "+")') if i == 0 else plt.title('Análise para padrão encontrado (palavra escolhida aleatoriamente)')

plt.show()