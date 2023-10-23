# Bibliotecas utilizadas
import array
import sys

# Variável infinito
inf = float('inf')

# Classe para representar o grafo 
class Grafo:
    def __init__(self, num_vertices):
        self.num_vertices = num_vertices
        self.adj_list = [[] for _ in range(num_vertices)]
        self.length = [0] * num_vertices
        self.caminho = [[] for _ in range(num_vertices)]

    # Adiciona aresta ao grafo
    def add_edge(self, origem, destino, custo):
        self.adj_list[origem].append([destino, custo])

# Algoritmo de dijkstra
def dijkstra(Grafo, inicio):

    # Distâncias iniciadas com infinito
    dist = [inf] * Grafo.num_vertices

    # Marca todos os vértices como não visitados  
    visitado = [False] * Grafo.num_vertices

    # Distância do vértice source para ele mesmo é zero
    dist[inicio] = 0

    # Encontra vértices mais próximos, um por vez
    for _ in range(Grafo.num_vertices):

        # Escolhe o vértice com dist mínima
        u = min((i for i in range(Grafo.num_vertices) if not visitado[i]), key=lambda i: (dist[i], Grafo.length[i]))

        # Marca como visitado
        visitado[u] = True
        
        # Atualiza as distâncias dos vértices adjacentes (u,v) u: origem, v: destino
        for v, custo in Grafo.adj_list[u]:
            # Se não foi visitado e o Distancia[v] + c(v,u) < Distancia[u] 
            if not visitado[v] and dist[u] + custo < dist[v]:
                # Soma o custo atual mais o custo para chegar no vértice v
                dist[v] = dist[u] + custo
                # Incrementa o comprimento
                Grafo.length[v] = Grafo.length[u] + 1
                # Adiciona u ao caminho para v
                Grafo.caminho[v] = Grafo.caminho[u] + [u]
            # Em caso de empate
            elif not visitado[v] and dist[u] + custo == dist[v]:
                if Grafo.length[u]+1 < Grafo.length[v] or (Grafo.length[u]+1 == Grafo.length[v] and u < v):
                    Grafo.length[v] = Grafo.length[u] + 1
                    Grafo.caminho[v] = Grafo.caminho[u] + [u]

    return dist

# Função para ler o grafo do arquivo
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
        print('E')
        sys.exit(1)

# Função principal
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