#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void solve(int, int);

int main() {
    int n, k;
    cin >> n >> k;
    solve(n, k);

    return 0;
}

void solve(int n, int k){
    string str = "";
    bool used[k+1];
    int mult = 0;

    for(int i = 2; i < n; i++){
        str = "";
        mult = i;
        while(str.size() < k){
            str += to_string(mult);
            mult += i;
        }
        if(str.size() > k)
            continue;
        for(int j = 0; j <= k; j++)
            used[j] = false;
        used[0] = true;
        for(char* c = &str[0]; *c != '\0'; c++)
            if(used[*c-'0'])
                goto skip;
            else
                used[*c-'0'] = true;
        cout << i << endl;
skip:;
    }
}
