#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

static vector<long> primes;

int main() {
    if(!primes.size()){
        primes.resize(10000);
        primes[0] = 2;
        long p = 3;
        int ind = 1;
        while(ind < 10000){
            bool prime = true;
            for(long j : primes)
                if(p % j == 0){
                    prime = false;
                    break;
                }
                else if(j*j > p)
                    break;
            if(prime)
                primes[ind++] = p;
            p += 2;
        }
    }

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << primes[n-1] << endl;
    }

    return 0;
}
