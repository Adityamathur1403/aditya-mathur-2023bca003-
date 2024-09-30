#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** top_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Stack overflow\n");
        return;
    }
    new_node->data = new_data;
    new_node->next = (*top_ref);
    (*top_ref) = new_node;
    printf("Pushed %d onto the stack.\n", new_data);
}

// Function to pop an element from the stack
int pop(struct Node** top_ref) {
    if (*top_ref == NULL) {
        printf("Stack underflow\n");
        return -1;
    }
    struct Node* temp = *top_ref;
    *top_ref = (*top_ref)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

// Function to display the stack
void displayStack(struct Node* top) {
    if (top == NULL) {
        printf("The stack is empty.\n");
        return;
    }
    printf("Stack elements are:\n");
    while (top != NULL) {
        printf("%d -> ", top->data);
        top = top->next;
    }
    printf("NULL\n");
}

// Menu function
void menu() {
    struct Node* top = NULL;
    int choice, data;
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Push an element onto the stack\n");
        printf("2. Pop an element from the stack\n");
        printf("3. Display the stack\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the data to push: ");
                scanf("%d", &data);
                push(&top, data);
                break;
            case 2:
                data = pop(&top);
                if (data != -1) {
                    printf("Popped %d from the stack.\n", data);
                }
                break;
            case 3:
                displayStack(top);
                break;
            case 4:
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
