#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100
//circular queue

struct CircularQueue {
    int arr[MAX_SIZE];
    int front, rear;
};

void initializeCircularQueue(struct CircularQueue *cq) {
    cq->front = -1;
    cq->rear = -1;
}


bool isCircularQueueEmpty(struct CircularQueue *cq) {
    return (cq->front == -1);
}


bool isCircularQueueFull(struct CircularQueue *cq) {
    return ((cq->rear + 1) % MAX_SIZE == cq->front);
}

// Insert 
void enqueueCircular(struct CircularQueue *cq, int value) {
    if (isCircularQueueFull(cq)) {
        printf("Circular queue is full. Cannot insert.\n");
        return;
    }

    if (isCircularQueueEmpty(cq)) {
        cq->front = 0; 
    }

    cq->rear = (cq->rear + 1) % MAX_SIZE;
    cq->arr[cq->rear] = value;
    printf("Element %d inserted into the circular queue.\n", value);
}

// Delete
void dequeueCircular(struct CircularQueue *cq) {
    if (isCircularQueueEmpty(cq)) {
        printf("Circular queue is empty. Cannot delete.\n");
        return;
    }

    int removedValue = cq->arr[cq->front];
    if (cq->front == cq->rear) {
        cq->front = cq->rear = -1; 
    } else {
        cq->front = (cq->front + 1) % MAX_SIZE;
    }

    printf("Element %d removed from the circular queue.\n", removedValue);
}

// Display 
void displayCircularQueue(struct CircularQueue *cq) {
    if (isCircularQueueEmpty(cq)) {
        printf("Circular queue is empty.\n");
        return;
    }

    printf("Circular queue elements: ");
    int i = cq->front;
    while (i != cq->rear) {
        printf("%d ", cq->arr[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", cq->arr[cq->rear]);
}

// Peek 
void peekCircular(struct CircularQueue *cq) {
    if (isCircularQueueEmpty(cq)) {
        printf("Circular queue is empty.\n");
        return;
    }

    printf("Front element: %d\n", cq->arr[cq->front]);
}

int main() {
    struct CircularQueue myCircularQueue;
    initializeCircularQueue(&myCircularQueue);

   

    return 0;
}




#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Stack structure
struct Stack {
    int arr[MAX_SIZE];
    int top;
};

void initializeStack(struct Stack *s) {
    s->top = -1;
}


bool isStackEmpty(struct Stack *s) {
    return (s->top == -1);
}


bool isStackFull(struct Stack *s) {
    return (s->top == MAX_SIZE - 1);
}

// Push 
void push(struct Stack *s, int value) {
    if (isStackFull(s)) {
        printf("Stack is full. Cannot push.\n");
        return;
    }

    s->top++;
    s->arr[s->top] = value;
    printf("Element %d pushed onto the stack.\n", value);
}

// Pop 
void pop(struct Stack *s) {
    if (isStackEmpty(s)) {
        printf("Stack is empty. Cannot pop.\n");
        return;
    }

    int poppedValue = s->arr[s->top];
    s->top--;

    printf("Element %d popped from the stack.\n", poppedValue);
}

// Peek 
void peekStack(struct Stack *s) {
    if (isStackEmpty(s)) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Top element: %d\n", s->arr[s->top]);
}

int main() {
    struct Stack myStack;
    initializeStack(&myStack);
