#include <vector>
#include <iostream>
using namespace std;

typedef unsigned long long ull;

ull mult(ull x, ull y, ull m){
    if(x <= 0xFFFFFFF && y <= 0xFFFFFFF)
        return x * y % m;

    int blockSize = 0;
    ull mask = 1ULL << 63;
    while(!(mask & m)){
        blockSize++;
        mask >>= 1;
    }
    mask = (1 << blockSize) - 1;

    ull ans = 0;
    while(x && y){
        ans = (ans + (y & mask) * x) % m;
        y >>= blockSize;
        x <<= blockSize;
        x %= m;
    }

    return ans;
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

ull getRand(){
    int res = 0;
    for(int i = 0; i < 3; i++)
        res = res * 10000 + rand() % 10000;
    return res;
}

bool millerRabin(ull d, ull n) {
    ull a = 2 + getRand() % (n - 2);

    ull x = power(a, d, n);

    if (x == 1  || x == n-1)
       return true;

    while (d != n-1) {
        x = mult(x, x, n);
        d *= 2;

        if (x == 1)      return true;
        if (x == n-1)    return true;
    }

    return false;
}

bool isPrime(ull n, int k = 10) {
    if(n == 2 || n == 3) return true;
    if(n <= 4) return false;

    ull d = n - 1;
    while (d % 2 == 0)
        d /= 2;

    for (int i = 0; i < k; i++)
         if (!millerRabin(d, n))
              return false;

    return true;
}

int main(){
    vector<int> primes = {2};
    vector<ull> sums = {2};
    for(int i = 3; primes.size() < 400000; i+=2){
        bool yes = true;
        for(int j : primes)
            if(j*j > i)
                break;
            else if(i % j == 0){
                yes = false;
                break;
            }
        if(yes){
            primes.push_back(i);
            sums.push_back(i + sums.back());
        }
    }

    int t; cin >> t;
    while(t--){
        ull n; cin >> n;
        ull maxSum = 2;
        int maxLen = 1;

        int start = 0;
        while(primes[start] < 150 && primes[start] < n){
            ull sub = start ? sums[start-1] : 0;
            int maxEnd = start + maxLen;
            while(sums[maxEnd] - sub <= n)
                maxEnd++;
            maxEnd--;

            while(maxEnd - start >= maxLen){
                ull sum = sums[maxEnd] - sub;
                if(isPrime(sum)){
                    maxLen = maxEnd - start + 1;
                    maxSum = sum;
                    break;
                }
                maxEnd--;
            }
            start++;
        }

        cout << maxSum << " " << maxLen << endl;
    }
}
