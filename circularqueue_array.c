#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct CircularQueue {
    int data[MAX_SIZE];
    int front;
    int rear;
    int size;
};

void initQueue(struct CircularQueue *q) {
    q->front = 0;
    q->rear = 0;
    q->size = 0;
}

int enqueue(struct CircularQueue *q, int data) {
    if ((q->rear + 1) % MAX_SIZE == q->front) {
        printf("Queue is full\n");
        return -1;
    }
    q->data[q->rear] = data;
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->size++;
    return 0;
}

int dequeue(struct CircularQueue *q) {
    if (q->size == 0) {
        printf("Queue is empty\n");
        return -1;
    }
    int data = q->data[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    q->size--;
    return data;
}

int peek(struct CircularQueue *q) {
    if (q->size == 0) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->data[q->front];
}

int isEmpty(struct CircularQueue *q) {
    return q->size == 0;
}

int isFull(struct CircularQueue *q) {
    return (q->rear + 1) % MAX_SIZE == q->front;
}

void printQueue(struct CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    int i = q->front;
    for (int count = 0; count < q->size; count++) {
        printf("%d ", q->data[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}

int main() {
    struct CircularQueue q;
    initQueue(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);

    printf("Queue: ");
    printQueue(&q);

    printf("Dequeued element: %d\n", dequeue(&q));
    printf("Queue: ");
    printQueue(&q);

    printf("Front element: %d\n", peek(&q));

    return 0;
}

