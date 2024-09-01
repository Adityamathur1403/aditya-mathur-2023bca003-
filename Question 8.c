#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100


struct Queue {
    int arr[MAX_SIZE];
    int front, rear;
};

void initializeQueue(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

bool isEmpty(struct Queue *q) {
    return (q->front == -1);
}

bool isFull(struct Queue *q) {
    return (q->rear == MAX_SIZE - 1);
}



// Insert 
void enqueue(struct Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot insert.\n");
        return;
    }

    if (isEmpty(q)) {
        q->front = 0; 
    }

    q->rear++;
    q->arr[q->rear] = value;
    printf("Element %d inserted into the queue.\n", value);
}



// Delete
void dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot delete.\n");
        return;
    }

    int removedValue = q->arr[q->front];
    q->front++;

    printf("Element %d removed from the queue.\n", removedValue);
}



// Traverse
void traverse(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; ++i) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}



// Peep
void peek(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Front element: %d\n", q->arr[q->front]);
}

int main() {
    struct Queue myQueue;
    initializeQueue(&myQueue);

    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Insert an element into the queue\n");
        printf("2. Delete an element from the queue\n");
        printf("3. Traverse the queue\n");
        printf("4. Peek at the front element\n");
        printf("5. Check if the queue is full\n");
        printf("6. Check if the queue is empty\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &value);
                enqueue(&myQueue, value);
                break;
            case 2:
                dequeue(&myQueue);
                break;
            case 3:
                traverse(&myQueue);
                break;
            case 4:
                peek(&myQueue);
                break;
            case 5:
                printf("Queue is%s full.\n", isFull(&myQueue) ? "" : " not");
                break;
            case 6:
                printf("Queue is%s empty.\n", isEmpty(&myQueue) ? "" : " not");
                break;
            case 7:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}