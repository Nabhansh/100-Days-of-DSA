#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 1000

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

char peek() {
    return stack[top];
}

int isEmpty() {
    return top == -1;
}

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

int isRightAssociative(char c) {
    return (c == '^');
}

int main() {
    char infix[MAX], postfix[MAX];
    scanf("%s", infix);

    int k = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        // operand
        if (isalnum(c)) {
            postfix[k++] = c;
        }
        // opening bracket
        else if (c == '(') {
            push(c);
        }
        // closing bracket
        else if (c == ')') {
            while (!isEmpty() && peek() != '(') {
                postfix[k++] = pop();
            }
            pop(); // remove '('
        }
        // operator
        else {
            while (!isEmpty() && 
                  (precedence(peek()) > precedence(c) ||
                  (precedence(peek()) == precedence(c) && !isRightAssociative(c)))) {
                postfix[k++] = pop();
            }
            push(c);
        }
    }

    // pop remaining operators
    while (!isEmpty()) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';

    printf("%s\n", postfix);

    return 0;
}
