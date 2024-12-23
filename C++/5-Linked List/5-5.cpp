// Add Two numbers as a linked list

// Time: O(max(m, n)) | Space: O(max(m, n)) (+1)
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *dummy = new ListNode();
    ListNode *ptr = dummy;
    int carry = 0, sum;
    while (l1 || l2 || carry) {
        sum = 0;
        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }
        sum += carry;
        ListNode *temp = new ListNode(sum % 10);
        carry = sum/10;
        ptr->next = temp;
        ptr = temp;
    }
    return dummy->next;
}