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

// delete first occurrence of key
struct Node* deleteKey(struct Node* head, int key) {
    struct Node *curr = head, *prev = NULL;

    // case 1: head contains key
    if (head != NULL && head->data == key) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    // case 2: search in rest
    while (curr != NULL && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    // key not found
    if (curr == NULL) return head;

    // unlink node
    prev->next = curr->next;
    free(curr);

    return head;
}

// print list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, key;

    scanf("%d", &n);
    struct Node* head = createList(n);

    scanf("%d", &key);

    head = deleteKey(head, key);

    printList(head);

    return 0;
}
