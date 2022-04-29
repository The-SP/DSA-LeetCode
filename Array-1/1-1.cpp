// Set Matrix Zeroes
#include <iostream>
#include <vector>
using namespace std;

void matrixZeroes(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    int cols0 = 1;

    for (int i = 0; i < m; i++) {
        if (matrix[i][0] == 0) cols0 = 0;
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 1; j--) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
        }
        if (cols0 == 0) matrix[i][0] = 0;
    }
}

void display(vector<vector<int>> arr) {
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[0].size(); j++)
            cout << arr[i][j] << ' ';
        cout << endl;
    }
}

int main() {
    vector<vector<int>> arr = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    matrixZeroes(arr);
    display(arr);
}