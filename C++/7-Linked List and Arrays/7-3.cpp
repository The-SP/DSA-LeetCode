// 3 sum
// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Brute force
// Time: O(n^3) || Space: O(3*k) // k is no of triplets
void threeSum(vector<int> &nums) {
    int n = nums.size();
    vector<vector<int>> result;
    vector<int> triplet;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    triplet = vector<int>({nums[i], nums[j], nums[k]});
                    result.push_back(triplet);
                }
            }
        }
    }
    for (auto vec : result) {
        for (int it : vec) {
            cout << it << ' ';
        }
        cout << endl;
    }
}


// Solution 2 (Optimized) : Two pointer approach
// Time: O(n^2) | Space: O(m)
void threeSum2(vector<int> nums) {
    int n = nums.size();
    vector<vector<int>> result;
    vector<int> triplet;
    sort(nums.begin(), nums.end());
    int start, end, target, twoSum;

    for (int i = 0; i < n - 2; i++) {
        if (i > 0 && nums[i] == nums[i-1])
            continue; // skip
        target = 0 - nums[i];
        start = i + 1;
        end = n - 1;
        while (start < end) {
            twoSum = nums[start] + nums[end];
            if (twoSum == target) {
                triplet = vector<int>({nums[i], nums[start], nums[end]});
                result.push_back(triplet);

                while (start < end && nums[start] == nums[start+1]) start++;
                while (start < end && nums[end] == nums[end-1]) end--;
                start++, end--;
            } else if (twoSum > target)
                end--;
            else
                start++;
        }
    }
    for (auto vec : result) {
        for (int it : vec) {
            cout << it << ' ';
        }
        cout << endl;
    }
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    threeSum(nums);
    cout << endl;
    threeSum2(nums);
}