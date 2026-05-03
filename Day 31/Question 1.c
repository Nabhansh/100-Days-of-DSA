#include <stdio.h>

#define MAX 1000

int stack[MAX];
int top = -1;

// push operation
void push(int x) {
    if (top == MAX - 1) {
        // optional: overflow handling (not required by problem)
        return;
    }
    stack[++top] = x;
}

// pop operation
void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    printf("%d\n", stack[top--]);
}

// display operation (top → bottom)
void display() {
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        int op;
        scanf("%d", &op);

        if (op == 1) {
            int val;
            scanf("%d", &val);
            push(val);
        }
        else if (op == 2) {
            pop();
        }
        else if (op == 3) {
            display();
        }
    }

    return 0;
}
