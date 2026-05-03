#include <stdlib.h>

// Node definition
typedef struct Node {
    int val;
    struct Node* next;
} Node;

// Linked list definition
typedef struct {
    Node* head;   // dummy head
    int size;
} MyLinkedList;


// Create
MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    obj->head = (Node*)malloc(sizeof(Node)); // dummy node
    obj->head->next = NULL;
    obj->size = 0;
    return obj;
}

// Get
int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) return -1;

    Node* curr = obj->head->next;
    for (int i = 0; i < index; i++)
        curr = curr->next;

    return curr->val;
}

// Add at head
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->next = obj->head->next;
    obj->head->next = node;
    obj->size++;
}

// Add at tail
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    Node* curr = obj->head;

    while (curr->next)
        curr = curr->next;

    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;
    curr->next = node;
    obj->size++;
}

// Add at index
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index > obj->size) return;
    if (index < 0) index = 0;

    Node* curr = obj->head;

    for (int i = 0; i < index; i++)
        curr = curr->next;

    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->next = curr->next;
    curr->next = node;
    obj->size++;
}

// Delete at index
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) return;

    Node* curr = obj->head;

    for (int i = 0; i < index; i++)
        curr = curr->next;

    Node* temp = curr->next;
    curr->next = temp->next;
    free(temp);

    obj->size--;
}

// Free memory
void myLinkedListFree(MyLinkedList* obj) {
    Node* curr = obj->head;
    while (curr) {
        Node* temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(obj);
}
