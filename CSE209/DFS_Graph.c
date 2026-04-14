#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int visited[MAX];

struct Node {
    int data;
    struct Node *next;
};

struct Graph {
    int numVertices;
    struct Node **adjLists;
};

struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Graph *createGraph(int vertices) {
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = (struct Node **)malloc(vertices * sizeof(struct Node *));
    for (int i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;
    return graph;
}

void addEdge(struct Graph *graph, int src, int dest) {
    struct Node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void DFS(struct Graph *graph, int vertex) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    struct Node *temp = graph->adjLists[vertex];
    while (temp) {
        int adj = temp->data;
        if (!visited[adj])
            DFS(graph, adj);
        temp = temp->next;
    }
}

int main() {
    int vertices, edges, src, dest, start;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    struct Graph *graph = createGraph(vertices);
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    for (int i = 0; i < edges; i++) {
        printf("Enter source and destination: ");
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }
    printf("Enter start vertex: ");
    scanf("%d", &start);
    for (int i = 0; i < vertices; i++)
        visited[i] = 0;
    printf("DFS: ");
    DFS(graph, start);
    printf("\n");
    return 0;
}