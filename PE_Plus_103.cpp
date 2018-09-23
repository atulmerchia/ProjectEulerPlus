#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long MOD = 715827881;

int main() {
    int n; cin >> n;
    vector<long> S = {1};
    vector<long> subs = {1};
    int subDex = 0;
    int b = 1;
    bool minus = false;
    for(int i = 1; i < n; i++){
        subs.push_back(b);
        b *= 2;
        if(minus)
            b -= subs[subDex++];
        minus = !minus;
        if(b < 0) b += MOD;
        else b %= MOD;
    }
    b = 0;
    auto it = subs.end();
    while(it-- != subs.begin()){
        b = (b + *it) % MOD;
        cout << b << " ";
    }
    return 0;
}
