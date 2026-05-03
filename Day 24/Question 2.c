struct ListNode* removeElements(struct ListNode* head, int val) {
    // dummy node to handle deletions at head
    struct ListNode dummy;
    dummy.next = head;

    struct ListNode* prev = &dummy;
    struct ListNode* curr = head;

    while (curr != NULL) {
        if (curr->val == val) {
            prev->next = curr->next; // unlink
            // free(curr); // uncomment if memory management is required in your environment
            curr = prev->next;       // move curr only
        } else {
            prev = curr;             // move both
            curr = curr->next;
        }
    }

    return dummy.next;
}
