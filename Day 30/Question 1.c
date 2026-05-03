#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

// create polynomial
struct Node* createPoly(int n) {
    struct Node *head = NULL, *tail = NULL;

    for (int i = 0; i < n; i++) {
        int c, e;
        scanf("%d %d", &c, &e);

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->coeff = c;
        newNode->exp = e;
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

// print polynomial
void printPoly(struct Node* head) {
    struct Node* curr = head;

    while (curr != NULL) {
        if (curr->exp == 0) {
            printf("%d", curr->coeff);
        } 
        else if (curr->exp == 1) {
            printf("%dx", curr->coeff);
        } 
        else {
            printf("%dx^%d", curr->coeff, curr->exp);
        }

        if (curr->next != NULL) {
            printf(" + ");
        }

        curr = curr->next;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node* poly = createPoly(n);

    printPoly(poly);

    return 0;
}
