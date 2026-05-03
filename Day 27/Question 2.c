#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

bool removeLoop(struct Node* head) {
    if (head == NULL || head->next == NULL)
        return false;

    struct Node *slow = head, *fast = head;

    // Step 1: Detect cycle
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // Cycle detected

            // Step 2: Find start of loop
            slow = head;
            struct Node* prev = NULL;

            while (slow != fast) {
                prev = fast;
                slow = slow->next;
                fast = fast->next;
            }

            // Step 3: Break the loop
            // 'fast' is at loop start, 'prev' is last node of loop
            if (prev != NULL)
                prev->next = NULL;

            return true;
        }
    }

    return false; // no cycle
}
