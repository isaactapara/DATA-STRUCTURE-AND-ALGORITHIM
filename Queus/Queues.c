/*
 * BSE-05-0065-2024 ISAACK TAPARA
 * Implementation of simple queue in C using arrays
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
    int items[MAX];
    int front, rear;
} Queue;

// Initialize the queue
void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is empty
int isEmpty(Queue *q) {
    return q->front == -1;
}

// Check if the queue is full
int isFull(Queue *q) {
    return (q->rear + 1) % MAX == q->front;
}

// Enqueue an element
int enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return 0;
    }
    if (isEmpty(q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX;
    }
    q->items[q->rear] = value;
    return 1;
}

// Dequeue an element
int dequeue(Queue *q, int *value) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return 0;
    }
    *value = q->items[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
    return 1;
}

// Display the queue
void displayQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue: ");
    int i = q->front;
    while (1) {
        printf("%d ", q->items[i]);
        if (i == q->rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// Example usage
int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    displayQueue(&q);

    int value;
    dequeue(&q, &value);
    printf("Dequeued: %d\n", value);

    displayQueue(&q);

    return 0;
}