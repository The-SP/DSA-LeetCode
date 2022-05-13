// Subset-II | Print all the unique subsets

#include <iostream>
#include <vector>
using namespace std;

void display(vector<vector<int>>& ans) {
    for (auto vec: ans) {
        for (int it: vec)
            cout << it << ' ';
        cout << endl;
    }
}

void solve(int idx, vector<int>& nums, int n, vector<int>& subset, vector<vector<int>>& ans) {
    ans.push_back(subset);
    for (int i=idx; i<n; i++) {
        if (i!=idx && nums[i] == nums[i-1]) continue;
        subset.push_back(nums[i]);
        solve(i+1, nums, n, subset, ans);
        subset.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> subset;
    solve(0, nums, nums.size(), subset, ans);
    return ans;
}

int main() {
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> ans = subsetsWithDup(nums);
    display(ans);
}