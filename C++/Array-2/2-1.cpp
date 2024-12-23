// Rotate 2D matrix by 90deg
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<vector<int>> &matrix) {
    int n = matrix.size();
    // Transpose of the matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            swap(matrix[i][j], matrix[j][i]);

    // Reverse each row of the matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n / 2; j++)
            swap(matrix[i][j], matrix[i][n - 1 - j]);
}

void display(vector<vector<int>> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[0].size(); j++)
            cout << arr[i][j] << ' ';
        cout << endl;
    }
}

int main() {
    vector<vector<int>> matrix = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    rotate(matrix);
    display(matrix);
}