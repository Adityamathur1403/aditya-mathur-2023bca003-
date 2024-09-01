#include <stdio.h>
#include <stdlib.h> 

#define MAX_SIZE 100

struct Stack {
    int arr[MAX_SIZE];
    int top;
};

void initializeStack(struct Stack *s) {
    s->top = -1;
}


void push(struct Stack *s, int value) {
    s->top++;
    s->arr[s->top] = value;
}


int pop(struct Stack *s) {
    int poppedValue = s->arr[s->top];
    s->top--;
    return poppedValue;
}


int evaluatePostfix(char postfix[]) {
    struct Stack myStack;
    initializeStack(&myStack);

    int i = 0;

    while (postfix[i] != '\0') {
        char ch = postfix[i];

        if (isdigit(ch)) {
            push(&myStack, ch - '0'); 
        } else {
            
            int operand2 = pop(&myStack);
            int operand1 = pop(&myStack);

            switch (ch) {
                case '+':
                    push(&myStack, operand1 + operand2);
                    break;
                case '-':
                    push(&myStack, operand1 - operand2);
                    break;
                case '*':
                    push(&myStack, operand1 * operand2);
                    break;
                case '/':
                    push(&myStack, operand1 / operand2);
                    break;
                
            }
        }

        i++;
    }

 
    return pop(&myStack);
}

int main() {
    char postfix[] = "34+2*1-"; 

    int result = evaluatePostfix(postfix);

    printf("Result of postfix expression: %d\n", result);

    return 0;
}