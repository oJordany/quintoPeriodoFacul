import json
import matplotlib.pyplot as plt

def plotGraph(nameFile):
    with open(nameFile, "r", encoding="utf-8") as file:
        datas = json.load(file)

    # xRecursive = [orderedPair[0] for orderedPair in datas["Algoritmo recursivo"]]
    # yRecursive = [orderedPair[1] for orderedPair in datas["Algoritmo recursivo"]]
    # plt.plot(xRecursive, yRecursive, "r-", label="Algoritmo recursivo")

    xIterative = [orderedPair[0] for orderedPair in datas]
    yIterative = [orderedPair[1] for orderedPair in datas]
    plt.plot(xIterative, yIterative, "b-", label="n.k")
    # plt.xticks(sorted(xRecursive+xIterative))
    # plt.yticks(sorted(yRecursive+yIterative))
    plt.ylabel("tempo de execução")
    plt.xlabel("tamanho da entrada")
    plt.legend()
    plt.grid()
    plt.show()
     
plotGraph("analiseAssintoticaBuscaBinaria.json")