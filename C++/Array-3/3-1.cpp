// Search in 2D matrix
#include <iostream>
#include <vector>
using namespace std;

void searchOMN(vector<vector<int>> &matrix, int target) {
    bool found = false;
    int m = matrix.size();
    int n = matrix[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == target) {
                found = true;
                i = m; // to break out of nested loop
                break;
            }
        }
    }
    cout << found;
}

// O(log(m*n))
bool binarySearch(vector<vector<int>> &matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    int beg = 0, end = (m * n - 1), mid;
    while (beg <= end) {
        mid = (beg + end) / 2;
        if (target == matrix[mid / n][mid % n])
            return true;
        else if (target > matrix[mid / n][mid % n])
            beg = mid + 1;
        else
            end = mid - 1;
    }
    return false;
}

int main() {
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    searchOMN(matrix, 13);
    cout << endl
         << binarySearch(matrix, 11);
}