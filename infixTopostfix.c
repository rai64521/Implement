#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int precedence(char c) {
    switch (c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int isEmpty() {
    return top == -1;
}

void infixToPostfix(char *infix, char *postfix) {
    int i = 0, j = 0;
    while (infix[i] != '\0') {
        if (isalpha(infix[i])) {
            postfix[j++] = infix[i++];
        } else if (infix[i] == '(') {
            push(infix[i++]);
        } else if (infix[i] == ')') {
            while (!isEmpty() && stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop();
            i++;
        } else if (isOperator(infix[i])) {
            while (!isEmpty() && precedence(stack[top]) >= precedence(infix[i])) {
                postfix[j++] = pop();
            }
            push(infix[i++]);
        } else {
            i++; // Skip any whitespace or unrecognized characters
        }
    }
    while (!isEmpty()) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];
    printf("Enter infix expression: ");
    fgets(infix, MAX_SIZE, stdin);  // Use fgets to read the entire line
    infix[strcspn(infix, "\n")] = '\0';  // Remove newline character at the end
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
