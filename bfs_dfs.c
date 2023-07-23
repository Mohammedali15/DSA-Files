#include <stdio.h>
#include <stdlib.h>

struct node {
    int vertex;
    struct node* next;
};

struct Graph {
    int numVertices;
    struct node** adjLists;
};

struct node* createNode(int v) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(struct node*));

    int i;
    for (i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // For undirected graph, add an edge from dest to src as well
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void BFS(struct Graph* graph, int startVertex) {
    int* visited = calloc(graph->numVertices,sizeof(int));

    struct node* queue = createNode(startVertex);
    visited[startVertex] = 1;

    while (queue != NULL)
    {
        int currentVertex = queue->vertex;
        printf("%d ", currentVertex);

        struct node* temp = graph->adjLists[currentVertex];
        while (temp != NULL)
        {
            int adjVertex = temp->vertex;
            if (visited[adjVertex] == 0)
            {
                visited[adjVertex] = 1;
                struct node* newNode = createNode(adjVertex);
                newNode->next = queue;
                queue = newNode;
            }
            temp = temp->next;
        }

        struct node* toDelete = queue;
        queue = queue->next;
        free(toDelete);
    }

    free(visited);
}

void DFSUtil(struct Graph* graph, int vertex, int* visited)
{
    visited[vertex] = 1;
    printf("%d ", vertex);

    struct node* temp = graph->adjLists[vertex];
    while (temp != NULL) {
        int adjVertex = temp->vertex;
        if (visited[adjVertex] == 0) {
            DFSUtil(graph, adjVertex, visited);
        }
        temp = temp->next;
    }
}

void DFS(struct Graph* graph, int startVertex) {
    int* visited = calloc(graph->numVertices, sizeof(int));
    DFSUtil(graph, startVertex, visited);
    free(visited);
}

int main() {
    int vertices, i = 0, m, src, dest, sp;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    struct Graph* graph = createGraph(vertices);
    while (1) {
        printf("1: Add edge 2: BFS 3: DFS 4: Exit\n");
        scanf("%d", &m);
        if (m == 1)
            {
            if (i < vertices )
            {
                printf("Enter the source and destination vertex: ");
                scanf("%d%d",&src,&dest);
                addEdge(graph,src,dest);
            }
            else
            {
                printf("Maximum number of vertices reached\n");
                exit(0);
            }
            }
            else if(m==2)
            {
                printf("ENter the point from where you want to start the BFS \n");
                scanf("%d",&sp);
                BFS(graph,sp);
            }
            else if(m==3)
            {
                printf("Enter the point from wehere you want to start the DFS\n");
                scanf("%d",&sp);
                DFS(graph,sp);
            }
            else if(m==4)
            {
                exit(0);
            }
            else
            {
                printf("Invalid choice\n");
            }
            i++;
        }
}
