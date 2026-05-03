#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// create list
struct Node* createList(int n) {
    struct Node *head = NULL, *tail = NULL;

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = x;
        newNode->next = NULL;

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

// rotate list
struct Node* rotateRight(struct Node* head, int k) {
    if (!head || !head->next || k == 0)
        return head;

    // Step 1: find length and last node
    int n = 1;
    struct Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
        n++;
    }

    // Step 2: make circular
    tail->next = head;

    // Step 3: normalize k
    k = k % n;

    // Step 4: find new tail (n-k-1 steps)
    int steps = n - k;
    struct Node* newTail = head;

    for (int i = 1; i < steps; i++) {
        newTail = newTail->next;
    }

    // Step 5: break the circle
    struct Node* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

// print list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, k;

    scanf("%d", &n);
    struct Node* head = createList(n);

    scanf("%d", &k);

    head = rotateRight(head, k);

    printList(head);

    return 0;
}
