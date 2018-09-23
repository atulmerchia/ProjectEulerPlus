#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

static vector<int> longestCycles;

static void precompute();
static bool isPrime(int);
static long findCycleLen(int);

int main() {
    if(longestCycles.size() < 10) precompute();
    int t = 0;
    cin >> t;
    int n = 0;
    int i = 0;
    while(t--){
        cin >> n;
        for(i = 0; longestCycles[i] < n && i < longestCycles.size(); i++);
        cout << longestCycles[i-1] << endl;
    }
    return 0;
}

static void precompute(){
    long len = 0;
    long lenToBeat = 0;
    longestCycles.push_back(3);
    for(int i = 7; i < 10000; i+=2){
        if(!isPrime(i)) continue;
        len = findCycleLen(i);
        if(len > lenToBeat){
            longestCycles.push_back(i);
            lenToBeat = len;
        }
    }
}

static bool isPrime(int n){
    double cap = sqrt(n);
    for(int i = 3; i <= cap; i += 2)
        if(n % i == 0)
            return false;
    return true;
}

static long findCycleLen(int n){
    long len = 1;
    int dividend = 10;
    do{
        dividend = (dividend * 10) % n;
        len++;
    }while(dividend != 1);
    return len;
}
