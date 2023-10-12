#include<stdio.h>
#include<stdlib.h>

typedef int CUSTO;

typedef struct Arco {
   int v_origem;           // vértice de origem
   int v_destino;          // vértice de destino 
   CUSTO custo;            // custo associado a aresta
   struct Arco *prox;      // próximo elemento da lista de adjacências
} Arco;

typedef struct Vertice {
   int num;                // número do vértice de 0 a n-1
   int grau_mais;          // grau de entrada
   int grau_menos;         // grau de saída
   int comprimento;        // comprimento do caminho encontrado para o vértice
   Arco *cabeca; 
} Vertice;

typedef struct Grafo {
   int n;          // número de vértices 
   int m;          // número de arcos
   Vertice *adj;   // ponteiro para o vetor de listas de adjacências
} Grafo;

Grafo *inicializarGrafo(int n, int m) {
   Grafo *grafo = (Grafo *)malloc(sizeof(Grafo));
   grafo->n = n;
   grafo->m = m;
   grafo->adj = (Vertice *)malloc(n * sizeof(Vertice));
   for (int i = 0; i < n; i++) {
     grafo->adj[i].num = i;
     grafo->adj[i].grau_mais = 0;
     grafo->adj[i].grau_menos = 0;
     grafo->adj[i].comprimento = 0;
     grafo->adj[i].cabeca = NULL;
   }
   printf("Grafo inicializado.\n");  // TODO
   return grafo;
}

// Função para adicionar um arco ao grafo
void adicionarArco(Grafo *grafo, int origem, int destino, CUSTO custo) {
   Arco *arco = (Arco *)malloc(sizeof(Arco));
   arco->v_origem = origem;
   arco->v_destino = destino;
   arco->custo = custo;
   arco->prox = grafo->adj[origem].cabeca;
   grafo->adj[origem].cabeca = arco;
   grafo->adj[origem].grau_menos++;
   grafo->adj[destino].grau_mais++;
   grafo->m++;
}

int main(void) {

   FILE *arquivo = fopen("grafo.txt", "r");
   char c, inicial;
   int n, m;

   // Caso o arquivo não possa ser aberto
   if (arquivo == NULL) {
      printf("E\n");
      return 1;
   }

   // Lê a letra, os números de vértices e arcos do arquivo
   if (fscanf(arquivo, "I %d %d", &n, &m) != 2) {
      printf("Erro ao ler informações gerais do grafo\n"); // TODO
      return 1;
   }

   printf("%d %d\n", n, m);

   Grafo *grafo = inicializarGrafo(n, m);

   fscanf(arquivo, " "); // Consome o espaço em branco e a nova linha

   // Lê as informações de vértices
   for (int i = 0; i < n; i++) {
      int num, grau_mais, grau_menos;
      if (fscanf(arquivo, "N %d %d %d", &num, &grau_mais, &grau_menos) != 3) {
         printf("Erro ao ler informações do vértice %d\n", i);    // TODO
         return 1;
      }
      grafo->adj[i].num = num;
      grafo->adj[i].grau_mais = grau_mais;
      grafo->adj[i].grau_menos = grau_menos;

      printf("Informações dos vértices lidas.\n");  // TODO
   }

   fscanf(arquivo, " "); // Consome o espaço em branco e a nova linha

   // Lê as informações de arcos
   for (int i = 0; i < m; i++) {
      int origem, destino;
      CUSTO custo;
      if (fscanf(arquivo, "E %d %d %d", &origem, &destino, &custo) != 3) {
         printf("Erro ao ler informações do arco %d\n", i);
         return 1;
      }
      adicionarArco(grafo, origem, destino, custo);
   }



   fclose(arquivo);

   return 0;
}