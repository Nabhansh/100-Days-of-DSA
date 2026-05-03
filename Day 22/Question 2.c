struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;

    while (curr != NULL) {
        struct ListNode* next = curr->next; // save next
        curr->next = prev;                  // reverse link
        prev = curr;                        // move prev
        curr = next;                        // move curr
    }

    return prev; // new head
}
