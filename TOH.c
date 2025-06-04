#include <stdio.h>


void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
    // Base case: If there's only one disk, move it directly from source to destination
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }

    // Recursive case:
    // 1. Move top n-1 disks from source to auxiliary rod, using destination as auxiliary
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);

    // 2. Move the nth (largest) disk from source to destination rod
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);

    // 3. Move the n-1 disks from auxiliary rod to destination rod, using source as auxiliary
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

// Main function to drive the program
int main() {
    int n; // Variable to store the number of disks

    // Prompt the user to enter the number of disks
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // Display the steps to solve the Tower of Hanoi puzzle
    printf("Steps to solve the Tower of Hanoi puzzle with %d disks:\n", n);
    towerOfHanoi(n, 'A', 'C', 'B'); // A, B, and C are names of rods

    return 0;
}
