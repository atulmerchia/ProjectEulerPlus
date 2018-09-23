#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef unsigned long long ull;

bool sieve [20000];
vector<int> sums;

ull mult(ull x, ull y, ull m){
    return (unsigned __int128) x * y % m;
}

ull power(ull x, ull y, ull m){
    x %= m;
    y %= m;
    ull res = 1;
    while(y){
        if(y & 1)
            res = mult(res, x, m);
        y >>= 1;
        x = mult(x, x, m);
    }
    return res;
}

bool millerRabin(ull a, ull d, ull n) {
    ull x = power(a, d, n);

    if (x == 1  || x == n-1)
       return true;

    while (d != n-1) {
        x = mult(x, x, n);
        d *= 2;

        if (x == 1)      return false;
        if (x == n-1)    return true;
    }

    return false;
}

const int babyPrimes [] = {2, 3, 5, 7, 11, 13, 17};

bool isPrime(ull n) {
    if(n < 20000)
        return sieve[n];
    for(int i : babyPrimes)
        if(n % i == 0)
            return false;

    if(n < 17 * 19)
        return true;

    ull d = n - 1;
    do{
        d >>= 1;
    }while ((d & 1) == 0);

    if(n < 9080191){
        if(!millerRabin(31, d, n)) return false;
        return millerRabin(73, d, n);
    }

    if(!millerRabin(2, d, n)) return false;
    if(!millerRabin(7, d, n)) return false;
    return millerRabin(61, d, n);
}

int concat(int a, int b) {
	int mult = 10;
	while (mult < b) mult *= 10;
	return a * mult + b;
}

bool validPair(int a, int b){
    return isPrime(concat(a, b)) && isPrime(concat(b, a));
}

void testSet(int sum, vector<int> primes, int level){
    if(level == 0){
        sums.push_back(sum);
        return;
    }
    for(auto i = primes.begin(); i < primes.end(); i++){
        vector<int> pairs;
        for(auto j = i + 1; j < primes.end(); j++)
            if(validPair(*i, *j))
                pairs.push_back(*j);
        testSet(sum + *i, pairs, level - 1);
    }
}

int main() {
	vector<int> primes;

    memset(sieve, true, 20000);
	for (int i = 3; i < 141; i += 2) {
		if(!sieve[i])
            continue;
        primes.push_back(i);
        for(int j = 3*i; j < 20000; j += 2*i)
            sieve[j] = false;
	}
    for(int i = 149; i < 20000; i += 2)
        if(sieve[i])
            primes.push_back(i);

    int n, k;
	cin >> n >> k;

    primes.erase(primes.begin() + 1);
    for(auto i = primes.begin(); i < primes.end() && *i < n; i++){
        vector<int> pairs;
        for(auto j = i + 1; j < primes.end() && *j < n; j++)
            if(validPair(*i, *j))
                pairs.push_back(*j);
        testSet(*i, pairs, k-1);
    }

	sort(sums.begin(), sums.end());
	for (int i = 0; i < sums.size(); i++)
		cout << sums[i] << endl;

	return 0;
}
