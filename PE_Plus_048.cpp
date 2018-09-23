#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const unsigned long long mod = 1e10;
const unsigned long long cap = 1ULL << 32;
const unsigned long long blockSize = 30;
const unsigned long long bitMask = (1ULL << blockSize) - 1;

unsigned long long mult(unsigned long long a, unsigned long long b){
    if(a < cap && b < cap)
        return a * b % mod;

    unsigned long long ans = 0;
    while(a && b){
        ans = (ans + (b&bitMask) * a) % mod;
        b >>= blockSize;
        a <<= blockSize;
        a %= mod;
    }

    return ans;
}

unsigned long long power(unsigned long long x, unsigned long long y){
    unsigned long long ans = 1;
    while(y){
        if(y & 1)
            ans = mult(ans,x);
        y /= 2;
        x = mult(x, x);
    }
    return ans;
}

int main() {
    int N;
    cin >> N;

    unsigned long long tot = 0;
    for(int i = 1; i <= N; i++)
        tot = (tot + power(i, i)) % mod;

    cout << tot;
    return 0;
}
