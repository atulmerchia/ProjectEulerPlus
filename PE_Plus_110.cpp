#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;

const unsigned primes [] {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

struct fac{
    long double n;
    vector<unsigned char> e;
    ull x;

    bool operator<(const fac other) const{
        return n > other.n;
    }
};

ull bestX = 0;

void print(vector<unsigned char> count){
    for(auto &i : count)
        i /= 2;
    int mod = 1e5;
    vector<int> big = {1};
    for(int i = 0; i < 25; i++){
        if(count[i] == 0)
            break;
        int p = primes[i];
        for(int j = 0; j < count[i]; j++){
            int carry = 0;
            for(int i = 0; i < big.size(); i++){
                carry += big[i] * p;
                big[i] = carry % mod;
                carry /= mod;
            }
            while(carry){
                big.push_back(carry % mod);
                carry /= mod;
            }
        }
    }

    cout << big[big.size() - 1];
    for(int i = big.size() - 2; i >= 0; i--)
        cout << setw(5) << setfill('0') << big[i];
}

int main() {
    ull minProd; cin >> minProd;
    minProd = minProd * 2 - 1;

    priority_queue<fac> q;

    q.push({1, vector<unsigned char>(25, 1), 1});

    while(true){
        auto f = q.top();
        auto val = f.n;
        auto exp = f.e;
        auto ans = f.x;
        q.pop();

        if(ans >= minProd){
            print(exp);
            break;
        }
        if(ans > bestX)
            bestX = ans;
        else
            continue;

        for(int i = 0; i < 25; i++){
            exp[i]+=2;
            ans = ans * exp[i] / (exp[i] - 2);
            val *= primes[i];
            q.push({val, exp, ans});
        }
    }

    return 0;
}
