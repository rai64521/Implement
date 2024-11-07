#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct CircularQueue {
    struct Node* front;
    struct Node* rear;
};

void initQueue(struct CircularQueue *q) {
    q->front = NULL;
    q->rear = NULL;
}

void enqueue(struct CircularQueue *q, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        newNode->next = q->front;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
        q->rear->next = q->front;
    }
}

int dequeue(struct CircularQueue *q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }

    int data = q->front->data;
    struct Node* temp = q->front;
    q->front = q->front->next;
    q->rear->next = q->front;

    if (q->front == q->rear) {
        q->front = q->rear = NULL;
    }

    free(temp);
    return data;
}

int peek(struct CircularQueue *q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->front->data;
}

int isEmpty(struct CircularQueue *q) {
    return q->front == NULL;
}

void printQueue(struct CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    struct Node* temp = q->front;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != q->front);
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
