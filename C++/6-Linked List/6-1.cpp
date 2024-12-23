// Find intersection point of Y Linked List

// Solution 1: Brute Force
// Time: O(m*n) | Space: O(1)
ListNode *intersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *ptr;
    while (headA) {
        ptr = headB;
        while (ptr) {
            if (ptr == headA) return headA;
            ptr = ptr->next;
        }
        headA = headA->next;
    }
    return NULL;
}

// Solution 2: Hashing
// Time: O(m+n) | Space: O(n)
ListNode *intersectionNode(ListNode *headA, ListNode *headB) {
    unordered_set<ListNode *> hash;
    while (headA) {
        hash.insert(headA);
        headA = headA->next;
    }
    while (headB) {
        if (hash.find(headB) != hash.end()) return headB;
        headB = headB->next;
    }
    return NULL;
}

// Solution 3: Difference of length
// Time: O(m+n) approx | Space: O(1)
ListNode *intersectionNode(ListNode *headA, ListNode *headB) {
    int m = 0, n = 0;
    ListNode *l1 = headA, *l2 = headB;
    while (l1 || l2) { // Find length of both list
        if (l1) {
            m++;
            l1 = l1->next;
        }
        if (l2) {
            n++;
            l2 = l2->next;
        }
    }
    int diff = abs(m - n); // +ve diff of lengths
    l1 = headA, l2 = headB;
    if (m < n) swap(l1, l2); // make list1 larger list
    for (int i = 0; i < diff; i++)
        l1 = l1->next; // move ptr of larger list by diff
    while (l1) {       // move both ptr while comparing
        if (l1 == l2) return l1;
        l1 = l1->next;
        l2 = l2->next;
    }
    return NULL;
}


// Solution 4 : Optimized
// Time: O(2*max(length of l1, length of l2)) | Space: O(1)
ListNode *intersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *l1 = headA, *l2 = headB;
    while (l1 != l2) {
        l1 = l1 ? l1->next : headB;
        l2 = l2 ? l2->next : headA;
    }
    // If no intersection, Both list will point to nullptr and cycle will end. Return will be nullptr.
    return l1;
}