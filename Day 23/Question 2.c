bool hasCycle(struct ListNode *head) {
    if(!head || !head->next) return false;
    struct ListNode *temp = head;
    while(temp->next){
        if(temp->val == INT_MAX) return true;
        temp->val = INT_MAX;
        temp = temp->next;
    }
    return false;
}
