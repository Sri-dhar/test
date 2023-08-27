#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct {
    int vertices[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
} Graph;

void createGraph(Graph *g) {
    int i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &g->numVertices);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < g->numVertices; i++) {
        for (j = 0; j < g->numVertices; j++) {
            scanf("%d", &g->vertices[i][j]);
        }
    }
}

void DFSUtil(Graph *g, int vertex, int visited[]) {
    printf("%d ", vertex);
    visited[vertex] = 1;

    int i;
    for (i = 0; i < g->numVertices; i++) {
        if (g->vertices[vertex][i] == 1 && !visited[i]) {
            DFSUtil(g, i, visited);
        }
    }
}

void DFS(Graph *g, int startVertex) {
    int visited[MAX_VERTICES] = {0};

    printf("DFS traversal starting from vertex %d: ", startVertex);
    DFSUtil(g, startVertex, visited);

    printf("\n");
}

int main() {
    Graph g;
    int startVertex;

    createGraph(&g);

    printf("Enter the starting vertex for DFS traversal: ");
    scanf("%d", &startVertex);

    DFS(&g, startVertex);

    return 0;
}

//input
/*
0 1 1 0 0 0
1 0 0 1 0 0
1 0 0 1 1 0
0 1 1 0 0 1
0 0 1 0 0 1
0 0 0 1 1 0
*/