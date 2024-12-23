// Merge two sorted list
// struct ListNode;

// Inplace method without using extra space
// Time: O(n+m) | Space: O(1)
ListNode *merge(ListNode *l1, ListNode *l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    // point l1 and l2 to smallest and largest one
    if (l1->val > l2->val) swap(l1, l2);
    // head of resultant merged list
    ListNode *merged = l1;

    while (l1 && l2) {
        ListNode *ptr = NULL;
        while (l1 && l1->val <= l2->val) {
            ptr = l1; // storing last sorted node
            l1 = l1->next;
        }

        // link last sorted node with next larger node in l2
        ptr->next = l2;
        swap(l1, l2);
    }
    return merged;
}