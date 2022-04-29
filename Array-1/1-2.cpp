// Pascal Triangle
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> pascal(int n) {
    vector<vector<int>> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i].resize(i + 1);
        arr[i][0] = arr[i][i] = 1;
        for (int j = 1; j <= i-1; j++) {
            arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
        }
    }
    return arr;
}

void display(vector<vector<int>> arr) {
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j <= i; j++)
            cout << arr[i][j] << ' ';
        cout << endl;
    }
}

int main() {
    vector<vector<int>> arr = pascal(5);
    display(arr);
}