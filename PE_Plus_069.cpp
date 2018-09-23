#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    vector<int> primes = {2};
    for(int i = 3; i < 200; i+=2){
        bool yes = true;
        for(int j : primes)
            if(i % j == 0){
                yes = false;
                break;
            }
        if(yes) primes.push_back(i);
    }

    int t;
    unsigned long long n;
    cin >> t;
    while(t--){
        cin >> n;
        unsigned long long prod = 1;
        for(int i : primes){
            if(n / i >= prod)
                prod *= i;
            else
                break;
            if(prod == n){
                prod /= i;
                break;
            }
        }
        cout << prod << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
