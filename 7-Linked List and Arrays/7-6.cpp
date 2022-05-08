// Count max consecutive ones

#include <iostream>
#include <vector>
using namespace std;

// Time: O(n) | Space: O(1)
int findMaxConsecutiveOnes(vector<int> &nums) {
    int count = 0, maxCount = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 1) {
            count++;
            maxCount = max(count, maxCount);
        } else {
            count = 0;
        }
    }
    return maxCount;
}

int main() {
    vector<int> nums = {1, 1, 0, 2, 1, 1, 1, 3};
    cout << findMaxConsecutiveOnes(nums);
}