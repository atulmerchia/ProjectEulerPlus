#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

static long answers [4];
static long pows[10];

static void precompute();
static long sumNum(int);

int main() {
    if(answers[0] == 0) precompute();
    int n = 0;
    cin >> n;
    cout << answers[n-3] << endl;
    return 0;
}

static void precompute(){
    int placeVal = 0;
    long sum = 0;
    long actualNum = 0;
    long max = 0;
    int logMax = 0;
    long exp = 0;

    for(int i = 3; i <= 6; i++){
        for(int j = 0; j < 10; j++)
            pows[j] = pow(j, i);

        actualNum = 100;

        max = 9;
        logMax = 1;
        exp = pow(9, i);

        while(max < exp * logMax){
            logMax++;
            max = max * 10 + 9;
        }
        max = exp * logMax;

        while(actualNum < max){
            sum = 0;
            if(sumNum(actualNum) == actualNum)
                answers[i-3] += actualNum;
            actualNum++;
        }
    }
}

static long sumNum(int n){
    long sum = 0;
    while(n > 0){
        sum += pows[n%10];
        n/=10;
    }
    return sum;
}
