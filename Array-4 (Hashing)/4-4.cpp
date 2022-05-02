// Largest sub-array with 0 sum
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int maxLen(vector<int> &A) {
    int n = A.size();
    int length = 0, sum = 0;
    unordered_map<int, int> hashSum;
    for (int i = 0; i < n; i++) {
        sum += A[i];
        if (sum == 0)
            length = i + 1;
        else if (hashSum.find(sum) != hashSum.end())
            length = max(length, i - hashSum[sum]);
        else
            hashSum[sum] = i;
    }
    return length;
}

int main() {
    vector<int> A = {15, -2, 2, -8, 1, 7, 10, 23};
    cout << maxLen(A);
}