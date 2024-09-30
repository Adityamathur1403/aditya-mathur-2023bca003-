#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

void insertAtFront(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    
    new_node->data = new_data;
    
    new_node->next = (*head_ref);
    
    (*head_ref) = new_node;
    
    printf("Node with data %d inserted at the front.\n", new_data);
}

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

void menu() {
    struct Node* head = NULL;
    int choice, data;
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert a node at the front\n");
        printf("2. Display the list\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                insertAtFront(&head, data);
                break;
            case 2:
                displayList(head);
                break;
            case 3:
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
