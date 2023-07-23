#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void deleteTree(struct Node* root) {
    if (root == NULL)
        return;

    deleteTree(root->left);
    deleteTree(root->right);

    free(root);
}

int main() {
    struct Node* root = NULL;

    int numElements;
    printf("Enter the number of elements in the tree: ");
    scanf("%d", &numElements);

    printf("Enter the elements:\n");
    for (int i = 0; i < numElements; i++) {
        int data;
        scanf("%d", &data);


        struct Node* newNode = createNode(data);


        if (root == NULL) {
            root = newNode;
        } else {

            struct Node* current = root;
            struct Node* parent;

            while (1) {
                parent = current;

                // If the new data is less than the current node's data, go to the left subtree
                if (data < current->data) {
                    current = current->left;

                    // If the left child is NULL, insert the new node here
                    if (current == NULL) {
                        parent->left = newNode;
                        break;
                    }
                } else {
                    current = current->right;


                    if (current == NULL) {
                        parent->right = newNode;
                        break;
                    }
                }
            }
        }
    }


    deleteTree(root);

    printf("Tree deleted successfully.\n");

    return 0;
}

