#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

static bool isComposite [1000001];
long solve(long);
void getPrimes();

int main() {
    if(!isComposite[1]) getPrimes();

    long n;
    cin >> n;
    cout << solve(n) << endl;

    return 0;
}

long solve(long n){
    long sum = 0;

    if(n % 2 == 0)
        n--;

    long copyN;
    long logN;
    while(n > 10){
        copyN = n;
        logN = 1;
        while(copyN > 0){
            if(isComposite[copyN])
                break;
            logN *= 10;
            copyN /= 10;
        }
        logN /= 10;
        if(copyN != 0) logN = -1;
        // else cout << n << " " << logN << endl;

        while(logN > 0){
            if(isComposite[n % logN])
                break;
            logN /= 10;
        }
        if(logN == 0)
            sum += n;
        n -= 2;
    }
    return sum;
}

void getPrimes(){
    isComposite[1] = true;
    double root;
    for(long i = 4; i <= 1000000; i+=2)
        isComposite[i] = true;
    for(long i = 3; i <= 1000; i+=2){
        if(isComposite[i]) continue;
        for(long j = i*3; j <= 1000000; j += 2*i)
            isComposite[j] = true;
    }
}
