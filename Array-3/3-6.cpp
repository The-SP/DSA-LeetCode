// Reverse Pairs
// (i, j) where 0 <= i < j < nums.length and nums[i] > 2 * nums[j]
#include <iostream>
#include <vector>
using namespace std;

// Time: O(N logN) + O(N)   Space: O(N)
int merge(vector<int> &nums, vector<int> &temp, int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    int count = 0;
    while (i <= mid && j <= right) {
        if (nums[i] > 2 * nums[j]) {
            count += mid - i + 1;
            j++;
        } else
            i++;
    }

    // Merge Sort
    i = k = left;
    j = mid + 1;
    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j])
            temp[k++] = nums[i++];
        else
            temp[k++] = nums[j++];
    }
    while (i <= mid)
        temp[k++] = nums[i++];
    while (j <= right)
        temp[k++] = nums[j++];
    for (int i = left; i <= right; i++)
        nums[i] = temp[i];
    return count;
}

int mergeSort(vector<int> &nums, vector<int> &temp, int left, int right) {
    int mid, count = 0;
    if (left < right) {
        mid = (left + right) / 2;
        count += mergeSort(nums, temp, left, mid);
        count += mergeSort(nums, temp, mid + 1, right);
        count += merge(nums, temp, left, mid, right);
    }
    return count;
}

int main() {
    vector<int> nums = {2, 4, 3, 5, 1}; // 3
    // vector<int> nums = {1,3,2,3,1}; // 2
    int n = nums.size();
    vector<int> temp(n);
    cout << mergeSort(nums, temp, 0, n - 1);
}