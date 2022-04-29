// Inversion of array (Merge-Sort)
#include <iostream>
using namespace std;

int merge(int arr[], int temp[], int left, int mid, int right) {
    int count = 0;
    int i = left, j = mid, k = left;
    while (i < mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            count += mid - i;
        }
    }
    while (i < mid)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];
    for (int i = left; i <= right; i++)
        arr[i] = temp[i];

    return count;
}

int merge_Sort(int arr[], int temp[], int left, int right) {
    int mid, count = 0;
    if (left < right) {
        mid = (left + right) / 2;
        count += merge_Sort(arr, temp, left, mid);
        count += merge_Sort(arr, temp, mid + 1, right);
        count += merge(arr, temp, left, mid + 1, right);
    }
    return count;
}

int main() {
    int arr[] = {5, 3, 2, 1, 4};    // 7
    // int arr[] = {5, 4, 3, 2, 1}; // 10
    int n = 5;
    int temp[n];
    int ans = merge_Sort(arr, temp, 0, n - 1);
    cout << "The total inversions = " << ans << endl;
}