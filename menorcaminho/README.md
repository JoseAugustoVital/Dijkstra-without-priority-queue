# Teoria dos Grafos e seus Algoritmos

## Informações do Estudante

- **Nome**: José Augusto Lajo Vieira Vital
- **Universidade**: Universidade Federal do Mato Grosso do Sul (FACOM - Faculdade de Computação)
- **Matéria**: Teoria dos Grafos e seus Algoritmos
- **Professor**: Vagner Pedrotti

## Algoritmo de Dijkstra sem fila de prioridade

Este projeto implementa o algoritmo de Dijkstra sem fila de prioridade. O algoritmo usa um vetor de distância e escolhe o vértice não visitado de menor valor no vetor por uma busca linear.

### Como executar

Para executar o programa, você precisa ter Python instalado em seu computador. Você pode baixar Python aqui.

Depois de instalar Python, você pode executar o programa com o seguinte comando:

```bash
python menorcaminho.py grafo.txt s
```

Caso o terminal retornar que o comando não foi identificado, tente colocar a versão do python instalada.
ex.: 
```bash
python3.11 menorcaminho.py grafo.txt s
```

Onde `grafo.txt` é o arquivo que contém a descrição do grafo e `s` é o vértice de origem.

## Formato do arquivo do grafo

O arquivo do grafo deve seguir o seguinte formato:

I n m  
N i g- g+  
E i j c T


Onde:

- `I n m`: Informações gerais do grafo, número de vértices e número de arestas.
- `N i g- g+`: Uma linha para cada vértice contendo o número do vértice de 0 a n-1 com o grau de entrada e o grau de saída.
- `E i j c`: Uma linha para cada arco do grafo, com o vértice de origem, vértice de destino e custo. O custo será sempre um inteiro não-negativo.
- `T`: Indica o fim do arquivo.

## Saída

Para todos os vértices (incluindo o próprio `s`) em ordem numérica, o programa imprime na saída uma linha contendo:

- Caso exista um caminho de `s` até `t`: `P t v c v1 v2 ... vn`
- Caso não exista caminho de `s` a `t`: `U t`
- Caso ocorra algum problema para leitura do grafo ou execução do algoritmo: `E`

