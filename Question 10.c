#include <stdio.h>
#include <stdbool.h>
#include <ctype.h> 
#define MAX_SIZE 100

// Stack structure
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

void infixToPostfix(char infix[], char postfix[]) {
    struct Stack myStack;
    initializeStack(&myStack);

    int i = 0; 
    int j = 0; 

    while (infix[i] != '\0') {
        char ch = infix[i];

        if (isdigit(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(&myStack, ch);
        } else if (ch == ')') {
            while (!isEmpty(&myStack) && peek(&myStack) != '(') {
                postfix[j++] = pop(&myStack);
            }
            pop(&myStack); 
        } else {
          
            while (!isEmpty(&myStack) && peek(&myStack) != '(' && ch <= peek(&myStack)) {
                postfix[j++] = pop(&myStack);
            }
            push(&myStack, ch);
        }

        i++;
    }

    while (!isEmpty(&myStack)) {
        postfix[j++] = pop(&myStack);
    }

    postfix[j] = '\0'; //
}

int main() {
    char infix[] = "3 + 4 * ( 2 - 1 )";
    char postfix[MAX_SIZE];

    infixToPostfix(infix, postfix);

    printf("Infix expression: %s\n", infix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}