#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

// push
void push(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}

// pop
int pop() {
    if (top == NULL) return 0; // safety
    struct Node* temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

// evaluate postfix
int evaluate(char* expr) {
    char* token = strtok(expr, " ");

    while (token != NULL) {

        // if number
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            push(atoi(token));
        }
        // operator
        else {
            int b = pop();
            int a = pop();
            int res;

            switch (token[0]) {
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/': res = a / b; break;
                default: res = 0;
            }

            push(res);
        }

        token = strtok(NULL, " ");
    }

    return pop();
}

int main() {
    char expr[1000];

    fgets(expr, sizeof(expr), stdin);

    // remove newline
    expr[strcspn(expr, "\n")] = '\0';

    int result = evaluate(expr);
    printf("%d\n", result);

    return 0;
}
