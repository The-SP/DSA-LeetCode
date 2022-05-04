// Detect Palindrome

// Solution: Using extra Data Structure
// Time: O(n) | Space: O(n)
bool isPalindrome(node* head) {
    vector<int> arr;
    while(head != NULL) {
        arr.push_back(head->num);
        head = head->next;
    }
    for(int i=0;i<arr.size()/2;i++) 
        if(arr[i] != arr[arr.size()-i-1]) return false;
    return true;
}

// Solution: Optimized, no extra data str. used
// Time: O(n/2)+O(n/2)+O(n/2) | Space: O(1)
bool isPalindrome(ListNode *head) {
    ListNode *slow = head, *fast = head;
    // reach middle element of the list
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    // reverse slow
    ListNode *curr_p = slow, *next_p, *prev_p = NULL;
    while (curr_p) {
        next_p = curr_p->next;
        curr_p->next = prev_p;
        prev_p = curr_p;
        curr_p = next_p;
    }
    slow = prev_p;

    // compare reverse of list after middle & original list from start
    while (slow) {
        if (head->val != slow->val) return false;
        slow = slow->next;
        head = head->next;
    }
    return true;
}