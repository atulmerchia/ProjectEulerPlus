#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef vector<vector<ull>> matrix;
const ull mod = 1e9 + 9;
const int K = 61;

matrix mul(matrix a, matrix b){
    matrix c(K+1, vector<ull>(K+1, 0));
    for(int i = 1; i <= K; i++)
        for(int j = 1; j <= K; j++)
            for(int k = 1; k <= K; k++)
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % mod;
    return c;
}

matrix pow(matrix a, ull p){
    if(p == 1)
        return a;
    if(p & 1)
        return mul(a, pow(a, p-1));
    matrix x = pow(a, p/2);
    return mul(x, x);
}

int main() {
    vector<ull> f1(K+1, 0);
    f1[1] = 1;

    matrix T(K+1, vector<ull>(K+1, 0));

    for(int i = 1; i <= 20; i++){
        T[1][i]++;
        T[1][2*i]++;
        T[1][3*i]++;
        T[K][2*i]++;
    }
    T[1][25]++;
    T[1][50]++;
    T[K][50]++;

    for(int i = 2; i < K; i++)
        T[i][i-1] = 1;
    T[K][K] = 1;

    ull n; cin >> n;
    T = pow(T, n);

//     for(int i = 1; i <= K; i++){
//         for(int j = 1; j <= K; j++)
//             cout << T[i][j] << " ";
//         cout << endl;
//     }

//     for(int i = 1; i <= K; i++)
//         cout << f1[i] << " ";
//     cout << endl;

    cout << T[K][1];

    return 0;
}
