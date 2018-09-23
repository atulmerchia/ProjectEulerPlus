#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const long MOD = 1e9 + 7;
const int values [8] = {1, 2, 5, 10, 20, 50, 100, 200};

int main() {
    long long answer[100001];
    for(long long &a : answer) a = 0;
    answer[0] = 1;

    for (int i = 0; i < 8; i++)
        for (long long j = values[i]; j < 100001; j++)
            answer[j] = (answer[j] + answer[j - values[i]]) % MOD;

    long long t = 0;
    cin >> t;
    long long n = 0;
    while(t--){
        cin >> n;
        cout << answer[n] << endl;
    }

    return 0;
}
