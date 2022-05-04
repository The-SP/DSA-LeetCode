// Find middle of the linked list
struct ListNode;

// Solution 1
ListNode* middle(ListNode* head) {
    ListNode* ptr = head;
    int i=0, mid;
    // Traverse the list and Count no of nodes
    while (ptr) {
        ptr = ptr->next;
        i++;
    }
    // Traverse for n/2 nodes to get to middle of the list
    mid = i/2;
    ptr = head;
    for (i=0; i<mid; i++)
        ptr=ptr->next;
    return ptr;
}

// Solution 2: Efficient: Tortoise-Hare-Approach
ListNode* middleNode(ListNode* head) {
    ListNode *slow=head, *fast=head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}