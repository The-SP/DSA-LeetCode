// Rotate a linked list k times to right

// Time: O(len) + O(len-(k%len)) | Space: O(1)
ListNode* rotateRight(ListNode* head, int k) {
    if (!head || !head->next) return head;
    
    // calculate length of LL
    ListNode* ptr = head;
    int length = 1;
    while(ptr->next) {
        ptr = ptr->next;
        length++:
    }
    // link last node to first node
    ptr->next = head;

    int end = length - k % length; // to get end of list
    while (end--) ptr = ptr->next;
    // Or, for (int i=1; i<end; i++)

    // point next of ptr to head and make ptr last node
    head = ptr->next;
    ptr->next = NULL;
    return head;
}