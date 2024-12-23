// Fractional Knapsack Problem

#include <algorithm>
#include <iostream>
using namespace std;

// Structure for an item which stores weight and
// corresponding value of Item
struct Item {
    int value, weight;

    // Constructor
    Item(int value, int weight) {
        this->value = value;
        this->weight = weight;
    }
};

// Comarison function to sort Item according to greater val/weight ratio
bool comparator(Item a, Item b) {
    return double(a.value) / a.weight > double(b.value) / b.weight;
}

// Main greedy function to solve problem
double fractionalKnapsack(int W, struct Item arr[], int n) {
    sort(arr, arr + n, comparator); // sorting based on ratio
    int wt;
    double value = 0;
    for (int i = 0; i < n; i++) {
        wt = arr[i].weight;
        if (wt <= W) {
            W -= wt;
            value += arr[i].value;
        } else {
            value += (double)(W) / wt * arr[i].value;
            break;
        }
    }
    return value;
}

int main() {
    int W = 50; //    Weight of knapsack
    Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Maximum value we can obtain = "
         << fractionalKnapsack(W, arr, n);
    return 0;
}
