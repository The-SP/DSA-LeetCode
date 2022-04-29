// Duplicate in array of N+1 integers
#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(vector<int> &nums) {
    int n = nums.size();
    vector<int> count(n);
    for (int i = 0; i < n; i++)
        if (count[nums[i]] == 0)
            count[nums[i]]++;
        else
            return nums[i];
    return 0;
}

int main() {
    vector<int> arr = {1, 3, 4, 2, 2};
    cout << findDuplicate(arr);
}