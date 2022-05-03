// Remove nth node from end of the list

// Efficent: Two pointer method (Traverse one time)
ListNode *remvoeNthFromEnd(ListNode *head, int n) {
    ListNode *slow = head, *fast = head;
    for (int i=0; i<n; i++)
        fast = fast->next;
    // if n == length of node i.e first node is target node
    if (fast == NULL) return head->next;
    while (fast->next)
        slow = slow->next, fast = fast->next;
    slow->next = slow->next->next;
    return head;
}

// Traversw two times
ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *ptr = head;
    if (head->next == NULL) { // only one node
        delete ptr;
        return NULL;
    }

    // count no of nodes
    int i = 0;
    while (ptr) {
        ptr = ptr->next;
        i++;
    }

    ptr = head;
    if (i == n) { // delete head
        head = head->next;
        delete ptr;
        return head;
    }
    ListNode *prev;
    int k = i - n;

    for (i = 0; i < k; i++) {
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next = ptr->next;
    delete ptr;
    return head;
}