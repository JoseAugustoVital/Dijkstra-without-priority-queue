<div align="center">

<h1 style="font-size: 32px">Implementação do Algoritmo de Dijkstra Modificado</h1>

<p style="font-size: 18px">Descrição do projeto...</p>

</div>

<div align="center">

</div>

Este projeto consiste na implementação de uma variação do algoritmo de Dijkstra para encontrar o caminho de menor custo em um grafo ponderado.

## Descrição do Problema

O objetivo é modificar o algoritmo de Dijkstra padrão para que ele retorne o caminho de menor custo entre dois vértices. Em caso de empate entre caminhos, deve-se priorizar:

1. Caminho de menor comprimento
2. Caminho lexicograficamente menor

## Solução Implementada

Para resolver esse problema, foi feita uma implementação do algoritmo de Dijkstra com as seguintes modificações:

- Armazenamento do comprimento do caminho para cada vértice (vetor `Comprimento[]`) 
- Ao escolher próximo vértice, usar distância como critério principal, comprimento como critério de desempate e número do vértice como último critério
- Ao atualizar distâncias, verificar se deve trocar antecessor com base em distância, comprimento e número do vértice

Dessa forma, garante-se que o caminho retornado é de menor custo, desempatando primeiro por comprimento e depois lexicograficamente.

## Detalhes da Implementação

A implementação utiliza:

- Lista de adjacência para representar o grafo 
- Vetor de distâncias ao invés de fila de prioridade
- Busca linear no vetor para escolher próximo vértice

## Compilação e Execução

O programa deve ser compilado com:

```
g++ dijkstra.cpp -o dijkstra
```

E executado assim:

```
./dijkstra grafo.txt origem
```

Onde `grafo.txt` contém a descrição do grafo e `origem` é o vértice de partida.

## Formato de Entrada

O arquivo de entrada deve conter o grafo no seguinte formato:

```
I n m
N i g- g+
E i j c
T
```

Onde:
- `n` = número de vértices
- `m` = número de arestas
- `N` = linha por vértice com grau de entrada e saída
- `E` = arestas com vértice origem, destino e custo
- `T` = fim do arquivo

## Limitações

- Máximo de 1.000.000 vértices
- Máximo de 10.000.000 arestas

## Licença

Este projeto é licenciado sob a Licença MIT. Veja o arquivo LICENSE para mais detalhes.
