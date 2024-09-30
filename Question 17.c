#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the end of the circular linked list
void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = *head_ref;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        new_node->next = new_node;
    } else {
        while (last->next != *head_ref) {
            last = last->next;
        }
        last->next = new_node;
    }
    printf("Node with data %d inserted at the end.\n", new_data);
}

// Function to insert a node before a specified position
void insertBeforePosition(struct Node** head_ref, int new_data, int position) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head_ref;
    new_node->data = new_data;
    if (position == 1) {
        while (temp->next != *head_ref) {
            temp = temp->next;
        }
        new_node->next = *head_ref;
        temp->next = new_node;
        *head_ref = new_node;
    } else {
        for (int i = 1; i < position - 1 && temp->next != *head_ref; i++) {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
    printf("Node with data %d inserted before position %d.\n", new_data, position);
}

// Function to delete the first node of the circular linked list
void deleteFirstNode(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = *head_ref;
    struct Node* last = *head_ref;
    while (last->next != *head_ref) {
        last = last->next;
    }
    if (*head_ref == (*head_ref)->next) {
        *head_ref = NULL;
    } else {
        *head_ref = (*head_ref)->next;
        last->next = *head_ref;
    }
    free(temp);
    printf("First node deleted.\n");
}

// Function to delete a node after a specified position
void deleteNodeAfterPosition(struct Node** head_ref, int position) {
    if (*head_ref == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = *head_ref;
    for (int i = 1; i < position && temp->next != *head_ref; i++) {
        temp = temp->next;
    }
    if (temp->next == *head_ref) {
        printf("Position is out of range.\n");
        return;
    }
    struct Node* node_to_delete = temp->next;
    temp->next = node_to_delete->next;
    free(node_to_delete);
    printf("Node after position %d deleted.\n", position);
}

// Function to traverse and display the circular linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("HEAD\n");
}

// Menu function
void menu() {
    struct Node* head = NULL;
    int choice, data, position;
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert a node at the end\n");
        printf("2. Insert a node before specified position\n");
        printf("3. Delete the first node\n");
        printf("4. Delete a node after specified position\n");
        printf("5. Display the list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the data to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 2:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                printf("Enter the position before which to insert the node: ");
                scanf("%d", &position);
                insertBeforePosition(&head, data, position);
                break;
            case 3:
                deleteFirstNode(&head);
                break;
            case 4:
                printf("Enter the position after which to delete the node: ");
                scanf("%d", &position);
                deleteNodeAfterPosition(&head, position);
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
