#include <stdio.h>  // Include standard input/output functions

// Function to search for key in array using linear search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {  // Go through each element in the array
        if (arr[i] == key) {       // Check if current element matches the key
            return i;              // If found, return the index
        }
    }
    return -1;  // If not found, return -1
}

int main() {
    int arr[] = {12, 45, 2, 9, 34, 78};  // Array to search in
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate number of elements in array
    int key;

    printf("Enter number to search: ");  // Ask user for the number to find
    scanf("%d", &key);                   // Read the number from user

    int index = linearSearch(arr, n, key); // Call linear search function
    if (index != -1)                      // If element found
        printf("Element found at index %d\n", index); // Print index
    else
        printf("Element not found\n");   // Otherwise print not found

    return 0;  // End program
}
