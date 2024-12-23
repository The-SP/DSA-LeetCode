// Delete given node in a Linked List : O(1) time

void deleteNode(ListNode *node) {
    node->val = node->next->val;
    node->next = node->next->next;
}
// Copy the next node's value in deleted node. then link node to next of next node
// This does not delete that node but indirectly it removes that node from the linked list.