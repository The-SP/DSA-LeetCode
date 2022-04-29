// Max profit
#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> &prices) {
    int n = prices.size();
    int min = prices[0], max = 0;
    for (int i = 1; i < n; i++) {
        if (prices[i] < min)
            min = prices[i];
        else if (prices[i] - min > max)
            max = prices[i] - min;
    }
    return max;
}

int main() {
    vector<int> prices = {7, 6, 4, 3, 1};
    cout << maxProfit(prices);
}