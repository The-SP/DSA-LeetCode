// Clone a linked list (deep copy) with random and next pointer

Node* copyRandomList(Node* head) {
    Node* ptr = head;
    unordered_map<Node*, Node*> hash;

    // Create copy of each node with correct value and default next and random ptr
    while (ptr) {
        hash[ptr] = new Node(ptr->val);
        ptr = ptr->next;
    }

    // Set correct next and random ptr of copy list
    ptr = head;
    while (ptr) {
        hash[ptr]->next = hash[ptr->next];
        hash[ptr]->random = hash[ptr->random];
        ptr = ptr->next;
    }
    return hash[head];
}