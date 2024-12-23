#include <iostream>
#include <vector>
using namespace std;

/**
 * L6: print all subsequences
 * L7: sub sequences of sum k
 *   - any one subsequence of sum k
 *   - count subsequences of sum k
*/

// Print all subsequences i.e Power Set
void allSubsequence(int i, vector<int> &arr, int n, vector<int> &ds) {
    if (i == n) {
        if (ds.empty()) cout << "{}";
        for (int it : ds)
            cout << it << ' ';
        cout << endl;
        return;
    }
    ds.push_back(arr[i]);
    allSubsequence(i + 1, arr, n, ds); // Take
    ds.pop_back();
    allSubsequence(i + 1, arr, n, ds); // Not-take
}

// Sub sequence of sum k
void sumK(int i, vector<int> &arr, int n, vector<int> &ds, int sum, int K) {
    if (i == n) {
        if (sum == K) {
            for (int it : ds)
                cout << it << ' ';
            cout << endl;
        }
        return;
    }
    ds.push_back(arr[i]);
    sumK(i + 1, arr, n, ds, sum + arr[i], K);
    ds.pop_back();
    sumK(i + 1, arr, n, ds, sum, K);
}

// Print any (only one) Sub sequence of sum k
// Find a solution and stop further recursive calls by returning bool value
bool anySumK(int i, vector<int> &arr, int n, vector<int> &ds, int sum, int K) {
    if (i == n) {
        if (sum == K) {
            for (int it : ds)
                cout << it << ' ';
            return true;
        }
        return false;
    }
    ds.push_back(arr[i]);
    if (anySumK(i + 1, arr, n, ds, sum + arr[i], K) == true) return true;
    ds.pop_back();
    if (anySumK(i + 1, arr, n, ds, sum, K) == true) return true;
    return false;
}

// Count sub-sequences of sum k
int countSumK(int i, vector<int> &arr, int n, int sum, int K) {
    if (i == n) {
        if (sum == K)
            return 1;
        return 0;
    }
    int l = countSumK(i + 1, arr, n, sum + arr[i], K); // Take
    int r = countSumK(i + 1, arr, n, sum, K); // Not-take
    return l + r;
}

int main() {
    // Print all subsequences
    vector<int> arr = {3, 2, 1};
    vector<int> ds;
    cout << "All subsequences:\n";
    allSubsequence(0, arr, arr.size(), ds);

    // Subsequence with sum K
    ds.clear();
    cout << "\nSubsequences with sum K:\n";
    sumK(0, arr, arr.size(), ds, 0, 3);

    // Any subsequence with sum K
    ds.clear();
    cout << "\nPrint any one Subsequence with sum K:\n";
    anySumK(0, arr, arr.size(), ds, 0, 3);

    // Count subsequences with sum K
    ds.clear();
    cout << "\nCount Subsequences with sum K:\n";
    cout << countSumK(0, arr, arr.size(), 0, 3);
}