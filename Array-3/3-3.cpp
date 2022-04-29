// Majority element (>N/2 times)
#include <iostream>
using namespace std;

// O(n)
int majorityElement(int arr[], int n) {
    int count = 0, element = 0;
    for (int i = 1; i < n; i++) {
        if (count == 0)
            element = arr[i];
        (element == arr[i]) ? count++ : count--;
    }
    return element;
}

int main() {
    int arr[] = {4, 4, 2, 4, 3, 4, 4, 3, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << majorityElement(arr, n);
}