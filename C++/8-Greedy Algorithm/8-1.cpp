// N meetings in one room

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Time: O(n*log n) | Space: O(2n)
void maxMeetings(int start[], int end[], int n) {
    pair<int, int> meet[n];
    for (int i = 0; i < n; i++)
        meet[i] = pair<int, int>(end[i], i);
    // sort meetings according to their end time
    sort(meet, meet + n);
    vector<int> solution;
    solution.push_back(meet[0].second + 1);
    int limit = meet[0].first, count = 0;
    for (int i = 1; i < n; i++) {
        if (start[meet[i].second] > limit) {
            limit = meet[i].first;
            count++;
            solution.push_back(meet[i].second + 1);
        }
    }

    for (int it : solution)
        cout << it << ' ';
    cout << "\nCount = " << count;
}

int main() {
    int n = 6;
    int start[] = {1, 3, 0, 5, 8, 5};
    int end[] = {2, 4, 5, 7, 9, 9};
    maxMeetings(start, end, n);
}