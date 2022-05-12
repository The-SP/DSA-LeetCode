// Minimum railway platforms

#include <algorithm>
#include <iostream>
using namespace std;

// Solution 1: Brute Force
// Time: O(n^2) | Sapce: O(1)
int findPlatform(int arr[], int dep[], int n) {
    int count, ans = 1;
    for (int i = 0; i < n - 1; i++) {
        count = 1;
        // count no of overlapping time intervals
        for (int j = i + 1; j < n; j++) {
            if ((arr[i] >= arr[j] && arr[i] <= dep[j]) || (arr[j] >= arr[i] && arr[j] <= dep[i]))
                count++;
        }
        ans = max(ans, count);
    }
    return ans;
}


// Solution 2: Sorting
// Time: O(n*log n) | Space: O(1)
int countPlatform(int arr[], int dep[], int n) {
    sort(arr, arr + n);
    sort(dep, dep + n);
    // After sorting, now easy to track trains that have arrived but not departed yet
    int count = 1, ans = 1;
    int i = 1, j = 0;
    while (i < n && j < n) {
        if (arr[i] <= dep[j]) { // one more platform needed
            i++;
            count++;
        } else { // there is one extra platform that can be reduced
            j++;
            count--;
        }
        ans = max(ans, count); // find current maximum
    }
    return ans;
}

int main() {
    int arr[] = {900, 945, 955, 1100, 1500, 1800};
    int dep[] = {920, 1200, 1130, 1150, 1900, 2000};
    int n = sizeof(dep) / sizeof(dep[0]);
    cout << findPlatform(arr, dep, n) << endl;
    cout << countPlatform(arr, dep, n) << endl;
}