#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void insertAtFront(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    new_node->prev = NULL;
    if ((*head_ref) != NULL) {
        (*head_ref)->prev = new_node;
    }
    (*head_ref) = new_node;
    printf("Node with data %d inserted at the front.\n", new_data);
}

// Function to insert a node at the end of the doubly linked list
void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        printf("Node with data %d inserted at the end.\n", new_data);
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
    new_node->prev = last;
    printf("Node with data %d inserted at the end.\n", new_data);
}

// Function to delete the last node of the doubly linked list
void deleteLastNode(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = *head_ref;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        *head_ref = NULL;
    }
    free(temp);
    printf("Last node deleted.\n");
}

// Function to delete a node before a specified position
void deleteNodeBeforePosition(struct Node** head_ref, int position) {
    if (*head_ref == NULL || position <= 1) {
        printf("Invalid position or the list is empty.\n");
        return;
    }
    struct Node* temp = *head_ref;
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->prev == NULL) {
        printf("Position is out of range.\n");
        return;
    }
    struct Node* node_to_delete = temp->prev;
    if (node_to_delete->prev != NULL) {
        node_to_delete->prev->next = temp;
    } else {
        *head_ref = temp;
    }
    temp->prev = node_to_delete->prev;
    free(node_to_delete);
    printf("Node before position %d deleted.\n", position);
}

// Function to traverse and display the doubly linked list
void displayList(struct Node* node) {
    if (node == NULL) {
        printf("The list is empty.\n");
        return;
    }
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Menu function
void menu() {
    struct Node* head = NULL;
    int choice, data, position;
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert a node at the front\n");
        printf("2. Insert a node at the end\n");
        printf("3. Delete the last node\n");
        printf("4. Delete a node before specified position\n");
        printf("5. Display the list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the data to insert at the front: ");
                scanf("%d", &data);
                insertAtFront(&head, data);
                break;
            case 2:
                printf("Enter the data to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                deleteLastNode(&head);
                break;
            case 4:
                printf("Enter the position before which to delete the node: ");
                scanf("%d", &position);
                deleteNodeBeforePosition(&head, position);
                break;
            case 5:
                displayList(head);
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

int main() {
    menu();
    return 0;
}
