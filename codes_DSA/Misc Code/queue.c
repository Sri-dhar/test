#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct {
    int* arr;
    int front;
    int rear;
    int size;
} CircularQueue;

CircularQueue* createCircularQueue() {
    CircularQueue* queue = (CircularQueue*)malloc(sizeof(CircularQueue));
    queue->arr = (int*)malloc(MAX_SIZE * sizeof(int));
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
    return queue;
}

int isEmpty(CircularQueue* queue) {
    return (queue->size == 0);
}

int isFull(CircularQueue* queue) {
    return (queue->size == MAX_SIZE);
}

void enqueue(CircularQueue* queue, int data) {
    if (isFull(queue)) {
        printf("Error: Queue is full.\n");
        return;
    }

    if (isEmpty(queue)) {
        queue->front = 0;
    }

    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->arr[queue->rear] = data;
    queue->size++;
    printf("Enqueued element: %d\n", data);
}

int dequeue(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Error: Queue is empty.\n");
        return -1;
    }

    int data = queue->arr[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
    queue->size--;
    return data;
}

void displayQueue(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Current Queue: ");
    int i;
    for (i = queue->front; i != queue->rear; i = (i + 1) % MAX_SIZE) {
        printf("%d ", queue->arr[i]);
    }
    printf("%d\n", queue->arr[i]);
}

void freeCircularQueue(CircularQueue* queue) {
    free(queue->arr);
    free(queue);
}

int main() {
    CircularQueue* queue = createCircularQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50); // Queue is full

    displayQueue(queue);

    int item = dequeue(queue);
    printf("Dequeued element: %d\n", item);

    displayQueue(queue);

    enqueue(queue, 60);
    enqueue(queue, 70);

    displayQueue(queue);

    freeCircularQueue(queue);

    return 0;
}
