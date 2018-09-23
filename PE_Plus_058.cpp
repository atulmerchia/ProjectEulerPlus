#include <vector>
#include <iostream>
using namespace std;

typedef unsigned long long ull;

ull mult(ull x, ull y, ull m){
    if(x <= 0xFFFFFFF && y <= 0xFFFFFFF)
        return x * y % m;

    if(y > x) swap(x, y);

    ull res = 0;
    while(x && y){
        if(y & 1){
            res += x;
            if(res >= m)
                res -= m;
        }
        x <<= 1;
        y >>= 1;
        if(x >= m)
            x -= m;
    }

    return res;
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

const ull babyPrimeMask = 0b100000100010100010100010101100;
const int babyPrimes [] = {2, 3, 5, 7, 11, 13, 17};
const ull cutoffs [] = {5329, 9080191, 4759123141ULL, 1122004669633ULL};
const int testBases [][7] = {
    {377687, 0},
    {31, 73, 0},
    {2, 7, 61, 0},
    {2, 13, 23, 1662803, 0},
    {2, 325, 9375, 28178, 450775, 9780504, 1795265022}
};

bool isPrime(ull n) {
    if(n < 31)
        return (babyPrimeMask & (1 << n)) > 0;
    for(int i : babyPrimes)
        if(n % i == 0)
            return false;

    if(n < 17 * 19)
        return true;

    ull d = n - 1;
    d >>= 1;
    while ((d & 1) == 0)
        d >>= 1;

    auto baseSet = 4;
    for(int i = 0; i < 4; i++)
        if(cutoffs[i] > n){
            baseSet = i;
            break;
        }

    for(int a : testBases[baseSet])
        if(!a) break;
        else if(!millerRabin(a, d, n)) return false;
    return true;
}

int main(){
    int n; cin >> n;

    ull count = 3, corner = 9, side = 3;
    while(count * 100 >= (2*side - 1) * n){
        side += 2;
        for(int i = 0; i < 4; i++){
            corner += side - 1;
            if(isPrime(corner))
                count++;
        }
    }

    cout << side;
}
