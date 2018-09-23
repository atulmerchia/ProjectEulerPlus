#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n; cin >> n;
    unsigned long long ans = 3*n*n;

    // x1(x2 - x1) = - y1(y2 - y1)
    // x2 = x1 + ky1, y2 = y1 - kx1

    for(int x = 1; x <= n; x++)
        for(int y = 1; y <= n; y++){
            int k = __gcd(x, y);
            ans += min(k * (n - x) / y, k * y / x) * 2;
        }

    cout << ans;

    return 0;
}
