#include <stdio.h>
#include <stdlib.h>  // For dynamic memory functions

// Structure to represent a node in BST
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));  // Allocate memory
    newNode->data = data;          // Set data
    newNode->left = NULL;          // Left child empty
    newNode->right = NULL;         // Right child empty
    return newNode;                // Return new node
}

// Insert a node into BST
Node* insert(Node* root, int data) {
    if (root == NULL)              // If tree is empty
        return createNode(data);   // Create and return new node

    if (data < root->data)         // If data less than root, go left
        root->left = insert(root->left, data);
    else if (data > root->data)    // If data greater, go right
        root->right = insert(root->right, data);

    return root;                   // Return unchanged root pointer
}

// Search key in BST recursively
Node* search(Node* root, int key) {
    if (root == NULL || root->data == key)  // If node empty or key found
        return root;                         // Return current node

    if (key < root->data)                    // If key smaller, search left
        return search(root->left, key);
    else                                    // Else search right
        return search(root->right, key);
}

int main() {
    Node* root = NULL;  // Start with empty BST
    int n, val, key;

    printf("How many values to insert? ");  // Ask how many nodes to add
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value: ");             // Ask for value
        scanf("%d", &val);
        root = insert(root, val);            // Insert into BST
    }

    printf("Enter value to search: ");      // Ask for search key
    scanf("%d", &key);

    if (search(root, key) != NULL)           // If found
        printf("Element %d found in the tree.\n", key);
    else
        printf("Element %d not found.\n", key);

    return 0;  // End program
}
