#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = createNode(data);
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue Underflow\n");
        return -1;
    } else {
        int data = queue->front->data;
        struct Node* temp = queue->front;
        queue->front = queue->front->next;
        if (queue->front == NULL) {
            queue->rear = NULL;
        }
        free(temp);
        return data;
    }
}

int peek(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is Empty\n");
        return -1;
    } else {
        return queue->front->data;
    }
}

int isEmpty(struct Queue* queue) {
    return queue->front == NULL;
}

int main() {
    struct Queue queue;
    queue.front = queue.rear = NULL;
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    printf("Dequeued element: %d\n", dequeue(&queue));
    printf("Peek element: %d\n", peek(&queue));
    return 0;
}
