#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    // int max [] = {3, 15, 55, 175, 525, 1533, 4431, 12771, 36828, 106392, 308022, 893698};
    // int cat [] = {2,      5,       14,         42,          132,            429        };
    // int sol [] = {1,  5, 20,  70, 231,  735, 2289,  7029, 21384,  64636, 194480, 583232};
    //               1,  5, 20,  70, 231,  735, 2289,  7029, 21384,  64636, 194480, 583232,
    const int MOD = 1e9 + 7;

    vector<unsigned long long> fac(1e6 + 1);
    vector<unsigned long long> inv(1e6 + 1);
    fac[0] = 1;

    unsigned long long prod = 1;
    for(int i = 1; i <= 1e6; i++){
        prod = prod * i % MOD;
        fac[i] = prod;
    }

    for(int i = 0; i <= 1e6; i++){
        int m = MOD;
        int a = fac[i], y = 0, x = 1;

        while (a > 1){
            int q = a / m;
            int t = m;

            m = a % m, a = t;
            t = y;

            y = x - q * y;
            x = t;
        }

        if (x < 0)
            x += MOD;

        inv[i] = x;
    }

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        unsigned long long ms = 0;
        for(int k = 2; k <= n/2; k++){
            unsigned long long t = fac[n] * inv[2*k] % MOD;
            t = t * inv[n-2*k] % MOD;
            t = t * fac[2*k-1] % MOD;
            t = t * inv[k+1] %MOD;
            ms = (ms + t * inv[k-2] % MOD) % MOD;
        }
        cout << ms << endl;
    }

    // for set of size n:
        // for subsets of size i in range (2, n//2):
            // catalan i * (n choose 2i);
    // subtract this sum from total number of available set comparisons
        // sum(i = 2 to n/2) ( nCi * (n-i)Ci / 2 )
            // n!/i!i!(n-2i)!

    // faster combos: tabulate factorials and modular inverses

    return 0;
}
