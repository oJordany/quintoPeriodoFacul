import json
import timeit
import random
import math

from lipsumAPI import lipsum

from buscaForcaBruta import busca_forca_bruta


def gera_texto(tamanho):
  return lipsum.byte(tamanho)


def palavra_aleatoria(frase):
    # Dividir a frase em palavras
    palavras = frase.split()

    # Escolher uma palavra aleatória
    palavra_aleatoria = random.choice(palavras)

    return palavra_aleatoria

def analisar_complexidade(tamanhos):
  dados = []

  for tamanho in tamanhos:
    texto = gera_texto(tamanho)
    padrao = texto[0:math.floor(len(texto)/2)]

    tempo_execucao = timeit.timeit(lambda: busca_forca_bruta(texto, padrao),
                                   number=10000)

    dados.append({
        "input": tamanho,
        "time": tempo_execucao / 10  # Calcula a média do tempo de execução
    })

    print(
        f"Tamanho: {tamanho}, Tempo de Execução: {tempo_execucao / 10} segundos (média de 100 execuções)"
    )

  # Adicionar dados ao arquivo JSON
  with open("analise_complexidade.json", "w", encoding="utf-8") as file:
    json.dump(dados, file, indent=4)


# Tamanhos de entrada para análise com ajuste de curva
# tamanhos_analise = [10] + list(range(100, 1001, 100))
# tamanhos_analise = tamanhos_analise + list(range(2000, 10001, 100))
# tamanhos_analise = tamanhos_analise + list(range(20000, 100001, 100))

# Tamanhos de entrada para análise sem ajuste de curva
tamanhos_analise = [10, 100, 500, 1000, 1250, 1500, 1750, 2000, 2500, 3000, 3500, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 12500, 15000, 17500, 20000, 25000, 30000, 35000, 40000, 50000, 60000, 70000, 80000, 90000, 100000]

# print(tamanhos_analise)
# Realizar análise de complexidade
analisar_complexidade(tamanhos_analise)
print("Análise de complexidade finalizada!")