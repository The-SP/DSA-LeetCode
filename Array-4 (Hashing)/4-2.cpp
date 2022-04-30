#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Two pointers then remaining twoSum using other two pointer
void fourSum(vector<int> nums, int target) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    vector<int> quadruplet(4);
    int twoSum, target3, target2, left, right;

    for (int i = 0; i < n; i++) {
        target3 = target - nums[i];
        for (int j = i + 1; j < n; j++) {
            target2 = target3 - nums[j];
            left = j + 1;
            right = n - 1;
            while (left < right) {
                twoSum = nums[left] + nums[right];
                if (twoSum == target2) {
                    quadruplet = vector<int>({nums[i], nums[j], nums[left], nums[right]});
                    result.push_back(quadruplet);

                    // Processing the duplicates of number 3
                    while (left < right && nums[left] == quadruplet[2])
                        ++left;

                    // Processing the duplicates of number 4
                    while (left < right && nums[right] == quadruplet[3])
                        --right;
                } else if (twoSum > target2)
                    right--;
                else
                    left++;
            }

            // Processing the duplicates of number 2
            while (j + 1 < n && nums[j + 1] == nums[j])
                j++;
        }
        // Processing the duplicates of number 1
        while (i + 1 < n && nums[i + 1] == nums[i])
            i++;
    }

    for (auto vec : result) {
        for (int it : vec)
            cout << it << ' ';
        cout << endl;
    }
}

int main() {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    fourSum(nums, 0);
}