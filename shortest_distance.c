#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include<limits.h>
void dijkstra(int array[100][100],int n,int src);
int main()
{
    int n,sp;
    printf("Enter the number of vertices \n");
    scanf("%d",&n);
    int graph[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
           printf("Enter the adjacency matrix value for edge (%d, %d): ", i, j);
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter the source node from which you need to calculate the shortes distance\n");
    scanf("%d",&sp);
     dijkstra(graph,n,sp);
}
void dijkstra(int graph[100][100], int n, int src)
{
    int dist[n]; // Array to store the shortest distances
    bool sptSet[n]; // Array to track the visited vertices
    int parent[n]; // Array to store the shortest path tree

    // Initialize dist, sptSet, and parent arrays
    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
        sptSet[i] = false;
        parent[i] = -1;
    }

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find the shortest path for all vertices
    for (int count = 0; count < n - 1; count++)
    {
        // Find the vertex with the minimum distance value
        int minDist = INT_MAX;
        int minIndex;

        for (int v = 0; v < n; v++)
        {
            if (!sptSet[v] && dist[v] <= minDist)
            {
                minDist = dist[v];
                minIndex = v;
            }
        }

        // Mark the selected vertex as visited
        sptSet[minIndex] = true;

        // Update dist value of the adjacent vertices of the selected vertex
        for (int v = 0; v < n; v++)
        {
            if (!sptSet[v] && graph[minIndex][v] != 0 && dist[minIndex] != INT_MAX &&
                dist[minIndex] + graph[minIndex][v] < dist[v])
            {
                dist[v] = dist[minIndex] + graph[minIndex][v];
                parent[v] = minIndex;
            }
        }
    }

    // Print the shortest distances and paths from the source
    printf("Vertex\tDistance\tPath\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t", i, dist[i]);

        // Print the path
        int j = i;
        while (j != src)
        {
            printf("%d <- ", j);
            j = parent[j];
        }
        printf("%d\n", src);
    }
}
