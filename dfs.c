#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100

// Structure for a graph node
struct Node {
    int value;
    struct Node* next;
};

// Structure for a graph
struct Graph {
    int numNodes;
    struct Node* adjList[MAX_NODES];
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
struct Graph* createGraph(int numNodes) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numNodes = numNodes;
    for (int i = 0; i < numNodes; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
}

// Function to perform DFS on the graph
void DFS(struct Graph* graph, int node, bool visited[], int* result[], int* index) {
    visited[node] = true;

    // Perform DFS on all adjacent nodes
    struct Node* currNode = graph->adjList[node];
    while (currNode != NULL) {
        int adjNode = currNode->value;
        if (!visited[adjNode]) {
            DFS(graph, adjNode, visited, result, index);
        }
        currNode = currNode->next;
    }

    // Add the current node to the result
    *result[*index] = node;
    (*index)++;
}

// Function to perform topological sorting
void topologicalSort(struct Graph* graph) {
    bool visited[MAX_NODES] = {false};
    int* result = (int*)malloc(graph->numNodes * sizeof(int));
    int index = 0;

    for (int i = 0; i < graph->numNodes; i++) {
        if (!visited[i]) {
            DFS(graph, i, visited, &result, &index);
        }
    }

    // Print the topological sort result
    printf("Topological Sorting: ");
    for (int i = graph->numNodes - 1; i >= 0; i--) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
}

int main() {
    int numNodes, numEdges;
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &numNodes);
    printf("Enter the number of edges in the graph: ");
    scanf("%d", &numEdges);

    struct Graph* graph = createGraph(numNodes);

    printf("Enter the edges:\n");
    for (int i = 0; i < numEdges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    topologicalSort(graph);

    return 0;
}

