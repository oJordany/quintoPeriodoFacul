import json

import matplotlib.pyplot as plt


def plotar_grafico(json_file):
  with open(json_file, "r", encoding="utf-8") as file:
      dados = json.load(file)

  tamanhos = [d["input"] for d in dados]
  tempos = [d["time"] for d in dados]

  # Gerar gráfico
  plt.plot(tamanhos, tempos)
  plt.title('Análise de Complexidade no Tempo - Força Bruta')
  plt.xlabel('Tamanho da Entrada (Texto)')
  plt.ylabel('Tempo de Execução (s)')
  plt.show()

# Nome do arquivo JSON gerado anteriormente
json_file = "analise_complexidade.json"

# Chamar a função para plotar o gráfico
plotar_grafico(json_file)