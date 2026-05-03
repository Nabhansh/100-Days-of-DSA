#include <stdio.h>

#define MAX 1000

int stack[MAX];
int top = -1;

void push(int x) {
    if (top == MAX - 1) return; // ignore overflow for this problem
    stack[++top] = x;
}

void pop() {
    if (top == -1) return; // ignore underflow for this problem
    top--;
}

void display() {
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    // push n elements
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        push(x);
    }

    int m;
    scanf("%d", &m);

    // pop m times
    for (int i = 0; i < m; i++) {
        pop();
    }

    // print remaining stack
    display();

    return 0;
}
