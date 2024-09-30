#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the front of the linked list
void insertAtFront(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
    printf("Node with data %d inserted at the front.\n", new_data);
}

// Function to insert a node at the end of the linked list
void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        printf("Node with data %d inserted at the end.\n", new_data);
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
    printf("Node with data %d inserted at the end.\n", new_data);
}

// Function to insert a node in ascending order
void insertInOrder(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* current;
    new_node->data = new_data;
    if (*head_ref == NULL || (*head_ref)->data >= new_data) {
        new_node->next = *head_ref;
        *head_ref = new_node;
    } else {
        current = *head_ref;
        while (current->next != NULL && current->next->data < new_data) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
    printf("Node with data %d inserted in order.\n", new_data);
}

// Function to delete the first node of the linked list
void deleteFirstNode(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = *head_ref;
    *head_ref = (*head_ref)->next;
    free(temp);
    printf("First node deleted.\n");
}

// Function to delete a node before a specified position
void deleteNodeBeforePosition(struct Node** head_ref, int position) {
    if (*head_ref == NULL || position <= 1) {
        printf("Invalid position or the list is empty.\n");
        return;
    }
    struct Node* temp = *head_ref;
    if (position == 2) {
        *head_ref = temp->next;
        free(temp);
        printf("Node before position %d deleted.\n", position);
        return;
    }
    struct Node* prev = NULL;
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Position is out of range.\n");
        return;
    }
    struct Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
    printf("Node before position %d deleted.\n", position);
}

// Function to delete a node after a specified position
void deleteNodeAfterPosition(struct Node** head_ref, int position) {
    if (*head_ref == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = *head_ref;
    for (int i = 1; temp != NULL && i < position; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Position is out of range.\n");
        return;
    }
    struct Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
    printf("Node after position %d deleted.\n", position);
}

// Function to display the linked list
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
        printf("3. Insert a node in ascending order\n");
        printf("4. Delete the first node\n");
        printf("5. Delete a node before specified position\n");
        printf("6. Delete a node after specified position\n");
        printf("7. Display the list\n");
        printf("8. Exit\n");
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
                printf("Enter the data to insert in order: ");
                scanf("%d", &data);
                insertInOrder(&head, data);
                break;
            case 4:
                deleteFirstNode(&head);
                break;
            case 5:
                printf("Enter the position before which to delete the node: ");
                scanf("%d", &position);
                deleteNodeBeforePosition(&head, position);
                break;
            case 6:
                printf("Enter the position after which to delete the node: ");
                scanf("%d", &position);
                deleteNodeAfterPosition(&head, position);
                break;
            case 7:
                displayList(head);
                break;
            case 8:
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
