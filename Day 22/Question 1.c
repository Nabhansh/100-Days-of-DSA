#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n;
    scanf("%d", &n);

    struct Node *head = NULL, *tail = NULL;

    // Build the list
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

    // Traverse (print elements)
    struct Node* curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");

    // Count nodes
    int count = 0;
    curr = head;
    while (curr != NULL) {
        count++;
        curr = curr->next;
    }

    // If the task truly wants count, print this:
    // printf("%d\n", count);

    return 0;
}
