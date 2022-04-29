// Grid unique paths
#include <iostream>
#include <vector>
using namespace std;

int recursivePath(int m, int n, int i, int j) {
    if (i == m - 1 && j == n - 1)
        return 1;
    if (i >= m || j >= n)
        return 0;
    return recursivePath(m, n, i + 1, j) + recursivePath(m, n, i, j + 1);
}

int dynamicPath(int m, int n, int i, int j, vector<vector<int>> &dp) {
    if (i == m - 1 && j == n - 1)
        return 1;
    if (i >= m || j >= n)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    return dp[i][j] = dynamicPath(m, n, i + 1, j, dp) + dynamicPath(m, n, i, j + 1, dp);
}

int main() {
    cout << recursivePath(3, 2, 0, 0) << endl; // 3
    cout << recursivePath(3, 7, 0, 0) << endl; // 28
    int m = 3, n = 7;
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    cout << dynamicPath(m, n, 0, 0, dp);
}