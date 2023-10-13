#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100
#define MAX_COST INT_MAX

typedef struct
{
    int vertex;
    int cost;
} Edge;

int graph[MAX_VERTICES][MAX_VERTICES];
int numVertices;

void readGraphFromFile()
{
    FILE *file = fopen("grafo.txt", "r");
    if (file == NULL)
    {
        printf("Erro ao realizar a leitura do arquivo 'grafo.txt'. \n");
        exit(1);
    }

    int numEdges;
    fscanf(file, "I %d %d", &numVertices, &numEdges);

    initializeGraph();

    for (int i = 0; i < numVertices; i++)
    {
        int vertex, inDegree, outDegree;
        fscanf(file, "N %d %d %d", &vertex, &inDegree, &outDegree);
    }

    for (int i = 0; i < numEdges; i++)
    {
        int source, dest, cost;
        fscanf(file, "E %d %d %d", &source, &dest, &cost);
        graph[source][dest] = cost;
    }

    fclose(file);
}

void dijkstra(int source)
{
    int distance[MAX_VERTICES];
    int visited[MAX_VERTICES];
    int previous[MAX_VERTICES];

    for (int i = 0; i < numVertices; i++)
    {
        distance[i] = MAX_COST;
        visited[i] = 0;
        previous[i] = -1;
    }

    distance[source] = 0;

    for (int i = 0; i < numVertices; i++)
    {
        int u = -1;
        for (int j = 0; j < numVertices; j++)
        {
            if (!visited[j] && (u == -1 || distance[j] < distance[u]))
            {
                u = j;
            }
        }

        visited[u] = 1;

        for (int v = 0; v < numVertices; v++)
        {
            if (graph[u][v] != -1)
            {
                if (distance[u] + graph[u][v] < distance[v])
                {
                    distance[v] = distance[u] + graph[u][v];
                    previous[v] = u;
                }
            }
        }
    }

    for (int t = 0; t < numVertices; t++)
    {
        if (t != source)
        {
            printf("C %d %d", distance[t], t);
            int path[MAX_VERTICES];
            int pathLength = 0;
            int current = t;
            while (current != -1)
            {
                path[pathLength] = current;
                pathLength++;
                current = previous[current];
            }
            for (int i = pathLength - 1; i >= 0; i--)
            {
                printf(" %d", path[i]);
            }
            printf("\n");
        }
    }
}

int main()
{
    readGraphFromFile();

    return 0;
}
