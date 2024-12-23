// Reverse a linked list

struct ListNode;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next)
 * };
 */

// Iterative method
// Time: O(n) | Space: O(1)
ListNode *reverseList(ListNode *head) {
    ListNode *current_p = head, *prev_p = NULL, *next_p;
    while (current_p) {
        next_p = current_p->next; // Store next
        current_p->next = prev_p; // Change next of current (reversing)
        prev_p = current_p;       // Move prev and current one step forward
        current_p = next_p;
    }
    head = prev_p;
    return head;
}

ListNode *recursive(ListNode *head) {
    if (head == NULL || head->next == NULL)
        return head;

    // reverse the rest list and put first element at the end
    ListNode *rest = recursive(head->next);
    head->next->next = head;

    head->next = NULL;
    return rest; // fix the head ptr
}

/** Dry Run
 * Initially: 1, 2, 3, 4, 5
 * After each recursion, traverses from 1-2-3-4-5, go to end of list
 * After first return, rest = 5, head = 4
 * head->next->next = head; i.e 4->next(5)->next = 4
 * 4->next = NULL
 * return rest; i.e rest is fixed at 5 (last node)
 */
