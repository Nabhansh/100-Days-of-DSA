#include <stdio.h>
#include <stdlib.h>

// -------- Stack Implementation --------
struct Stack {
    int *arr;
    int top;
    int capacity;
};

struct Stack* createStack(int capacity) {
    struct Stack* s = (struct Stack*)malloc(sizeof(struct Stack));
    s->capacity = capacity;
    s->top = -1;
    s->arr = (int*)malloc(capacity * sizeof(int));
    return s;
}

void push(struct Stack* s, int x) {
    s->arr[++s->top] = x;
}

int pop(struct Stack* s) {
    return s->arr[s->top--];
}

int isEmptyStack(struct Stack* s) {
    return s->top == -1;
}

// -------- Queue Implementation --------
struct Queue {
    int *arr;
    int front, rear, size, capacity;
};

struct Queue* createQueue(int capacity) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->capacity = capacity;
    q->front = 0;
    q->size = 0;
    q->rear = capacity - 1;
    q->arr = (int*)malloc(capacity * sizeof(int));
    return q;
}

int isEmptyQueue(struct Queue* q) {
    return q->size == 0;
}

void enqueue(struct Queue* q, int x) {
    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = x;
    q->size++;
}

int dequeue(struct Queue* q) {
    int val = q->arr[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return val;
}

// -------- Reverse Function --------
void reverseQueue(struct Queue* q) {
    struct Stack* s = createStack(q->capacity);

    // Step 1: Dequeue all elements into stack
    while (!isEmptyQueue(q)) {
        push(s, dequeue(q));
    }

    // Step 2: Push back into queue
    while (!isEmptyStack(s)) {
        enqueue(q, pop(s));
    }
}

// -------- Main --------
int main() {
    int N;
    scanf("%d", &N);

    struct Queue* q = createQueue(N);

    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        enqueue(q, x);
    }

    reverseQueue(q);

    // Print reversed queue
    while (!isEmptyQueue(q)) {
        printf("%d ", dequeue(q));
    }

    return 0;
}
