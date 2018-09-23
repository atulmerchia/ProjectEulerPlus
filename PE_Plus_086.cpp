#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int combinations(int a, int b){
    if (2*a < b) return 0;

    if (a >= b) return b / 2;

    return a - (b - 1) / 2;
}

int main(){
    int limit = 1e6;
    vector<unsigned long long> arr(limit + 1, 0);

    for (int m = 1; m <= 1414; m++)
        for (int n = m % 2 + 1; n < m; n+=2){
            if (__gcd(m, n) != 1)
                continue;

            int x = m*m - n*n;
            int y = 2*m*n;

            for (int k = 1; k*x <= limit; k++)
                arr[k*x] += combinations(k*x, k*y);
            for (int k = 1; k*y <= limit; k++)
                arr[k*y] += combinations(k*y, k*x);
        }

    for(int i = 1; i < limit; i++)
        arr[i] += arr[i-1];

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << arr[n] << endl;
    }
}
