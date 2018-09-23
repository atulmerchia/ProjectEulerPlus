#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    unsigned long long n;
    int deltaIncA, deltaIncB;
    cin >> n >> deltaIncA >> deltaIncB;
    unsigned long long a = 1, b = 1, incA, incB;
    deltaIncA -= 2;
    deltaIncB -= 2;
    incA = deltaIncA + 1;
    incB = deltaIncB + 1;
    while(a < n && b < n){
        if(a == b)
            cout << a << endl;
        if(a < b){
            a += incA;
            incA += deltaIncA;
        }
        else{
            b += incB;
            incB += deltaIncB;
        }
    }
    return 0;
}
