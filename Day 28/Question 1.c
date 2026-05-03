#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// create circular linked list
struct Node* createCLL(int n) {
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

    // make it circular
    if (tail != NULL)
        tail->next = head;

    return head;
}

// traverse circular list
void printCLL(struct Node* head) {
    if (head == NULL) return;

    struct Node* curr = head;

    do {
        printf("%d ", curr->data);
        curr = curr->next;
    } while (curr != head);  // stop when back to head
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node* head = createCLL(n);

    printCLL(head);

    return 0;
}
