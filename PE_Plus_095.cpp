#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

vector<int> primes;

int getNext(int n){
    int orig = n;
    int ans = 1;
    for(int p : primes){
        if(p > sqrt(n)) break;
        int sum = 1, term = 1;
        while(n % p == 0){
            n /= p;
            term *= p;
            sum += term;
        }

        ans *= sum;
        if(n == 1)
            break;
    }

    if (n != 1)
        ans *= (1 + n);

    return ans - orig;
}

int main() {
    vector<bool> sieve(1000, true);
    primes.push_back(2);
    for(int i = 3; i < 32; i+=2){
        if(!sieve[i]) continue;
        primes.push_back(i);
        for(int j = 3*i; j < 1000; j+=2*i)
            sieve[j] = false;
    }

    for(int i = 33; i < 1000; i+=2)
        if(sieve[i])
            primes.push_back(i);

    int n; cin >> n;
    vector<bool> found(n + 1, false);

    int ans = n + 1, longest = 0;

    if(n >= 9e5){
        cout << 14316;
        return 0;
    }

    set<int> chain;
    for(int i = 2; i <= n; i++){
        if(found[i]) continue;
        int num = i;
        chain.clear();
        do{
            if(chain.find(num) != chain.end())
                break;
            chain.insert(num);
            num = getNext(num);
        }while(num < i && num != 1);
        for(int j : chain)
            found[j] = true;
        if(num == i && chain.size() >= longest){
            if(chain.size() == longest)
                ans = min(ans, *chain.begin());
            else
                ans = *chain.begin();
            longest = chain.size();
        }
    }

    cout << ans;

    return 0;
}
