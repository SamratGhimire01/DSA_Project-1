
#include <stdio.h>
#define MAX 100

// DFS traversal function
void DFS(int adj[MAX][MAX], int n, int v, int visited[MAX]) {
    printf("%d ", v);      // Print the current vertex
    visited[v] = 1;        // Mark as visited

    // Visit all adjacent vertices
    for (int i = 0; i < n; i++) {
        if (adj[v][i] && !visited[i]) {
            DFS(adj, n, i, visited); // Recursively visit neighbors
        }
    }
}

int main() {
    int n, adj[MAX][MAX], visited[MAX] = {0}, start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]); // Read adjacency matrix

    printf("Enter starting vertex (0-based index): ");
    scanf("%d", &start);

    printf("DFS Traversal: ");
    DFS(adj, n, start, visited); // Call DFS
    printf("\n");
    return 0;
}
