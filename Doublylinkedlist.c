#include <stdio.h>
#include <stdlib.h>

// Node structure for Doubly Linked List
typedef struct DNode {
    int data;
    struct DNode* prev;
    struct DNode* next;
} DNode;

// Insert a new node at the beginning
void insertAtStart(DNode** head, int data) {
    DNode* newNode = (DNode*)malloc(sizeof(DNode));  // Allocate memory for new node
    newNode->data = data;                            // Assign data
    newNode->prev = NULL;                            // New node's prev points to NULL (first node)
    newNode->next = *head;                           // New node's next points to current head

    if (*head != NULL) {
        (*head)->prev = newNode;  // Update current head's prev to new node
    }
    *head = newNode;              // Update head to new node
}

// Insert a new node at the end
void insertAtEnd(DNode** head, int data) {
    DNode* newNode = (DNode*)malloc(sizeof(DNode));  // Allocate memory for new node
    newNode->data = data;                            // Assign data
    newNode->next = NULL;                            // New node's next points to NULL (last node)

    if (*head == NULL) {  // If list is empty
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    DNode* temp = *head;
    while (temp->next != NULL) {  // Traverse to the last node
        temp = temp->next;
    }
    temp->next = newNode;  // Link last node to new node
    newNode->prev = temp;  // New node's prev points to last node
}

// Delete the first node
void deleteFromStart(DNode** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    DNode* temp = *head;         // Store current head
    *head = (*head)->next;       // Update head to next node
    if (*head != NULL) {
        (*head)->prev = NULL;    // Update new head's prev to NULL
    }
    free(temp);                  // Free memory of old head
}

// Delete the last node
void deleteFromEnd(DNode** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    DNode* temp = *head;
    while (temp->next != NULL) {  // Traverse to the last node
        temp = temp->next;
    }

    if (temp->prev == NULL) {     // Only one node in list
        *head = NULL;
    } else {
        temp->prev->next = NULL;  // Update second last node's next to NULL
    }
    free(temp);                   // Free memory of last node
}

// Display the linked list
void display(DNode* head) {
    while (head != NULL) {
        printf("%d <-> ", head->data);  // Print current node's data
        head = head->next;              // Move to next node
    }
    printf("NULL\n");                   // Mark end of list
}

int main() {
    DNode* head = NULL;
    int choice, data;

    do {
        printf("\n--- DOUBLY LINKED LIST OPERATIONS ---\n");
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