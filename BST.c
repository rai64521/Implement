#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert node in BST
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Function to search node in BST
struct Node* searchNode(struct Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    } else if (data < root->data) {
        return searchNode(root->left, data);
    } else {
        return searchNode(root->right, data);
    }
}

// Function to find minimum value node in BST
struct Node* findMinNode(struct Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete node from BST
struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) {
        return root;
    } else if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        } else if (root->left == NULL) {
            struct Node* temp = root;
            root = root->right;
            free(temp);
        } else if (root->right == NULL) {
            struct Node* temp = root;
            root = root->left;
            free(temp);
        } else {
            struct Node* temp = findMinNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

// Function to print inorder traversal of BST
void printInorder(struct Node* root) {
    if (root != NULL) {
        printInorder(root->left);
        printf("%d ", root->data);
        printInorder(root->right);
    }
}

// Function to print preorder traversal of BST
void printPreorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        printPreorder(root->left);
        printPreorder(root->right);
    }
}

// Function to print postorder traversal of BST
void printPostorder(struct Node* root) {
    if (root != NULL) {
        printPostorder(root->left);
        printPostorder(root->right);
        printf("%d ", root->data);
    }
}

// Function to print level order traversal of BST
void printLevelOrder(struct Node* root) {
    if (root == NULL) {
        return;
    }

    struct Node** queue = (struct Node**)malloc(100 * sizeof(struct Node*));
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        struct Node* temp = queue[front++];
        printf("%d ", temp->data);

        if (temp->left != NULL) {
            queue[rear++] = temp->left;
        }

        if (temp->right != NULL) {
            queue[rear++] = temp->right;
        }
    }
}

int main() {
    struct Node* root = NULL;

    // Insert nodes
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    // Print inorder traversal
    printf("Inorder Traversal: ");
    printInorder(root);
    printf("\n");

    // Print preorder traversal
    printf("Preorder Traversal: ");
    printPreorder(root);
    printf("\n");

    // Print postorder traversal
    printf("Postorder Traversal: ");
    printPostorder(root);

    return 0;
}