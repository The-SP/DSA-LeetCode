// Minimum number of coins change

#include <iostream>
#include <vector>
using namespace std;

// Solution: Dynamic Programming
// Time: O(V*M) | Space: O(V)
int minCoins(int coins[], int M, int V) {
    vector<int> table(V + 1, INT_MAX); // To store min no of coins for 'i' value
    table[0] = 0;
    // Compute min coins for all values from 1 to V
    for (int i = 1; i <= V; i++) {
        for (int j = 0; j < M; j++) {
            if (coins[j] <= i) {
                int sub_res = table[i - coins[j]];
                if (sub_res != INT_MAX)
                    table[i] = min(table[i], sub_res + 1);
            }
        }
    }
    if (table[V] == INT_MAX) return -1;
    return table[V];
}

int main() {
    int V = 11, M = 4;
    int coins[] = {9, 6, 5, 1};
    cout << minCoins(coins, M, V);
    // Ans: 2 (Use 6, 5 coin)
}