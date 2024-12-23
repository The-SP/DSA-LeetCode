// Pow(x, n)
#include <iostream>
using namespace std;

// 0(log n)
double myPow(double x, int n) {
    if (n == 0) return 1;
    if (x == 0) return 0;
    long long nn = n;
    double ans = 1.0;
    if (nn < 0) {
        nn = -nn;
        x = 1 / x;
    }
    while (nn) {
        if (nn % 2 == 1) ans = ans * x;
        x = x * x;
        nn = nn / 2;
    }
    return ans;
}

int main() {
    cout << myPow(2.1, 3) << endl;  // 9.261
    cout << myPow(1, -2147483648);   // 1
}