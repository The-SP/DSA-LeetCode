#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Two-Pointer Approach
// Time: O(N logN) | Space: O(1)
void twoSum(vector<int> &nums, int target) {
    vector<int> pair, copy;
    copy = nums;
    sort(copy.begin(), copy.end());
    int n = nums.size(), n1, n2;
    int left = 0, right = n - 1;
    while (left < right) {
        if (copy[left] + copy[right] == target) {
            n1 = copy[left];
            n2 = copy[right];
            break;
        } else if (copy[left] + copy[right] > target)
            right--;
        else
            left++;
    }
    for (int i = 0; i < n; i++)
        if (n1 == nums[i] || n2 == nums[i])
            pair.push_back(i);

    // Display
    for (int it : pair)
        cout << it << ' ';
    cout << endl;
}

// Hashing Method
// Time: O(N) | Space: O(N)
void twoSumHash(vector<int> &nums, int target) {
    int n = nums.size();
    vector<int> pair;
    unordered_map<int, int> hash;
    for (int i = 0; i < n; i++) {
        if (hash.find(target - nums[i]) != hash.end()) {
            pair.push_back(hash[target - nums[i]]);
            pair.push_back(i);
            break;
        }
        hash[nums[i]] = i;
    }

    // Display
    for (int it : pair)
        cout << it << ' ';
}

int main() {
    vector<int> nums = {3, 2, 4};
    twoSum(nums, 6);
    twoSumHash(nums, 6);
}