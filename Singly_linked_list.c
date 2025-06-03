#include <stdio.h>
#include <stdlib.h>

// Node structure for Singly Linked List
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Insert a new node at the beginning
void insertAtStart(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));  // Allocate memory for new node
    newNode->data = data;                         // Assign data
    newNode->next = *head;                        // Point new node to current head
    *head = newNode;                              // Update head to new node
}

// Insert a new node at the end
void insertAtEnd(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));  // Allocate memory for new node
    newNode->data = data;                         // Assign data
    newNode->next = NULL;                         // New node points to NULL (end of list)

    if (*head == NULL) {
        *head = newNode;  // If list is empty, new node becomes head
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL) {  // Traverse to the last node
        temp = temp->next;
    }
    temp->next = newNode;         // Link last node to new node
}

// Delete the first node
void deleteFromStart(Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = *head;   // Store current head
    *head = (*head)->next; // Update head to next node
    free(temp);            // Free memory of old head
}

// Delete the last node
void deleteFromEnd(Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if ((*head)->next == NULL) {  // Only one node in list
        free(*head);
        *head = NULL;
        return;
    }

    Node* secondLast = *head;
    while (secondLast->next->next != NULL) {  // Traverse to second last node
        secondLast = secondLast->next;
    }
    free(secondLast->next);      // Free memory of last node
    secondLast->next = NULL;     // Update second last node to point to NULL
}

// Display the linked list
void display(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);  // Print current node's data
        head = head->next;              // Move to next node
    }
    printf("NULL\n");                   // Mark end of list
}

int main() {
    Node* head = NULL;
    int choice, data;

    do {
        printf("\n--- SINGLY LINKED LIST OPERATIONS ---\n");
        printf("1. Insert at Beginning\n2. Insert at End\n3. Delete from Beginning\n4. Delete from End\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtStart(&head, data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                deleteFromStart(&head);
                break;
            case 4:
                deleteFromEnd(&head);
                break;
            case 5:
                display(head);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid input!\n");
        }
    } while (choice != 6);

    return 0;
}