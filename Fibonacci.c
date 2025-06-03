#include <stdio.h>

// Recursive function to calculate nth Fibonacci number
int fibonacci(int n) {
    if (n == 0) return 0;       // Base case: F(0) = 0
    else if (n == 1) return 1;  // Base case: F(1) = 1
    else 
        return fibonacci(n - 1) + fibonacci(n - 2);  // Recursive call: F(n) = F(n-1) + F(n-2)
}

int main() {
    int n, i;
    printf("Enter number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci Series: ");
    for (i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));  // Print each term in the series
    }
    return 0;
}