#include <stdio.h>

#define MAX 1000

int q[MAX];
int front = -1, rear = -1;

// enqueue
void enqueue(int x) {
    if (front == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
    q[rear] = x;
}

// dequeue
void dequeue() {
    if (front == -1) return;

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

// display
void display() {
    if (front == -1) return;

    int i = front;
    while (1) {
        printf("%d ", q[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
}

int main() {
    int n, m;
    scanf("%d", &n);

    // enqueue all elements
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        enqueue(x);
    }

    scanf("%d", &m);

    // perform m dequeues
    for (int i = 0; i < m; i++) {
        dequeue();
    }

    display();

    return 0;
}
