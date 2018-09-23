#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        int tree [n][n+2];
        for(int i = 0; i < n; i++){
            tree[i][0] = 0;
            tree[i][i+2] = 0;
            tree[i][i+3] = 0;
        }
        cin >> tree[0][1];
        for(int i = 1; i < n; i++){
            for(int j = 1; j <= i+1; j++){
                cin >> tree[i][j];
                int a = tree[i-1][j-1];
                int b = tree[i-1][j];
                if(a < b) a = b;
                b = tree[i-1][j];
                if(a < b) a = b;
                tree[i][j] += a;
            }
        }
        int max = 0;
        for(int i = 1; i <= n; i++)
            if(max < tree[n-1][i]) max = tree[n-1][i];
        cout << max << endl;
    }
    return 0;
}
