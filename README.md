# Projeto: Implementação do Algoritmo de Dijkstra

## Descrição do Trabalho

Este projeto envolve a implementação do algoritmo de Dijkstra sem fila de prioridade. O algoritmo utiliza um vetor de distância e seleciona o vértice não visitado de menor valor no vetor por uma busca linear.

O problema do menor caminho é alterado para produzir o caminho de menor custo. Em caso de empate entre vários caminhos, opta-se pelo de menor comprimento. Se ainda persistir o empate, opta-se pelo lexicograficamente anterior.

## Modificações no Algoritmo

Para fazer isto, é preciso armazenar o comprimento do caminho encontrado para cada vértice: Comprimento[v], e fazer duas modificações:

1. No momento de selecionar o vértice v a ser fixado (e removido da lista dos pendentes). Quando se escolhe o vértice de menor valor de Distancia, em caso de empate, opte pelo com menor Comprimento. Em caso de persistência do empate, escolha o de menor número.
2. No momento de atualizar os vetores Distancia e Anterior. Quando se verifica se Distancia[v] + c(v,u) < Distancia[u], deve-se considerar o caso em que Distancia[v] + c(v,u) = Distancia[u]. Neste caso, deve-se trocar o antecessor de u para v caso Comprimento[v]+1 < Comprimento[v] ou Comprimento[v]+1 = Comprimento[v] e v for menor (numericamente) ao atual antecessor de u.

A implementação usa uma lista de adjacência para poder operar com grafos esparsos (muitos vértices e proporcionalmente poucas arestas).

## Execução

Seu programa deverá processar a linha de comando, executar o que se pede, imprimindo a saída esperada e terminar.

A linha de comando será como:

```bash
./menorcaminho grafo.txt s
