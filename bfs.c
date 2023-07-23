#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int parent[MAX_VERTICES];
bool visited[MAX_VERTICES];

int numVertices;

// Function to initialize the graph
void initializeGraph() {
    int i, j;
    for (i = 0; i < MAX_VERTICES; i++) {
        for (j = 0; j < MAX_VERTICES; j++) {
            graph[i][j] = 0;
        }
        visited[i] = false;
    }
}

// Function to add an edge to the graph
void addEdge(int src, int dest, int weight) {
    graph[src][dest] = weight;
    graph[dest][src] = weight;
}

// Function to find the vertex with minimum distance value, from the set of vertices not yet included in MST
int minKey(int key[]) {
    int min = INT_MAX, min_index, v;
    for (v = 0; v < numVertices; v++) {
        if (visited[v] == false && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to print the MST
void printMST() {
    printf("Edge \tWeight\n");
    for (int i = 1; i < numVertices; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}

// Function to construct and print MST for a graph using BFT
void findMST() {
    int key[MAX_VERTICES];  // Key values used to pick minimum weight edge in cut
    int i, u, v;

    for (i = 0; i < numVertices; i++) {
        key[i] = INT_MAX;
        visited[i] = false;
    }

    key[0] = 0;  // First vertex is always the root of MST
    parent[0] = -1;  // First node is always root

    for (i = 0; i < numVertices - 1; i++) {
        u = minKey(key);
        visited[u] = true;

        for (v = 0; v < numVertices; v++) {
            if (graph[u][v] && visited[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST();
}

int main() {
    int numEdges, src, dest, weight;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    initializeGraph();

    printf("Enter the edges (src, dest) and weight:\n");
    for (int i = 0; i < numEdges; i++) {
        scanf("%d %d %d", &src, &dest, &weight);
        addEdge(src, dest, weight);
    }

    printf("Minimum Spanning Tree using BFT:\n");
    findMST();

    return 0;
}
