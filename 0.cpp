// Snippets

// Display 1D-Vector
void display(vector<int> arr) {
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << ' ';
}

// Display 2D-Vector
void display(vector<vector<int>> arr) {
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[0].size(); j++)
            cout << arr[i][j] << ' ';
        cout << endl;
    }
}

// Init 2D-vector
vector<vector<int>> arr = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
display(arr);

// Size of 2D-vector
int m = matrix.size();
int n = matrix[0].size();

// Linked List

// Count no of nodes
ListNode *ptr = head;
int i = 0;
while (ptr) {
    ptr = ptr->next;
    i++;
}