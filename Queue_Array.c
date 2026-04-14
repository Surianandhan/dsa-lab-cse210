#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int front, rear;
} Queue;

void createQueue(Queue *q) {
    q->front = q->rear = -1;
}

int isEmpty(Queue *q) {
    return q->front == -1;
}

int isFull(Queue *q) {
    return q->rear == MAX_SIZE - 1;
}

void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow\n");
        return;
    }
    if (isEmpty(q))
        q->front = 0;
    q->rear++;
    q->data[q->rear] = value;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return -1;
    }
    int value = q->data[q->front];
    if (q->front == q->rear)
        createQueue(q);
    else
        q->front++;
    return value;
}

int main() {
    Queue q;
    createQueue(&q);
    int choice, data;
    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                enqueue(&q, data);
                break;
            case 2:
                data = dequeue(&q);
                if (data != -1)
                    printf("Dequeued: %d\n", data);
                break;
            case 3:
                printf("Exiting\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 3);
    return 0;
}