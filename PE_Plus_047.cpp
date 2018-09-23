#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

static int factors[2000004];
void getFactors();

int main() {
    if(factors[14] != 2) getFactors();

    int n, k;
    cin >> n >> k;

    int inARow = 0;
    for(int i = 2; i < n + k; i++){
        if(factors[i] == k){
            inARow++;
            if(inARow >= k)
                cout << i - k + 1 << endl;
        }
        else
            inARow = 0;
    }

    return 0;
}

void getFactors(){
    for(int i = 0; i < 2000000; i++)
        factors[i] = 0;
    for(int i = 2; i < 2000004; i++){
        if(factors[i] != 0) continue;
        for(int j = 2*i; j < 2000004; j+=i)
            factors[j]++;
    }
}
