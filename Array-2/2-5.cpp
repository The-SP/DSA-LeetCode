// Repeat and Missing number
#include <iostream>
#include <vector>
using namespace std;

void repeatAndMissing(vector<int> &arr) {
    int xor1 = arr[0];
    int n = arr.size();
    // X-OR of all array elements
    for (int i = 1; i < n; i++)
        xor1 ^= arr[i];
    // X-OR the result with no from 1 to n
    for (int i = 1; i <= n; i++)
        xor1 ^= i;

    // Result: x^y
    int last_bit = xor1 & 1; // get rightmost bit
    int x = 0, y = 0;
    /* Now divide elements into two sets by comparing a rightmost set bit
   of xor1 with the bit at the same position in each element.
   Also, get XORs of two sets. The two XORs are the output elements.
   The following two for loops serve the purpose */
    for (int i = 0; i < n; i++) {
        if (arr[i] & last_bit)
            x = x ^ arr[i]; // repeat
        else
            y = y ^ arr[i]; // missing
    }
    for (int i = 1; i <= n; i++) {
        if (i & last_bit)
            x = x ^ i;
        else
            y = y ^ i;
    }

    // NB! numbers can be swapped, maybe do a check ?
    int x_count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x)
            x_count++;
    }

    if (x_count == 0)
        cout << y << ' ' << x;
    else
        cout << x << ' ' << y;
}

int main() {
    vector<int> arr = {3, 1, 2, 5, 4, 6, 7, 5};
    repeatAndMissing(arr);
}