// Find starting point of loop of Linked List

// Solution 1: Hashing
// Time: O(n) | Space: O(n)
node *detectCycle(node *head) {
    unordered_set<node *> hashSet;
    while (head != NULL) {
        if (hashSet.find(head) != hashSet.end()) return head;
        hashSet.insert(head);
        head = head->next;
    }
    return NULL;
}


// 2 ptr method
// Time: O(n) | Space: O(1)
ListNode *start(ListNode *head) {
    ListNode *slow = head, *fast = head, *entry = head;
    ;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            while (slow != entry) {
                slow = slow->next;
                entry = entry->next;
            }
            return entry;
        }
    }
    return NULL;
}

/** HOW
 * Distance traveled by slow when they meet = L1 + L2
 * Distance traveled by fast when they meet = L1 + L2 + x + L2
 * where, L1 = distance between head and entry
 *        L2 = distance between entry and meeting point
 *        x = remaining length of cycle
 * 2(L1 + L2) = L1 + L2 + x + L2
 * => x = L1
 * so *slow needs to move x steps & *entry needs to move L1 steps (then they meet at entry of cycle)
 */