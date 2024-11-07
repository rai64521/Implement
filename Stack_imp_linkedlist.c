#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(struct Stack* stack, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(struct Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        int data = stack->top->data;
        struct Node* temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
        return data;
    }
}

int peek(struct Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is Empty\n");
        return -1;
    } else {
        return stack->top->data;
    }
}

int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

int main() {
    struct Stack stack;
    stack.top = NULL;
    push(&stack, 100);
    push(&stack, 200);
    push(&stack, 500);
    printf("Popped element: %d\n", pop(&stack));
    printf("Peek element: %d\n", peek(&stack));
    return 0;
}
