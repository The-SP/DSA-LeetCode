// Longest Consecutive sequence in an array
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

// Time: O(N*log N)+O(N)
int longestSequence(vector<int> arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int length = 1, max = 1;
    int current = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] == ++current) {
            length++;
            if (length > max) max = length;
        } else {
            current = arr[i];
            length = 1;
        }
    }
    return max;
}

// Time: O(N) | Space: O(N)
int longestSequenceHash(vector<int> arr) {
    int n = arr.size();
    set<int> hashSet;
    for (int num : arr)
        hashSet.insert(num);
    // set<int> hashSet(nums.begin(), nums.end());

    int maxLength = 0, length;
    for (int num : arr) {
        if (!hashSet.count(num - 1)) {
            length = 1;
            while (hashSet.count(num + length))
                length++;
            maxLength = max(length, maxLength);
        }
    }
    return maxLength;
}

int main() {
    vector<int> arr = {100, 200, 1, 3, 2, 4};
    cout << longestSequence(arr) << endl;
    cout << longestSequenceHash(arr);
}