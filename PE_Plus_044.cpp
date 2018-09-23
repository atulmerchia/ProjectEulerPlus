#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

auto pent(auto p){
    return p * (3*p - 1) / 2;
}

bool is_pentagonal(unsigned long long n){
    double dubN = (1 + sqrt(1 + 24 * n)) / 6.0;
    return dubN == static_cast<unsigned int>(dubN);

    // 0 = 3x^2 - x - 2P
    // x = 1 + sqrt(1 + 24P) / 6

    // 3xx - x + 1/12 = 2n + 3/4
    // (sqrt3 x - 1/2rt3) = 2n + 3/4
}

void process(unsigned long long n, unsigned long long k){
    for(unsigned long long p = k + 1; p <= n; p++){
        unsigned long long pent_p = pent(p);
        unsigned long long pent_k = pent(p-k);
        if(is_pentagonal(pent_p - pent_k) || is_pentagonal(pent_p + pent_k))
            cout << pent_p << endl;
    }
}

int main() {
    unsigned long long n, k;
    cin >> n >> k;
    process(n, k);
    return 0;
}
