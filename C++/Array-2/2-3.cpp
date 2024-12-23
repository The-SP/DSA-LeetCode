// Merge sorted Array
#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &nums1, vector<int> &nums2, int m, int n) {
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (i >= 0 && j >= 0) {
        if (nums1[i] >= nums2[j])
            nums1[k--] = nums1[i--];
        else
            nums1[k--] = nums2[j--];
    }
    while (i >= 0)
        nums1[k--] = nums1[i--];
    while (j >= 0)
        nums1[k--] = nums2[j--];

    for (auto it : nums1)
        cout << it << ' ';
}

int main() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0}, nums2 = {2, 5, 6}; // Output: {1,2,2,3,5,6}
    merge(nums1, nums2, 3, 3);
}