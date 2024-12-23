// Detect a cycle in Linked List

// Solution 1: Hashing
// Time: O(n) | Space: O(n)
bool detectCycle(ListNode *head) {
    unordered_set<ListNode *> hashSet;
    while (head) {
        if (hashSet.find(head) != hashSet.end())
            return true;
        hashSet.insert(head);
        head = head->next;
    }

    return false;
}

// Solution 2: Two ptr method
// Floyd’s Cycle-Finding Algorithm // "tortoise and the hare algorithm"
// Time: O(n) | Space: O(1)
bool detectCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;

        // At the point if fast and slow are at same address
        // this means linked list has a cycle in it.
        if (fast == slow) return true;
    }
    return false;
}

/** HOW?
 * let's say 2 people are running in a circular track, one person is running slowly and another person is running faster(2 times the speed of first person)

 * After a certain period of time person 2 again meet or overtake person 1,

 * In that case we can conclude that the track is circular ( replace running track with our Linked list)
*/