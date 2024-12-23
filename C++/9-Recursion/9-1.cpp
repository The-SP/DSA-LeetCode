// Subset sum

#include<bits/stdc++.h>
using namespace std;

// Time: O(2^n) + O(2^n * log(2^n))
// Space: O(2^n) for storing 2^n subsets sums
void solve(int i, vector<int>& arr, int n, vector<int>& ans, int sum) {
    if (i == n) {
        ans.push_back(sum);
        return;
    }
    // Select element to add it to subset and move to next index (pick)
    solve(i+1, arr, n, ans, sum+arr[i]);
    // Not select element and move to next index (non-pick)
    solve(i+1, arr, n, ans, sum);
}

vector<int> subsetSums(vector<int> arr, int n) {
    vector<int> ans;
    solve(0, arr, n, ans, 0);
    return ans;
}

int main() {
  vector < int > arr{3,1,2};
  vector < int > ans = subsetSums(arr, arr.size());
  sort(ans.begin(), ans.end());
  cout<<"The sum of each subset is "<<endl;
  for (auto sum: ans)
    cout << sum << ' ';
} 