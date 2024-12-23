// Sort 0's 1's 2's
#include <iostream>
#include <vector>
using namespace std;

void sortColors(vector<int>& nums) {
    int colors[3] = {0};
    int n = nums.size();
    for (int i=0; i<n; i++)
        colors[nums[i]]++;
    int i=0, j=0;
    while (i<n && j<3) {
        if (colors[j]-- > 0) nums[i++] = j;
        else j++;
    }
}

void display(vector<int> nums) {
    for (int i=0; i<nums.size(); i++)
        cout << nums[i] << ' ';
}

int main() {
    vector<int> arr = {2, 0, 2, 1, 1, 0};
    sortColors(arr);
    display(arr);
}