#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Queue structure
struct Queue {
    struct Node *front, *rear;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Initialize queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Enqueue operation
void enqueue(struct Queue* q, int x) {
    struct Node* temp = createNode(x);

    // If queue is empty
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }

    // Add at the end
    q->rear->next = temp;
    q->rear = temp;
}

// Dequeue operation
int dequeue(struct Queue* q) {
    // If queue is empty
    if (q->front == NULL)
        return -1;

    struct Node* temp = q->front;
    int val = temp->data;

    q->front = q->front->next;

    // If queue becomes empty
    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return val;
}

int main() {
    int N;
    scanf("%d", &N);

    struct Queue* q = createQueue();

    while (N--) {
        char op[10];
        scanf("%s", op);

        if (op[0] == 'e') { // enqueue
            int x;
            scanf("%d", &x);
            enqueue(q, x);
        } else { // dequeue
            printf("%d\n", dequeue(q));
        }
    }

    return 0;
}
