# Linked List Cycle II
# https://leetcode.com/problems/linked-list-cycle-ii/


from typing import Optional


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return None
        has_cycle = False
        slow = fast = head
        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                has_cycle = True
                break
        if not has_cycle:
            return None

        slow = head
        while slow != fast:
            slow = slow.next
            fast = fast.next
        return slow
