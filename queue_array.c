#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int queue[MAX_SIZE];
int front = 0;
int rear = 0;

// Enqueue operation
void enqueue(int data) {
    if (rear == MAX_SIZE) {
        printf("Queue Overflow\n");
    } else {
        queue[rear++] = data;
    }
}

// Dequeue operation
int dequeue() {
    if (front == rear) {
        printf("Queue Underflow\n");
        return -1;
    } else {
        return queue[front++];
    }
}

// Peek operation
int peek() {
    if (front == rear) {
        printf("Queue is Empty\n");
        return -1;
    } else {
        return queue[front];
    }
}

// IsEmpty operation
int isEmpty() {
    return front == rear;
}

// IsFull operation
int isFull() {
    return rear == MAX_SIZE;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    printf("Dequeued element: %d\n", dequeue());
    printf("Peek element: %d\n", peek());
  
    return 0;
}
