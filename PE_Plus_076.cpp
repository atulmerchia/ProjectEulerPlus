#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int MOD = 1e9 + 7;

int solve(int n){
    vector<int> arr(n+1, 0);
    arr[0] = 1;

    for(int i = 1; i < n; i++)
        for(int j = i;  j <= n; j++)
            arr[j] = (arr[j] + arr[j-i]) % MOD;

    return arr[n];
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}
