#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

static long answers[7];

long intVal(vector<int> a){
    long res = 0;
    for(int i : a)
        res = res * 10 + i;
    return res;
}

int main() {
    int divisors[7] = {2, 3, 5, 7, 11, 13, 17};

    int n; cin >> n;
    vector<int> a (n+1);
    for(int i = 0; i <= n; i++)
        a[i] = i;

    int i;
    long ans = 0;
    do{
        for(i = 3; i <= n; i++)
            if((100*a[i-2] + 10*a[i-1] + a[i]) % divisors[i-3] != 0)
                break;
        if(i > n)
            ans += intVal(a);
    }while(next_permutation(a.begin(), a.end()));
    cout << ans;
    return 0;
}
