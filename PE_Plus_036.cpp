#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long solve(long, int);
bool palindromeInBase(long, int);

int main() {
    int n, k;
    cin >> n >> k;
    cout << solve(n, k) << endl;

    return 0;
}

long solve(long n, int k){
    long sum = 0;
    for(long i = 1; i < n; i++){
        if(i % k == 0) continue;
        if(palindromeInBase(i, 10) && palindromeInBase(i, k))
            sum += i;
    }
    return sum;
}

bool palindromeInBase(long n, int k){
    long left = 1;
    while(left <= n)
        left *= k;
    if(left > 1)
        left /= k;

    int right = 1;

    while(left > right){
        if(n/left % k != n/right % k) return false;
        left /= k;
        right *= k;
    }
    return true;
}
