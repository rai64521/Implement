#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int coefficient;
    int exponent;
    struct Node* next;
};

// Linked list structure
struct LinkedList {
    struct Node* head;
};

// Function to create new node
struct Node* createNode(int coefficient, int exponent) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;
    return newNode;
}

// Function to append node to linked list
void append(struct LinkedList* list, int coefficient, int exponent) {
    struct Node* newNode = createNode(coefficient, exponent);
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        struct Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to print polynomial
void printPolynomial(struct LinkedList* list) {
    struct Node* current = list->head;
    while (current != NULL) {
        printf("%dx^%d + ", current->coefficient, current->exponent);
        current = current->next;
    }
    printf("0\n");
}

// Function to add polynomials
struct LinkedList* addPolynomials(struct LinkedList* poly1, struct LinkedList* poly2) {
    struct LinkedList* result = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    result->head = NULL;
    struct Node* current1 = poly1->head;
    struct Node* current2 = poly2->head;

    while (current1 != NULL && current2 != NULL) {
        if (current1->exponent == current2->exponent) {
            append(result, current1->coefficient + current2->coefficient, current1->exponent);
            current1 = current1->next;
            current2 = current2->next;
        } else if (current1->exponent > current2->exponent) {
            append(result, current1->coefficient, current1->exponent);
            current1 = current1->next;
        } else {
            append(result, current2->coefficient, current2->exponent);
            current2 = current2->next;
        }
    }

    while (current1 != NULL) {
        append(result, current1->coefficient, current1->exponent);
        current1 = current1->next;
    }

    while (current2 != NULL) {
        append(result, current2->coefficient, current2->exponent);
        current2 = current2->next;
    }

    return result;
}

int main() {
    // Create polynomials
    struct LinkedList poly1;
    poly1.head = NULL;
    append(&poly1, 2, 2);
    append(&poly1, 3, 1);
    append(&poly1, 1, 0);

    struct LinkedList poly2;
    poly2.head = NULL;
    append(&poly2, 1, 2);
    append(&poly2, -2, 1);
    append(&poly2, -3, 0);

    // Print polynomials
    printf("Polynomial 1: ");
    printPolynomial(&poly1);
    printf("Polynomial 2: ");
    printPolynomial(&poly2);

    // Add polynomials
    struct LinkedList* result = addPolynomials(&poly1, &poly2);

    // Print result
    printf("Resultant Polynomial: ");
    printPolynomial(result);

    return 0;
}
