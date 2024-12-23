// Kadane's Algorithm
#include <iostream>
#include <vector>
using namespace std;

// O(n^2): display sub array and max length
void maxSubArray(vector<int> arr) {
    int n = arr.size();
    int subArray[2] = {0};
    int sum = 0, max = 0;
    for (int i = 0; i < n; i++) {
        sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            if (sum > max) {
                max = sum;
                subArray[0] = i;
                subArray[1] = j;
            }
        }
    }
    cout << "max = " << max << endl;
    for (int i = subArray[0]; i <= subArray[1]; i++)
        cout << arr[i] << ' ';
}

void kadane(vector<int> arr) {
    int n = arr.size();
    int sum = 0, max = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum > max) max = sum;
        if (sum < 0) sum = 0;
    }
    cout << endl
         << max;
}

// Kadane fails if array only consits of -ve integers
// Using dynamic programming to solve in O(n)
void dynamic(vector<int> arr) {
    int n = arr.size();
    vector<int> dp(n);
    dp[0] = arr[0];
    int max = dp[0];
    for (int i = 1; i < n; i++) {
        dp[i] = arr[i] + (dp[i - 1] > 0 ? dp[i - 1] : 0);
        if (dp[i] > max) max = dp[i];
    }
    cout << endl
         << max;
}

int main() {
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    maxSubArray(arr);
    kadane(arr);
    dynamic(arr);
}