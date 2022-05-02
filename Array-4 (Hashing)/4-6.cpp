// Longest substring without repeat
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Brute force Approach
// Time: O(N2) | Space: O(N)
int longestSubstring(const string &s) {
    int maxLen = 0, i, j;
    for (i = 0; i < s.length(); i++) { // outer loop for traversing the string
        unordered_set<char> set;
        for (j = i; j < s.length(); j++) { // nested loop for getting different substring starting with str[i]
            if (set.find(s[j]) != set.end())
                break;
            set.insert(s[j]);
        }
        maxLen = max(maxLen, j - i);
    }
    return maxLen;
}

// Optimized approach
// Time: O(N) | Space: O(N)
int longestSubstringOptimized(string s) {
    unordered_map<char, int> hash;
    int maxLen = 0, start = -1;
    for (int i = 0; i != s.length(); i++) {
        if (hash.find(s[i]) != hash.end() && hash[s[i]] > start)
            start = hash[s[i]];
        hash[s[i]] = i;
        maxLen = max(maxLen, i - start);
    }
    return maxLen;
}

int main() {
    cout << longestSubstring("abcaabcdba") << endl;
    cout << longestSubstringOptimized("abcaabcdba");
}