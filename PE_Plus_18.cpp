#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solve(int[][16], int);

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t = 0;
    cin >> t;
    int n = 0;
    for(int i = 0; i < t; i++){
        cin >> n;
        int stairs [n][16];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < 16; j++)
                stairs[i][j] = 0;
        for(int i = 0; i < n; i++){
            for(int j = 1; j <= i+1; j++)
                cin >> stairs[i][j];
        }
        cout << solve(stairs, n) << endl;
    }
    return 0;
}

int solve(int stairs[][16], int n){
    int solution[n+1][n+1];
    for(int i = 0; i < n+1; i++)
        for(int j = 0; j < n+1; j++)
            solution[i][j] = 0;
    solution[0][1] = stairs[0][1];
    int left, right;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i+1; j++){
            left = solution[i-1][j-1];
            right = solution[i-1][j];
            if(left > right)
                solution[i][j] = stairs[i][j] + left;
            else
                solution[i][j] = stairs[i][j] + right;
        }
    int best = 0;
    for(int i = 0; i < n+1; i++)
        if(best < solution[n-1][i])
            best = solution[n-1][i];
    return best;
}
