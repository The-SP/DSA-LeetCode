// Job Sequencing Problem

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

struct Job {
    int id, dead, profit;
};

bool comparator(Job a, Job b) {
    return a.profit > b.profit;
}

// Time: O(n*log n) + O(n*m)
// Space: O(m) where m = max deadline
pair<int, int> jobSchedule(Job arr[], int n) {
    // Sort job according to greater profit
    sort(arr, arr+n, comparator);
    // Find max deadline
    int maxDead = arr[0].dead;
    for (int i=1; i<n; i++)
        maxDead = max(maxDead, arr[i].dead);
    // Create slots of size maxDead
    vector<bool> slots(maxDead+1, false);
    int jobs = 0, profit = 0;
    for (int i=0; i<n; i++) {
        // For every job check empty slot from its last day
        for (int j=arr[i].dead; j>0; j--) {
            if (slots[j] == false) {
                slots[j] = true;
                profit += arr[i].profit;
                jobs++;
                break;
            }
        }
    }
    return make_pair(jobs, profit);
}

int main() {
    int n = 4;
    Job arr[n] = {{1, 4, 20}, {2, 1, 10}, {3, 2, 40}, {4, 2, 30}};
    pair<int, int> ans = jobSchedule(arr, n);
    cout << ans.first << " " << ans.second;
}