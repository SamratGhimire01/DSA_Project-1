#include <stdio.h>     
#include <stdlib.h>     // for malloc and free

// Define the structure for AVL tree nodes
typedef struct Node {
    int key;            // the value stored in the node
    struct Node* left;  // pointer to left child
    struct Node* right; // pointer to right child
    int height;         // height of the node (used to check balance)
} Node;

// Get maximum of two numbers
int max(int a, int b) {
    return (a > b) ? a : b; // return whichever is greater
}

// Get height of a node
int height(Node* n) {
    if (n == NULL)
        return 0; // null node has height 0
    return n->height; // otherwise return stored height
}

// Create a new node with given key
Node* newNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node)); // allocate memory
    node->key = key;       // set value
    node->left = NULL;     // no left child yet
    node->right = NULL;    // no right child yet
    node->height = 1;      // new node is initially a leaf (height 1)
    return node;
}

// Perform a right rotation to fix imbalance
Node* rightRotate(Node* y) {
    Node* x = y->left;        // x becomes new root
    Node* T2 = x->right;      // hold temporary right child

    x->right = y;             // rotate
    y->left = T2;

    // update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x; // return new root
}

// Perform a left rotation to fix imbalance
Node* leftRotate(Node* x) {
    Node* y = x->right;       // y becomes new root
    Node* T2 = y->left;       // hold temporary left child

    y->left = x;              // rotate
    x->right = T2;

    // update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y; // return new root
}

// Get the balance factor of a node
int getBalance(Node* n) {
    if (n == NULL)
        return 0; // no node = balanced
    return height(n->left) - height(n->right); // left - right height
}

// Insert a key into the AVL tree and balance it
Node* insert(Node* node, int key) {
    if (node == NULL)
        return newNode(key); // insert new node here

    if (key < node->key)            // go left if key is smaller
        node->left = insert(node->left, key);
    else if (key > node->key)       // go right if key is bigger
        node->right = insert(node->right, key);
    else
        return node; // duplicates not allowed

    // update the height of the current node
    node->height = 1 + max(height(node->left), height(node->right));

    // get the balance factor to check if node is unbalanced
    int balance = getBalance(node);

    // Now fix the imbalance if it occurred

    // Case 1 - Left Left (rotate right)
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Case 2 - Right Right (rotate left)
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Case 3 - Left Right (left rotate left child, then right rotate)
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);  // step 1
        return rightRotate(node);             // step 2
    }

    // Case 4 - Right Left (right rotate right child, then left rotate)
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right); // step 1
        return leftRotate(node);                // step 2
    }

    return node; // return the unchanged node pointer
}

// In-order traversal to print sorted values
void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);              // go left
        printf("%d ", root->key);         // print value
        inOrder(root->right);             // go right
    }
}

// Main function to test AVL insertion
int main() {
    Node* root = NULL;                            // start with an empty tree
    int keys[] = {10, 20, 30, 40, 50, 25};        // values to insert
    int n = sizeof(keys) / sizeof(keys[0]);       // find number of values

    for (int i = 0; i < n; i++) {
        root = insert(root, keys[i]);             // insert into AVL tree
        printf("Inserted %d. In-order: ", keys[i]);
        inOrder(root);                            // print tree after each insertion
        printf("\n");
    }

    return 0; // end program
}
