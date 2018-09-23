#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b){
    if(b < a)
        swap(a, b);
    while(a){
        int temp = a;
        a = b % a;
        b = temp;
    }
    return b;
}

int main() {
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        long ans = 1;
        for(int i = 2; i <= n; i++)
            if(ans % i)
                ans *= i / gcd(i, ans);
        cout << ans << endl;
    }
    return 0;
}
