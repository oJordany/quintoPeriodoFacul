import random
import time
import json

def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]

tamanhos = [10, 100, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000]
resultados = []

for tamanho in tamanhos:
    # Gerar vetor aleatório
    vetor = [random.randint(1, 1000) for _ in range(tamanho)]

    # Medir tempo de execução do Bubble Sort
    inicio = time.time()
    bubble_sort(vetor)
    fim = time.time()
    tempo_execucao = fim - inicio

    resultados.append([tamanho, tempo_execucao])

# Salvar os resultados em um arquivo JSON
with open('resultados.json', 'w') as arquivo:
    json.dump(resultados, arquivo)

print("Resultados salvos em 'resultados.json'.")
