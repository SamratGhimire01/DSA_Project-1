#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100  // Max number of elements in heap

int heap[MAX_SIZE];  // Array to store heap elements
int size = 0;        // Current number of elements in heap

// Swap two integers by pointer
void swap(int *a, int *b) {
    int temp = *a;  
    *a = *b;      
    *b = temp;
}

// Heapify subtree rooted at index i (make sure max heap property is maintained)
void heapify(int arr[], int n, int i) {
    int largest = i;             // Assume current node is largest
    int left = 2 * i + 1;        // Left child index
    int right = 2 * i + 2;       // Right child index

    if (left < n && arr[left] > arr[largest])  // If left child bigger
        largest = left;

    if (right < n && arr[right] > arr[largest]) // If right child bigger
        largest = right;

    if (largest != i) {          // If largest not root, swap and heapify again
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// Build max heap from an unsorted array
void build_max_heap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)  // Start from last non-leaf node
        heapify(arr, n, i);                // Heapify each node
}

// Insert value into heap and maintain max heap property
void insert(int value) {
    if (size >= MAX_SIZE) {            // Check if heap full
        printf("Heap is full.\n");
        return;
    }

    heap[size] = value;                // Insert at end of heap
    int current = size;                // Track current index
    size++;                           // Increase heap size

    // Bubble up new element until heap property restored
    while (current > 0 && heap[current] > heap[(current - 1) / 2]) {
        swap(&heap[current], &heap[(current - 1) / 2]);
        current = (current - 1) / 2;  // Move up to parent index
    }
}

// Display all elements in the heap
void display() {
    printf("Heap elements:\n");
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    int choice, value, n;

    do {
        printf("\n--- HEAP MENU ---\n");
        printf("1. Build Heap from Array\n2. Insert Element\n3. Display Heap\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Enter number of elements: ");
                scanf("%d", &n);
                int arr[n];
                printf("Enter %d elements:\n", n);
                for (int i = 0; i < n; i++)
                    scanf("%d", &arr[i]);
                build_max_heap(arr, n);
                printf("Max heap built successfully.\n");
                break;
            }
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                printf("Value inserted.\n");
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}
