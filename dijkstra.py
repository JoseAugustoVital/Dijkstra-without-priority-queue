# Importando as bibliotecas necessárias
import array
import sys

# Definindo uma constante para representar infinito
inf = float('inf')

# Classe Grafo para representar um grafo direcionado ponderado
class Grafo:
    def __init__(self, num_vertices):
        # Número total de vértices no grafo
        self.num_vertices = num_vertices
        # Lista de adjacências para representar o grafo
        self.adj_list = [[] for _ in range(num_vertices)]
        # Vetor para armazenar o comprimento do caminho mais curto para cada vértice
        self.length = [0] * num_vertices
        # Vetor para armazenar o caminho mais curto para cada vértice
        self.caminho = [[] for _ in range(num_vertices)]

    # Método para adicionar uma aresta ao grafo
    def add_edge(self, origem, destino, custo):
        # Adiciona o vértice de destino e o custo da aresta à lista de adjacências do vértice de origem
        self.adj_list[origem].append([destino, custo])

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
        u = min((i for i in range(Grafo.num_vertices) if not visitado[i]), key=lambda i: (dist[i], Grafo.length[i]))

        # Marca o vértice escolhido como visitado
        visitado[u] = True
        
        # Atualiza a distância dos vértices adjacentes ao vértice escolhido
        for v, custo in Grafo.adj_list[u]:
            # Se o vértice adjacente não foi visitado e a distância é menor através do vértice u 
            if not visitado[v] and dist[u] + custo < dist[v]:
                # Atualiza a distância e o comprimento do caminho mais curto
                dist[v] = dist[u] + custo
                Grafo.length[v] = Grafo.length[u] + 1
                # Atualiza o caminho mais curto para v através de u
                Grafo.caminho[v] = Grafo.caminho[u] + [u]
            # Em caso de empate na distância, escolhe o caminho com menor comprimento ou menor rótulo. #TODO
            elif not visitado[v] and dist[u] + custo == dist[v]:
                if Grafo.length[u]+1 < Grafo.length[v] or (Grafo.length[u]+1 == Grafo.length[v] and u < v):
                    Grafo.length[v] = Grafo.length[u] + 1
                    Grafo.caminho[v] = Grafo.caminho[u] + [u]

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
                    g.add_edge(int(data[1]), int(data[2]), int(data[3]))
            return g
    except Exception as e:
        print('Erro ao ler o arquivo')
        sys.exit(1)

# Função principal que lê o grafo, executa o algoritmo de Dijkstra e imprime os resultados.
def main():
    arquivo = sys.argv[1]
    inicio = int(sys.argv[2])
    
    g = read(arquivo)
    
    dist = dijkstra(g, inicio)
    
    for i in range(g.num_vertices):
        if dist[i] == inf:
            print('U', i)
        else:
            print('P', i, dist[i], g.length[i], ' '.join(map(str, g.caminho[i]+[i])))

if __name__ == "__main__":
    main()

# Para executar o código, use o seguinte comando no terminal:
# python3.11 dijkstra.py ../Dijkstra-without-priority-queue/inputs/g-10-30.txt 4 > generated-output.txt
