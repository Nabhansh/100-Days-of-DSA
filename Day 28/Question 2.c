#include <stdbool.h>

// DO NOT redefine struct ListNode

// reverse helper
struct ListNode* reverse(struct ListNode* head) {
    struct ListNode *prev = NULL, *curr = head;

    while (curr) {
        struct ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool isPalindrome(struct ListNode* head) {
    if (!head || !head->next) return true;

    // find middle
    struct ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // reverse second half
    struct ListNode* second = reverse(slow);

    // compare
    struct ListNode* first = head;
    while (second) {
        if (first->val != second->val)
            return false;
        first = first->next;
        second = second->next;
    }

    return true;
}
