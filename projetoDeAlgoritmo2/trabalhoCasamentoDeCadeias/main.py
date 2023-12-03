import lipsum

from buscaForcaBruta import busca_forca_bruta

# Códigos ANSI para cores
azul = "\033[94m"
verde = "\033[92m"
reset = "\033[0m"
vermelho = "\033[91m"

def gera_texto(tamanho):
  return lipsum.byte(tamanho)

def main():

  tamanhos_disponiveis = [500, 1000, 1500, 2000, 3000]

  while True: 
    # Escolher o tamanho do texto
    print(f"\n{azul}=== Menu de Opções ==={reset}")
    print("Escolha o tamanho do texto:\n")
    
    for i, tamanho in enumerate(tamanhos_disponiveis, start=1):
      print(f"{azul}{i}.{reset}{tamanho} caracteres")
      
    print(f"{azul}6.{reset}Sair\n")
    
    opcao_tamanho = int(input("Digite o número da opção desejada: "))
    
    if opcao_tamanho == 6 :
      print(f"{verde}Saindo do programa. Até mais!{reset}")
      break
    
    tamanho_texto = tamanhos_disponiveis[opcao_tamanho - 1]
  
    # Gerar texto aleatório
    texto_principal = gera_texto(tamanho_texto)
    print(f"\n{azul}Texto gerado:{reset}\n\n \t{texto_principal}\n")

    # Escolher o padrão de busca
    padrao_busca = input("Digite o padrão que deseja buscar no texto: ")
  
    resultados = busca_forca_bruta(texto_principal, padrao_busca)
  
    # Exibir resultados
    if resultados != [] :
      print(f"\n{verde}O padrão '{padrao_busca}' foi encontrado nos índices:{reset}{resultados}")
    else:
      print(f"\n{vermelho}O padrão '{padrao_busca}' não foi encontrado no texto.{reset}")
      
if __name__ == "__main__":
  main()
