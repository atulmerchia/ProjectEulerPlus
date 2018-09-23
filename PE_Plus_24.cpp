#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

static void precompute();

int main() {
    long fact[13] = {1,1};
    bool used [13];

    for(int i = 2; i < 13; i++)
        fact[i] = fact[i-1] * i;

    int t; cin >> t;

    while(t--){
        for(bool & b : used)
            b = false;
        int n; cin >> n;
        n--;
        for(int i = 12; i >= 0; i--){
            int q = n / fact[i];
            int index = 0;
            while(q)
                if(!used[index++])
                    q--;
            while(used[index])
                index++;
            used[index] = true;
            cout << (char)('a' + index);
            n %= fact[i];
        }
        cout << endl;
    }

    return 0;
}
