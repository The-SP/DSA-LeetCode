// Majority elements (>N/3 times)
#include <iostream>
#include <vector>
using namespace std;

// Extended Boyer Moore's Voting algorithm
// O(n)
vector<int> majorityElement(int arr[], int n) {
    int c1 = 0, c2 = 0, e1 = 0, e2 = 0; // count, element/candidate
    for (int i = 0; i < n; i++) {
        if (e1 == arr[i])
            c1++;
        else if (e2 == arr[i])
            c2++;
        else if (c1 == 0) {
            e1 = arr[i];
            c1 = 1;
        } else if (c2 == 0) {
            e2 = arr[i];
            c2 = 1;
        } else {
            c1--;
            c2--;
        }
    }
    vector<int> majority;
    c1 = c2 = 0;
    for (int i = 0; i < n; i++) {
        if (e1 == arr[i])
            c1++;
        else if (e2 == arr[i])
            c2++;
    }
    if (c1 > n / 3) majority.push_back(e1);
    if (c2 > n / 3) majority.push_back(e2);
    return majority;
}

int main() {
    int arr[] = {2, 9, 9, 3, 9, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> majority = majorityElement(arr, n);
    for (int it : majority)
        cout << it << ' ';
}