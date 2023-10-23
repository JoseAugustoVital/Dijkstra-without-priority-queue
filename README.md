# Projeto: Implementação do Algoritmo de Dijkstra sem Fila de Prioridade

Este projeto consiste na implementação do algoritmo de Dijkstra sem o uso de fila de prioridade. Em vez disso, utilizamos um vetor de distância e selecionamos o vértice não visitado de menor valor no vetor por meio de uma busca linear.

## Objetivo

O objetivo deste trabalho é alterar o problema do menor caminho para produzir o caminho de menor custo. No caso de empate entre vários caminhos, optamos pelo de menor comprimento. Se ainda persistir o empate, optamos pelo lexicograficamente anterior.

## Modificações no Algoritmo

Para atingir o objetivo, armazenamos o comprimento do caminho encontrado para cada vértice (Comprimento[v]) e fazemos duas modificações:

1. No momento de selecionar o vértice v a ser fixado (e removido da lista dos pendentes), escolhemos o vértice de menor valor de Distancia. Em caso de empate, optamos pelo com menor Comprimento. Se o empate persistir, escolhemos o de menor número.

2. No momento de atualizar os vetores Distancia e Anterior, consideramos o caso em que Distancia[v] + c(v,u) = Distancia[u]. Neste caso, trocamos o antecessor de u para v se Comprimento[v]+1 < Comprimento[v] ou Comprimento[v]+1 = Comprimento[v] e v for menor (numericamente) ao atual antecessor de u.

## Implementação

A implementação usa uma lista de adjacência para operar com grafos esparsos (muitos vértices e proporcionalmente poucas arestas).

## Execução

O programa processa a linha de comando, executa o que se pede, imprime a saída esperada e termina.

A linha de comando será como:

```bash
./menorcaminho grafo.txt s

O programa lê o grafo do arquivo grafo.txt e executa o algoritmo de Dijkstra com origem em s até todos os destinos.
Saída

Para todos os vértices (incluindo o próprio s) em ordem numérica, imprime na saída uma linha contendo:

    Caso exista um caminho de s até t:

    P t v c v1 v2 ... vn

    Caso não exista caminho de s a t:

    U t

    Caso ocorra algum problema para leitura do grafo ou execução do algoritmo:

    E

Formato do Grafo

O grafo segue o seguinte formato:

I n m
N i g- g+
E i j c
T

Observações

O grafo não terá mais de 10⁶ vértices nem mais de 10⁷ arestas. O trabalho é individual e deve ser inteiramente codificado pelo aluno sem auxílio de nenhuma ferramenta de geração de código.
