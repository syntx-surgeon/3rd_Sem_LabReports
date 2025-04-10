//Doubly Linked List
#include <stdio.h>
#include <stdlib.h>

// Structure for doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function prototypes
void insertAtEnd(struct Node** head, int value);  // Helper function for initial list creation
void deleteFromBeginning(struct Node** head);
void deleteFromEnd(struct Node** head);
void deleteFromPosition(struct Node** head, int position);
void displayList(struct Node* head);
int getLength(struct Node* head);

// Main function
int main() {
    struct Node* head = NULL;
    int choice, value, position;
    
    // Initial list creation for demonstration
    printf("Creating initial list for demonstration...\n");
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    displayList(head);
    
    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Delete from Beginning\n");
        printf("2. Delete from End\n");
        printf("3. Delete from Specified Position\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                deleteFromBeginning(&head);
                break;
                
            case 2:
                deleteFromEnd(&head);
                break;
                
            case 3:
                printf("Enter position to delete (0-based index): ");
                scanf("%d", &position);
                deleteFromPosition(&head, position);
                break;
                
            case 4:
                displayList(head);
                break;
                
            case 5:
                printf("Exiting program...\n");
                // Free remaining nodes
                while (head != NULL) {
                    struct Node* temp = head;
                    head = head->next;
                    free(temp);
                }
                return 0;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Helper function to insert at end (for initial list creation)
void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    
    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }
    
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Delete from beginning
void deleteFromBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty! Cannot delete.\n");
        return;
    }
    
    struct Node* temp = *head;
    *head = (*head)->next;
    
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    
    printf("Deleted node with value %d from beginning.\n", temp->data);
    free(temp);
}

// Delete from end
void deleteFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty! Cannot delete.\n");
        return;
    }
    
    struct Node* temp = *head;
    if (temp->next == NULL) {
        *head = NULL;
        printf("Deleted node with value %d from end.\n", temp->data);
        free(temp);
        return;
    }
    
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->prev->next = NULL;
    printf("Deleted node with value %d from end.\n", temp->data);
    free(temp);
}

// Delete from specified position
void deleteFromPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty! Cannot delete.\n");
        return;
    }
    
    if (position < 0) {
        printf("Invalid position! Position should be non-negative.\n");
        return;
    }
    
    struct Node* temp = *head;
    int i;
    
    // Move to the position
    for (i = 0; i < position && temp != NULL; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Position %d exceeds list length!\n", position);
        return;
    }
    
    // If it's the first node
    if (temp == *head) {
        deleteFromBeginning(head);
        return;
    }
    
    // If it's the last node
    if (temp->next == NULL) {
        deleteFromEnd(head);
        return;
    }
    
    // Node in between
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    printf("Deleted node with value %d from position %d.\n", temp->data, position);
    free(temp);
}

// Display the list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    printf("Doubly Linked List: ");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Get length of list (helper function)
int getLength(struct Node* head) {
    int length = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }
    return length;
}