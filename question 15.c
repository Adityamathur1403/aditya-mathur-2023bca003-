#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to create a queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to add an element to the queue
void enqueue(struct Queue* q, int data) {
    struct Node* temp = newNode(data);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        printf("Enqueued %d to the queue.\n", data);
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
    printf("Enqueued %d to the queue.\n", data);
}

// Function to remove an element from the queue
int dequeue(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue underflow\n");
        return -1;
    }
    struct Node* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    int data = temp->data;
    free(temp);
    return data;
}

// Function to display the queue
void displayQueue(struct Queue* q) {
    struct Node* temp = q->front;
    if (temp == NULL) {
        printf("The queue is empty.\n");
        return;
    }
    printf("Queue elements are:\n");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Menu function
void menu() {
    struct Queue* q = createQueue();
    int choice, data;
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue an element\n");
        printf("2. Dequeue an element\n");
        printf("3. Display the queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the data to enqueue: ");
                scanf("%d", &data);
                enqueue(q, data);
                break;
            case 2:
                data = dequeue(q);
                if (data != -1) {
                    printf("Dequeued %d from the queue.\n", data);
                }
                break;
            case 3:
                displayQueue(q);
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
