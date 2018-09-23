#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
ull mod = 1e9 + 7;

vector<ull> coef;
int n;

ull eval(ull x){
    unsigned __int128 res = 0;
    for(int i = n; i >= 0; i--)
        res = (res * x + coef[i]) % mod;
    return (ull) res;
}

int main(){
    cin >> n;
    coef.resize(n+1);

    for(ull & u : coef)
        cin >> u;

    ull val [n+1];
    for(int i = 1; i <= n; i++)
        val[i] = eval(i);

    vector<ull> res(n+1, 0);

    for(int i = 1; i <= n; i++)
        res[i] = val[i];

    for(int i = 1; i < n; i++)
        for(int j = n; j > i; j--){
            while(val[j] < val[j-1])
                val[j] += mod;
            val[j] -= val[j-1];
            res[j] = (res[j] + val[j]) % mod;
        }

    for(int i = 1; i <= n; i++)
        cout << res[i] << " ";

    return 0;
}

// f1  f2  f3

// 1   8   27
//     7   19
//         12

// +_________
// 1   15  58

// 10  49  142
//     39   93
//          54

// +__________
// 10  88  289
