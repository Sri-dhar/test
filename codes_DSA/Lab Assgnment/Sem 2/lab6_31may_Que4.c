#include <stdio.h>
#define SIZE 10

struct CircularQueue {
    int items[SIZE];
    int front;
    int rear;
};

void enqueue(struct CircularQueue* queue, int data) {
    if ((queue->rear + 1) % SIZE == queue->front) {
        printf("The circular queue is full.\n");
    } else {
        queue->rear = (queue->rear + 1) % SIZE;
        queue->items[queue->rear] = data;
        printf("Enqueued the element %d at position %d.\n", data, queue->rear);
    }
}

void dequeue(struct CircularQueue* queue, int position) {
    if (queue->front == queue->rear) {
        printf("The circular queue is empty.\n");
    } else if (position < 1 || position > SIZE) {
        printf("Invalid position.\n");
    } else {
        int index = queue->front;
        for (int i = 1; i < position; i++) {
            index = (index + 1) % SIZE;
        }
        printf("Dequeued the element %d from position %d.\n", queue->items[index], index);
        queue->items[index] = 0;
    }
}

void displayQueue(struct CircularQueue* queue) {
    if (queue->front == queue->rear) {
        printf("The circular queue is empty.\n");
    } else {
        int index = queue->front;
        printf("Elements in the circular queue: ");
        while (index != queue->rear) {
            index = (index + 1) % SIZE;
            printf("%d ", queue->items[index]);
        }
        printf("\n");
    }
}

int main() {
    struct CircularQueue queue;
    queue.front = 0;
    queue.rear = 0;

    int size;
    printf("Enter the size of the circular queue: ");
    scanf("%d", &size);
    printf("\n");
    if (size > SIZE || size < 1) {
        printf("Invalid size. The size should be between 1 and %d.\n", SIZE);
        return 0;
    }
    
    int data;
    printf("Enter the elements of the circular queue:\n");

    int pos, val, inp;

    while (1) {
        printf("Enter 1 to enqueue, 0 to dequeue, 2 to display, or 3 to exit: ");
        scanf("%d", &inp);

        if (inp == 3) {
            break;
        } else if (inp == 1) { printf("\n");
            printf("Enter the position you want to enqueue at: "); printf("\n");
            scanf("%d", &pos);
            printf("Enter the value you want to enqueue: "); printf("\n");
            scanf("%d", &val);
            enqueue(&queue, val);
        } else if (inp == 0) { printf("\n");
            printf("Enter the position you want to dequeue at: "); printf("\n");
            scanf("%d", &pos);
            dequeue(&queue, pos);
        } else if (inp == 2) { printf("\n");
            displayQueue(&queue); printf("\n");
        } else {
            printf("Invalid input. Try again.\n"); printf("\n");
        }
    }

    int position;
    printf("Enter the position to dequeue an element: "); printf("\n");
    scanf("%d", &position);

    dequeue(&queue, position);

    return 0;
}
