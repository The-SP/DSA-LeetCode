// Merge overlapping sub-intervals
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals) {
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> merged;
    for (int i=0; i<n; i++) {
        if (merged.empty() || merged.back()[1] < intervals[i][0]) {
            vector<int> temp = intervals[i];
            merged.push_back(temp);
        } else {
            merged.back()[1] = max(merged.back()[1], intervals[i][1]);
        }
    }
    return merged;
}

void display(vector<vector<int>> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[0].size(); j++)
            cout << arr[i][j] << ' ';
        cout << endl;
    }
}

int main() {
    vector<vector<int>> intervals = {{1, 3}, {2, 4}, {2, 6}, {8, 9}, {8, 10}, {9, 11}, {15, 18}, {16, 17}};;
    vector<vector<int>> merged = merge(intervals);
    display(merged);
}