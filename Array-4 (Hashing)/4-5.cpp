// Count no of subArray with given X-Or K
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int subArray(vector<int> &A, int B) {
    int n = A.size();
    int xor1 = 0, count = 0;
    for (int i = 0; i < n; i++) {
        xor1 = 0;
        for (int j = i; j < n; j++) {
            xor1 ^= A[j];
            if (xor1 == B) count++;
        }
    }
    return count;
}

int subArrayHash(vector<int> &A, int B) {
    int n = A.size();
    unordered_map<int, int> hash;
    int xor1 = 0, count = 0;
    for (int i = 0; i < n; i++) {
        xor1 ^= A[i];
        if (xor1 == B)
            count++;
        else if (hash.find(xor1 ^ B) != hash.end())
            count += hash[xor1 ^ B];
        else
            hash[xor1]++;
    }
    return count;
}

int main() {
    // vector<int> A = {4, 2, 2, 4, 6};
    vector<int> A = {5, 6, 7, 8, 9};
    cout << subArray(A, 6) << endl;
    cout << subArrayHash(A, 6) << endl;
}