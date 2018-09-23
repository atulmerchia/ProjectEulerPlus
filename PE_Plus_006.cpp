#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        long sumToN = n * (n+1) / 2;
        long ans = 0;
        for(int i = 1; i <= n; i++)
            ans += i*(sumToN-i);
        cout << ans << endl;
    }
    return 0;
}
