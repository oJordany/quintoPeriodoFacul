def busca_forca_bruta(texto, padrao):
  """
  Função que realiza uma busca de padrão (substring) em um texto usando o método de força bruta.

  Parâmetros:
  - texto (str): O texto no qual a busca será realizada.
  - padrao (str): O padrão a ser procurado no texto.

  Retorno:
  Lista contendo os índices de início de todas as ocorrências do padrão no texto.
  """
  #obtém o comprimento do texto e do padrão
  n = len(texto)
  m = len(padrao)
  indices = []  # lista de índices de início do casamento de cadeias
  
  #percorre o texto até que onde a última ocorrência possível do padrão começaria.
  for i in range(n - m + 1):
    j = 0 # Inicializa o índice para percorrer o padrão
    while j < m and texto[i + j] == padrao[j]:
      j += 1 #Incrementa o índice enquanto os caracteres são iguais
  
    # Verifica se o padrão foi encontrado
    if j == m:
      indices.append(i)  # Adiciona o índice de início da ocorrência na lista

  return indices  # Retorna a lista de índices