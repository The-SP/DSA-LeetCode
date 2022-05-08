// Remove duplicates from sorted array

#include <iostream>
#include <vector>
using namespace std;

// Two pointers method
// Time: O(n) | Space: O(1)
int removeDuplicates(vector<int> &nums) {
    int k = 0;
    for (int i = 1; i < nums.size(); i++)
        if (nums[i] != nums[k])
            nums[++k] = nums[i];
    return k + 1;
    for (int i = 0; i < k + 1; i++) {
        cout << nums[i] << ' ';
    }
    return k + 1;
}

int main() {
    vector<int> nums = {1, 1, 2};
    cout << removeDuplicates(nums);
}