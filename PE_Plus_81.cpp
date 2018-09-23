#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n; cin >> n;

    unsigned long long arr [n][n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> arr[i][j];

    for(int i = 1; i < n; i++){
        arr[0][i] += arr[0][i-1];
        arr[i][0] += arr[i-1][0];
    }

    for(int i = 1; i < n; i++)
        for(int j = 1; j < n; j++)
            arr[i][j] += min(arr[i-1][j], arr[i][j-1]);

    cout << arr[n-1][n-1];

    return 0;
}
