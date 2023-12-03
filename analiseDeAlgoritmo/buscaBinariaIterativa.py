import numpy as np
import timeit
import time
import json

def binarySearchIterative(orderedList, searchedValue):
    firstIndex = 0
    listLength = len(orderedList)
    lastIndex = listLength - 1
    middleElementIndex = (firstIndex + lastIndex) // 2
    middleElement = orderedList[middleElementIndex]

    finded = False
    while not finded:
        if firstIndex == lastIndex:
            if middleElement != searchedValue:
                return None
            else:
                finded = True
        
        elif middleElement == searchedValue:
            finded = True 
        
        elif middleElement > searchedValue:
            newPosition = middleElementIndex - 1
            lastIndex = newPosition
            middleElementIndex = (firstIndex + lastIndex) // 2
            middleElement = orderedList[middleElementIndex]
            if middleElement == searchedValue:
                finded = True
            
        elif middleElement < searchedValue:
            newPosition = middleElementIndex + 1
            firstIndex = newPosition
            middleElementIndex = (firstIndex + lastIndex) // 2
            middleElement = orderedList[middleElementIndex]
            if middleElement == searchedValue:
                finded = True

    return middleElementIndex

def binarySearchRecursive(lista_de_numeros, primeiro_indice, ultimo_indice, valor_pesquisado):
    if ultimo_indice >= primeiro_indice:
       
        indice_elemento_do_meio = (primeiro_indice + ultimo_indice) // 2
        elemento_do_meio = lista_de_numeros[indice_elemento_do_meio]
       
 
        if elemento_do_meio == valor_pesquisado:
            return indice_elemento_do_meio
 
        elif elemento_do_meio > valor_pesquisado:
            nova_posicao = indice_elemento_do_meio - 1
            # novo último índice é a nova posição
            return binarySearchRecursive(lista_de_numeros, primeiro_indice, nova_posicao, valor_pesquisado)
 
        elif elemento_do_meio < valor_pesquisado:
            nova_posicao = indice_elemento_do_meio + 1
             #novo primeiro índice é a nova posição
            return binarySearchRecursive(lista_de_numeros, nova_posicao, ultimo_indice, valor_pesquisado)
 
    else:
        return None
            
def analisarAssintoticamente():
    MAX_SIZE = 10**7 + 900000
    size = 10
    results = {"Algoritmo recursivo": [],  "Algoritmo iterativo": []}

    while size < MAX_SIZE:
        randomValues = np.random.choice(np.arange(0, 10**8), size=size, replace=False)
        orderedList = np.sort(randomValues)
        searchedValueIndex = -1
        searchedValue = orderedList[searchedValueIndex]

        recursiveExecutionTime = time.process_time()
        binarySearchRecursive(orderedList, 0, size - 1, searchedValue)
        recursiveExecutionTime = time.process_time() - recursiveExecutionTime

        iterativeExecutionTime = time.process_time()
        binarySearchIterative(orderedList, searchedValue)
        iterativeExecutionTime = time.process_time() - iterativeExecutionTime

        results["Algoritmo recursivo"].append([size, recursiveExecutionTime])
        results["Algoritmo iterativo"].append([size, iterativeExecutionTime])

        if size < 10000:
            size *= 2
        else: 
            size += 10000

    with open("analiseAssintoticaBuscaBinaria_2.json", "w", encoding="utf-8") as file:
        json.dump(results, file, indent=4)

analisarAssintoticamente()