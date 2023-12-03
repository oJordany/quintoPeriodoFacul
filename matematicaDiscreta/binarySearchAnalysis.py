import numpy as np
import time
import json
import matplotlib.pyplot as plt

def binarySearchIterative(orderedList, searchedValue):
    firstIndex = 0
    lastIndex = len(orderedList) - 1

    while firstIndex <= lastIndex:
        middleElementIndex = (firstIndex + lastIndex) // 2
        middleElement = orderedList[middleElementIndex]

        if middleElement == searchedValue:
            return middleElementIndex
        elif middleElement < searchedValue:
            firstIndex = middleElementIndex + 1
        else:
            lastIndex = middleElementIndex - 1

    return None

def binarySearchRecursive(lista_de_numeros, primeiro_indice, ultimo_indice, valor_pesquisado):
    if ultimo_indice >= primeiro_indice:
        indice_elemento_do_meio = (primeiro_indice + ultimo_indice) // 2
        elemento_do_meio = lista_de_numeros[indice_elemento_do_meio]

        if elemento_do_meio == valor_pesquisado:
            return indice_elemento_do_meio
        elif elemento_do_meio > valor_pesquisado:
            return binarySearchRecursive(lista_de_numeros, primeiro_indice, indice_elemento_do_meio - 1, valor_pesquisado)
        else:
            return binarySearchRecursive(lista_de_numeros, indice_elemento_do_meio + 1, ultimo_indice, valor_pesquisado)
    else:
        return None

def analisarAssintoticamente():
    MAX_SIZE = 10**7 + 900000
    size = 10
    results = {"Algoritmo recursivo": [], "Algoritmo iterativo": []}

    while size < MAX_SIZE:
        randomValues = np.random.choice(np.arange(0, 10**8), size=size, replace=False)
        orderedList = np.sort(randomValues)
        searchedValueIndex = -1
        searchedValue = orderedList[searchedValueIndex]

        # Medição do tempo para o algoritmo recursivo
        recursiveStartTime = time.time()
        binarySearchRecursive(orderedList, 0, size - 1, searchedValue)
        recursiveExecutionTime = time.time() - recursiveStartTime

        # Medição do tempo para o algoritmo iterativo
        iterativeStartTime = time.time()
        binarySearchIterative(orderedList, searchedValue)
        iterativeExecutionTime = time.time() - iterativeStartTime

        results["Algoritmo recursivo"].append([size, recursiveExecutionTime])
        results["Algoritmo iterativo"].append([size, iterativeExecutionTime])

        if size < 10000:
            size *= 2
        else:
            size += 10000

    with open("analiseAssintoticaBuscaBinaria.json", "w", encoding="utf-8") as file:
        json.dump(results, file, indent=4)

def gerarGrafico():
    with open("analiseAssintoticaBuscaBinaria.json", "r", encoding="utf-8") as file:
        data = json.load(file)

    sizes = [entry[0] for entry in data["Algoritmo recursivo"]]
    recursive_times = [entry[1] for entry in data["Algoritmo recursivo"]]
    iterative_times = [entry[1] for entry in data["Algoritmo iterativo"]]

    plt.figure(figsize=(10, 6))
    plt.plot(sizes, recursive_times, label="Algoritmo Recursivo", marker='o')
    plt.plot(sizes, iterative_times, label="Algoritmo Iterativo", marker='o')
    plt.xscale('log')  # Escala logarítmica para melhor visualização
    plt.yscale('log')  # Escala logarítmica para melhor visualização
    plt.title('Análise Assintótica - Busca Binária')
    plt.xlabel('Tamanho da Entrada')
    plt.ylabel('Tempo de Execução (s)')
    plt.legend()
    plt.grid(True)
    plt.show()

analisarAssintoticamente()
gerarGrafico()