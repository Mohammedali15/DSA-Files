#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to perform in-order traversal and find the kth smallest element
int kthSmallest(struct Node* root, int k) {
    // Stack to store the nodes during traversal
    struct Node* stack[100];
    int top = -1;
    int count = 0;
    struct Node* current = root;

    while (current != NULL || top != -1) {
        // Reach the leftmost node of the current subtree
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }

        current = stack[top--];
        count++;

        // If kth smallest element is found, return its value
        if (count == k) {
            return current->data;
        }

        current = current->right;
    }

    // If k is greater than the total number of elements in the BST
    return -1;
}

// Function to insert a node into the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// Function to create a BST based on user input
struct Node* createBST() {
    struct Node* root = NULL;
    int data;
    char choice;

    do {
        printf("Enter a number: ");
        scanf("%d", &data);

        root = insert(root, data);

        printf("Do you want to enter another number? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return root;
}

// Test the code
int main() {
    struct Node* root = createBST();

    int k;
    printf("Enter the value of k: ");
    scanf("%d", &k);

    int kthSmallestElement = kthSmallest(root, k);

    if (kthSmallestElement != -1) {
        printf("The %dth smallest element in the BST is: %d\n", k, kthSmallestElement);
    } else {
        printf("Invalid value of k!\n");
    }

    return 0;
}

