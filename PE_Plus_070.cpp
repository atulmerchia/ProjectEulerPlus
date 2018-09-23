#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

static vector<int> primes;

bool valid(int a, int b){
    int arr [10];
    for(int &i : arr)
        i = 0;
    while(a){
        arr[a % 10]++;
        a /= 10;
    }
    while(b){
        arr[b % 10]--;
        b /= 10;
    }
    for(int i : arr)
        if(i)
            return false;
    return true;
}

void getPrimes(){
    primes = {2};
    int RT = sqrt(1e7);
    for(int i = 3; i <= RT; i+=2){
        int rt = sqrt(i);
        bool yes = true;
        for(int j : primes){
            if(i % j == 0){
                yes = false;
                break;
            }
            if(j >= rt)
                break;
        }
        if(yes)
            primes.push_back(i);
    }
}

int phi(int x, double min){
    int n = x;
    int tot = n;
    for(int i : primes){
        if(n % i)
            continue;
        if(i * i > n)
            break;
        tot -= tot / i;
        do{
            n /= i;
        }while(n % i == 0);
        if(tot * min < x)
            return tot;
    }

    if(n == x)
        return x - 1;
    if(n > 1)
        tot -= tot / n;
    return tot;
}

int main() {
    if(!primes.size()) getPrimes();

    int n;
    cin >> n;
    double rt = sqrt(n);

    int ans = 2;
    double best = 1e7 + 1;

    for(int i = 3; i < n; i++){
        int tot = phi(i, best);
        if((double) i / tot >= best)
            continue;
        if(!valid(i, tot))
            continue;
        best = (double) i / tot;
        ans = i;
    }

    cout << ans;

    return 0;
}
