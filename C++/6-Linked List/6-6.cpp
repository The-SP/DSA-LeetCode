// Flattening of linked list

// Time: O(n) | Space: O(1)

// like merge sort, merge two lists
Node *merge(Node *a, Node *b) {
    Node *temp = new Node();
    Node *res = temp;
    while (a && b) {
        if (a->data <= b->data) {
            temp->bottom = a;
            temp = temp->bottom;
            a = a->bottom;
        } else {
            temp->bottom = b;
            temp = temp->bottom;
            b = b->bottom;
        }
    }
    if (a)
        temp->bottom = a;
    else
        temp->bottom = b;
    return res->bottom;
}

// returns the root of the flattened linked list
Node *flatten(Node *root) {
    if (root == NULL || root->next == NULL)
        return root;
    root->next = flatten(root->next);
    root = merge(root, root->next);
    return root;
}