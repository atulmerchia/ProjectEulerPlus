#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n; cin >> n;

    unsigned long long arr [n][n];
    unsigned long long temp [n];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> arr[i][j];

    for (int i = 0; i < n; i++) {
        temp[i] = arr[i][n - 1];
    }

    for (int i = n - 2; i >= 0; i--) {
        temp[0] += arr[0][i];
        for (int j = 1; j < n; j++) {
            temp[j] = min(temp[j - 1] + arr[j][i], temp[j] + arr[j][i]);
        }

        for (int j = n - 2; j >= 0; j--) {
            temp[j] = min(temp[j], temp[j+1] + arr[j][i]);
        }
    }

    unsigned long long ans = temp[0];
    for(int i = 1; i < n; i++)
        ans = min(ans, temp[i]);

    cout << ans;

    return 0;
}
