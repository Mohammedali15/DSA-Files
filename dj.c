#include <stdio.h>
#include <limits.h>

void dijkstra(int graph[100][100], int n, int src);

int main()
{
    int n, src;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int graph[n][n];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the source vertex: ");
    scanf("%d", &src);

    dijkstra(graph, n, src);

    return 0;
}

void dijkstra(int graph[100][100], int n, int src)
{
    int dist[n];
    int visited[n];

    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int count = 0; count < n - 1; count++)
    {
        int minDist = INT_MAX;
        int minIndex;

        for (int v = 0; v < n; v++)
        {
            if (visited[v] == 0 && dist[v] <= minDist)
            {
                minDist = dist[v];
                minIndex = v;
            }
        }

        visited[minIndex] = 1;

        for (int v = 0; v < n; v++)
        {
            if (visited[v] == 0 && graph[minIndex][v] && dist[minIndex] != INT_MAX &&
                dist[minIndex] + graph[minIndex][v] < dist[v])
            {
                dist[v] = dist[minIndex] + graph[minIndex][v];
            }
        }
    }

    printf("Vertex\tDistance\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\n", i, dist[i]);
    }
}
