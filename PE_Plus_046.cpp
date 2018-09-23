#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

static bool isPrime [500000];
void getPrimes();

int main() {
    if(!isPrime[2]) getPrimes();

    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        int count = 0, delta = 3, square = 1;
        while(square < n/2){
            if(isPrime[n - 2*square]) count++;
            square += delta;
            delta += 2;
        }
        cout << count << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}

void getPrimes(){
    for(int i = 3; i < 500000; i += 2)
        isPrime[i] = true;

    isPrime[2] = true;
    for(int i = 3; i < sqrt(500000); i += 2){
        if(!isPrime[i]) continue;
        for(int j = i*3; j < 500000; j += 2*i)
            isPrime[j] = false;
    }
}
