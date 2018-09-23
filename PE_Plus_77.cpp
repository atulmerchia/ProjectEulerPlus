#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
static vector<ull> ans;

void getAns(){
    vector<int> primes;
    vector<int> sieve(1000, true);
    sieve[0] = sieve[1] = false;
    for(int i = 4; i < 1000; i+=2)
        sieve[i] = false;
    for(int i = 3; i < 32; i+=2)
        if(sieve[i])
            for(int j = 3*i; j < 1000; j+=2*i)
                sieve[j] = false;
    for(int i = 0; i < 1000; i++)
        if(sieve[i])
            primes.push_back(i);

    ans.resize(1001, 0);

    ans[0] = 1;
    for(int i : primes)
        for(int j = 0; j <= 1000 - i; j++)
            ans[j + i] += ans[j];
}

int main() {
    if(!ans.size()) getAns();

    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        cout << ans[n] << endl;
    }

    return 0;
}
