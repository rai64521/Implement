#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int stack[MAX_SIZE];
int top = -1;

// Push operation
void push(int data) {
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = data;
    }
}

// Pop operation
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}

// Peek operation
int peek() {
    if (top == -1) {
        printf("Stack is Empty\n");
        return -1;
    } else {
        return stack[top];
    }
}

// IsEmpty operation
int isEmpty() {
    return top == -1;
}

// IsFull operation
int isFull() {
    return top == MAX_SIZE - 1;
}

int main() {
    push(10);
    push(20);
    push(30);
    printf("Popped element: %d\n", pop());
    printf("Peek element: %d\n", peek());
    return 0;
}