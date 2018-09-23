#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;

static vector<int> primes;

inline ull mul(ull a, ull b, ull c){
    return __int128(a)*b%c;
}

ull power(ull x, ull y, ull p){
    ull res = 1;

    while (y > 0){
        if (y & 1)
            res = mul(res, x, p);

        x = mul(x, x, p);
        y /= 2;
    }
    return res;
}

bool millerTest(ull d, ull n){
    ull a = 2 + rand() % (n - 4);
    ull x = power(a, d, n);

    if (x == 1  || x == n-1)
       return true;

    while (d != n-1){
        x = (x * x) % n;
        d *= 2;

        if (x == 1)      return false;
        if (x == n-1)    return true;
    }

    return false;
}

bool witness(ull n, ull d, ull s, ull a){
    ull x = power(a, d, n);
    ull y;

    while(s--){
        y = mul(x, x, n);
        if(y == 1 && x != 1 && x != n-1)
            return false;
        x = y;
    }

    if(y != 1) return false;
    return true;
}

bool isPrime(ull n){
    if(n == 2 || n == 3) return true;
    if(n < 2 || n % 2 == 0 || n % 3 == 0) return false;

    ull s = __builtin_ctzll(n-1);
    ull d = (n-1) >> s;

    for(ull p : primes){
        if(p == n) return true;
        if(!witness(n, d, s, p)) return false;
        if(p == 23) break;
    }

    return true;
}

bool isSquare(ull n){
    ull r = sqrt(n);
    return (r * r == n);
}

ull solve(ull n){
    ull ans = 1;
    for(ull p : primes){
        if(p > n || p > 1e6)
            break;
        ull count = 1;
        while(n % p == 0){
            count+=2;
            n /= p;
        }
        ans *= count;
    }

    if(n > 1){
        if(isPrime(n))
            ans *= 3;
        else if(isSquare(n))
            ans *= 5;
        else
            ans *= 9;
    }

    ans = (ans + 1) / 2;
    return ans;
}

void getPrimes(){
    primes.push_back(2);
    vector<bool>sieve(1e6, true);
    for(int i = 3; i < 1e3; i += 2){
        if(sieve[i]){
            primes.push_back(i);
            for(int j = 3*i; j < 1e6; j += 2*i)
                sieve[j] = false;
        }
    }
    for(int i = 1001; i < 1e6; i += 2)
        if(sieve[i])
            primes.push_back(i);
}

int main() {
    if(!primes.size()) getPrimes();
    int t; cin >> t;

    while(t--){
        ull n; cin >> n;
        cout << solve(n) << endl;
    }

    return 0;
}
