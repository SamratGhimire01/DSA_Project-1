
#include <stdio.h>
#define MAX 100

int queue[MAX];         // Array to use as queue for BFS
int front = -1, rear = -1; // Queue pointers

// Function to add element to queue
void enqueue(int vertex) {
    if (rear == MAX - 1)
        return;         // Queue is full
    if (front == -1)
        front = 0;      // Set front to 0 if queue was empty
    queue[++rear] = vertex; // Add vertex to queue
}

// Function to remove element from queue
int dequeue() {
    if (front == -1 || front > rear)
        return -1;      // Queue is empty
    return queue[front++]; // Remove and return front element
}

// Function to perform BFS traversal
void BFS(int adj[MAX][MAX], int n, int start) {
    int visited[MAX] = {0}; // Array to mark visited vertices

    enqueue(start);         // Start BFS from 'start' vertex
    visited[start] = 1;     // Mark as visited

    while (front != -1 && front <= rear) {
        int current = dequeue(); // Get next vertex from queue
        printf("%d ", current);  // Print the vertex

        // Visit all adjacent vertices
        for (int i = 0; i < n; i++) {
            if (adj[current][i] == 1 && !visited[i]) {
                enqueue(i);      // Add to queue if not visited
                visited[i] = 1;  // Mark as visited
            }
        }
    }
}

int main() {
    int n;                      // Number of vertices
    int adj[MAX][MAX];          // Adjacency matrix
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]); // Read adjacency matrix

    int start;
    printf("Enter starting vertex (0-based index): ");
    scanf("%d", &start);

    printf("BFS Traversal: ");
    BFS(adj, n, start);         // Call BFS function
    printf("\n");
    return 0;
}
