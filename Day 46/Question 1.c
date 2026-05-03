#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

// Queue Node
struct QueueNode {
    struct TreeNode* data;
    struct QueueNode* next;
};

// Queue
struct Queue {
    struct QueueNode *front, *rear;
};

// Create Queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Enqueue
void enqueue(struct Queue* q, struct TreeNode* node) {
    struct QueueNode* temp = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    temp->data = node;
    temp->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}

// Dequeue
struct TreeNode* dequeue(struct Queue* q) {
    if (q->front == NULL) return NULL;

    struct QueueNode* temp = q->front;
    struct TreeNode* node = temp->data;

    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;

    free(temp);
    return node;
}

// Check empty
int isEmpty(struct Queue* q) {
    return q->front == NULL;
}

// -------- LEVEL ORDER TRAVERSAL --------
void levelOrder(struct TreeNode* root) {
    if (root == NULL) return;

    struct Queue* q = createQueue();
    enqueue(q, root);

    while (!isEmpty(q)) {
        struct TreeNode* curr = dequeue(q);
        printf("%d ", curr->val);

        if (curr->left) enqueue(q, curr->left);
        if (curr->right) enqueue(q, curr->right);
    }
}
