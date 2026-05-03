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

// get length
int getLength(struct Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

// find intersection
struct Node* getIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    struct Node *p1 = head1, *p2 = head2;

    // move longer list ahead
    int diff = abs(len1 - len2);
    if (len1 > len2) {
        while (diff--) p1 = p1->next;
    } else {
        while (diff--) p2 = p2->next;
    }

    // move both together
    while (p1 != NULL && p2 != NULL) {
        if (p1 == p2) return p1;
        p1 = p1->next;
        p2 = p2->next;
    }

    return NULL;
}

int main() {
    int n, m;

    scanf("%d", &n);
    struct Node* list1 = createList(n);

    scanf("%d", &m);
    struct Node* list2 = createList(m);

    // ⚠️ NOTE: This input does NOT naturally create intersection.
    // For testing, you must manually connect:
    // Example: connect last node of list2 to some node of list1

    // Example manual intersection (for demonstration):
    struct Node* temp1 = list1;
    while (temp1 != NULL && temp1->data != 30) {
        temp1 = temp1->next;
    }

    struct Node* temp2 = list2;
    while (temp2->next != NULL) {
        temp2 = temp2->next;
    }

    if (temp1 != NULL) {
        temp2->next = temp1; // create intersection
    }

    struct Node* inter = getIntersection(list1, list2);

    if (inter)
        printf("%d\n", inter->data);
    else
        printf("No Intersection\n");

    return 0;
}
