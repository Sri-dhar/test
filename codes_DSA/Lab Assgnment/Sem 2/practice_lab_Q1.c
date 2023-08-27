#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct {
    int items[MAX_VERTICES];
    int front;
    int rear;
} Queue;

typedef struct {
    int vertices[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
} Graph;

void enqueue(Queue *q, int value) {
    q->items[q->rear++] = value;
}

int dequeue(Queue *q) {
    return q->items[q->front++];
}

int isEmpty(Queue *q) {
    return q->front == q->rear;
}

void createGraph(Graph *g) {
    int i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &g->numVertices);

    for (i = 0; i < g->numVertices; i++) {
        for (j = 0; j < g->numVertices; j++) {
            g->vertices[i][j] = 0;
        }
    }

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < g->numVertices; i++) {
        for (j = 0; j < g->numVertices; j++) {
            scanf("%d", &g->vertices[i][j]);
        }
    }
}

void BFS(Graph *g, int startVertex) {
    int visited[MAX_VERTICES] = {0};
    Queue q;

    printf("BFS traversal starting from vertex %d: ", startVertex);

    visited[startVertex] = 1;
    enqueue(&q, startVertex);

    while (!isEmpty(&q)) {
        int currentVertex = dequeue(&q);
        printf("%d ", currentVertex);

        int i;
        for (i = 0; i < g->numVertices; i++) {
            if (g->vertices[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(&q, i);
            }
        }
    }
    printf("\n");
}

int main() {
    Graph g;
    int startVertex;

    createGraph(&g);

    printf("Enter the starting vertex for BFS traversal: ");
    scanf("%d", &startVertex);

    BFS(&g, startVertex);

    return 0;
}
