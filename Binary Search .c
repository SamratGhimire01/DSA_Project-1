#include <stdio.h>  // Include standard input/output

// Function to do binary search in a sorted array
int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {  // While the search space is valid
        int mid = low + (high - low) / 2;  // Find the middle index

        if (arr[mid] == key)                // If middle element is key
            return mid;                    // Return index
        else if (arr[mid] < key)           // If key is bigger, ignore left half
            low = mid + 1;                 // Search right half
        else                              // Otherwise ignore right half
            high = mid - 1;               // Search left half
    }
    return -1;  // Key not found
}

int main() {
    int arr[] = {5, 10, 15, 20, 25, 30};  // Sorted array
    int n = sizeof(arr) / sizeof(arr[0]); // Number of elements
    int key;

    printf("Enter number to search: ");  // Ask for key
    scanf("%d", &key);                   // Read key

    int index = binarySearch(arr, 0, n - 1, key);  // Call binary search
    if (index != -1)                      // If found
        printf("Element found at index %d\n", index);  // Print index
    else
        printf("Element not found\n");   // Else print not found

    return 0;  // End program
}
