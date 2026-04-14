#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

struct Edge {
    int weight;
    struct Vertex *dest;
    struct Edge *next;
};

struct Vertex {
    char name[50];
    struct Edge *edge;
};

struct Graph {
    struct Vertex vertices[MAX];
    int numVertices;
};

void saveGraph(struct Graph *g, char filename[]) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error opening file\n");
        return;
    }
    fprintf(file, "%d\n", g->numVertices);
    for (int i = 0; i < g->numVertices; i++) {
        fprintf(file, "%s\n", g->vertices[i].name);
        struct Edge *curr = g->vertices[i].edge;
        while (curr) {
            fprintf(file, "%d %s\n", curr->weight, curr->dest->name);
            curr = curr->next;
        }
        fprintf(file, "NULL\n");
    }
    fclose(file);
}

void loadGraph(struct Graph *g, char filename[]) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file\n");
        return;
    }
    fscanf(file, "%d", &g->numVertices);
    for (int i = 0; i < g->numVertices; i++) {
        fscanf(file, "%s", g->vertices[i].name);
        g->vertices[i].edge = NULL;
    }
    // Simplified loading (full version needs linking)
    fclose(file);
}

int main() {
    struct Graph g;
    char filename[100];
    printf("Enter filename to save graph: ");
    scanf("%s", filename);
    // Assume graph is initialized elsewhere
    saveGraph(&g, filename);
    printf("Graph saved to %s\n", filename);
    return 0;
}