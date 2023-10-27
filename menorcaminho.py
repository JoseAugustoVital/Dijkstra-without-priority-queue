# Autor: José Augusto Lajo Vieira Vital
# Algoritmo de Dijkstra sem fila de prioridade utilizando lista de adjacencia

# Importando as bibliotecas necessárias
import sys

# Definindo uma constante para representar infinito
inf = float('inf')

# Classe Grafo para representar um grafo direcionado ponderado
class Grafo:
    def __init__(self, num_vertices):
        # Número total de vértices no grafo
        self.num_vertices = num_vertices
        # Lista de adjacências para representar o grafo
        self.lista_adj = [[] for _ in range(num_vertices)]
        # Vetor para armazenar o comprimento do caminho mais curto para cada vértice
        self.comprimento = [0] * num_vertices
        # Vetor para armazenar o caminho mais curto para cada vértice
        self.caminho = [[] for _ in range(num_vertices)]
        # Vetor para armazenar o elemento anterior para cada vértice
        self.anterior = [[] for _ in range(num_vertices)]

    # Método para adicionar uma aresta ao grafo
    def add_adj(self, origem, destino, custo):
        # Adiciona o vértice de destino e o custo da aresta à lista de adjacências do vértice de origem
        self.lista_adj[origem].append([destino, custo])

# Implementação do algoritmo de Dijkstra
def dijkstra(Grafo, inicio):
    # Inicializa a distância de todos os vértices como infinito
    dist = [inf] * Grafo.num_vertices
    # Marca todos os vértices como não visitados  
    visitado = [False] * Grafo.num_vertices
    # A distância do vértice inicial para ele mesmo é zero
    dist[inicio] = 0
    # Encontra o caminho mais curto para todos os vértices
    for _ in range(Grafo.num_vertices):
        # Escolhe o vértice com a menor distância, que ainda não foi visitado.
        u = min((i for i in range(Grafo.num_vertices) if not visitado[i]), key=lambda i: (dist[i], Grafo.comprimento[i],i))
        # Marca o vértice escolhido como visitado
        visitado[u] = True
        # Atualiza a distância dos vértices adjacentes ao vértice escolhido
        for v, custo in Grafo.lista_adj[u]:
            # Se o vértice adjacente não foi visitado e a distância é menor através do vértice u 
            if not visitado[v] and dist[u] + custo < dist[v]:
                # Atualiza a distância e o comprimento do caminho mais curto
                dist[v] = dist[u] + custo
                Grafo.comprimento[v] = Grafo.comprimento[u] + 1
                # Atualiza o caminho mais curto para v através de u
                Grafo.caminho[v] = Grafo.caminho[u] + [u]
                Grafo.anterior[v] = u
            # Em caso de empate na distância, escolhe o caminho com menor comprimento ou menor rótulo. 
            elif not visitado[v] and dist[u] + custo == dist[v]:
                # Se o comprimento não for igual ou se o comprimento for igual e o rótulo do vértice u é menor do que o vértice anteirior de v
                if Grafo.comprimento[u]+1 < Grafo.comprimento[v] or (Grafo.comprimento[u]+1 == Grafo.comprimento[v] and u < Grafo.anterior[v]):
                    # Atualiza o comprimento de v
                    Grafo.comprimento[v] = Grafo.comprimento[u] + 1
                    # Atualiza o caminho de v
                    Grafo.caminho[v] = Grafo.caminho[u] + [u]
                    # Atribui o u ao anterior de v
                    Grafo.anterior[v] = u
    return dist

# Função para ler o grafo de um arquivo de texto
def read(arquivo):
    try:
        with open(arquivo, 'r') as file:
            lines = file.readlines()
            num_vertices = int(lines[0].split()[1])
            g = Grafo(num_vertices)
            for line in lines[1:]:
                if line[0] == 'E':
                    data = line.split()
                    g.add_adj(int(data[1]), int(data[2]), int(data[3]))
            return g
    except Exception as e:
        print('Erro ao ler o grafo')
        sys.exit(1)

# Função principal que lê o grafo, executa o algoritmo de Dijkstra e imprime os resultados.
def main():
    # Argumentos de leitura
    arquivo = sys.argv[1]
    inicio = int(sys.argv[2])
    # Leitura do arquivo 
    g = read(arquivo)
    # Chamada da funcao Dijkstra
    dist = dijkstra(g, inicio)
    # Iterando sobre todos os vértices de g
    for i in range(g.num_vertices):
        if dist[i] == inf:
            print('U', i)
        else:
            print('P', i, dist[i], g.comprimento[i], ' '.join(map(str, g.caminho[i]+[i])))

if __name__ == "__main__":
    main()