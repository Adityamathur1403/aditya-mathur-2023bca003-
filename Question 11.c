#include <stdio.h>
#include <stdbool.h>
#include <ctype.h> 

#define MAX_SIZE 100


struct Stack {
    char arr[MAX_SIZE];
    int top;
};


void initializeStack(struct Stack *s) {
    s->top = -1;
}

void push(struct Stack *s, char value) {
    s->top++;
    s->arr[s->top] = value;
}

// Pop 
char pop(struct Stack *s) {
    char poppedValue = s->arr[s->top];
    s->top--;
    return poppedValue;
}

char peek(struct Stack *s) {
    return s->arr[s->top];
}

bool isEmpty(struct Stack *s) {
    return (s->top == -1);
}

void infixToPrefix(char infix[], char prefix[]) {
    
}

int main() {
    char infix[] = "3 + 4 * ( 2 - 1 )";
    char prefix[MAX_SIZE];

    infixToPrefix(infix, prefix);

    printf("Infix expression: %s\n", infix);
    printf("Prefix expression: %s\n", prefix);

    return 0;
}