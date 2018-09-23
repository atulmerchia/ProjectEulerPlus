#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    // square: 3163
    // cube  :  216
    // fourth:   57

    vector<bool> sieve(3163, true);

    for(int i = 3; i < 57; i++)
        if(sieve[i])
            for(int j = i*3; j < 3163; j += 2*i)
                sieve[j] = false;

    vector<int> primes = {2};
    for(int i = 3; i < 3163; i+=2)
        if(sieve[i])
            primes.push_back(i);

    vector<int> squares, cubes, fourths;
    for(int i : primes)
        if(i > 3163) break;
        else squares.push_back(i*i);
    for(int i : primes)
        if(i > 216) break;
        else cubes.push_back(i*i*i);
    for(int i : primes)
        if(i > 57) break;
        else fourths.push_back(i*i*i*i);

    vector<long> ans(1e7 + 1, false);
    for(long i : squares)
        for(long j : cubes){
            long sum = i + j;
            if(sum > 1e7)
                break;
            else
                for(long k : fourths)
                    if(sum+k > 1e7)
                        break;
                    else
                        ans[sum+k] = 1;
        }

    for(int i = 1; i <= 1e7; i++)
        ans[i] += ans[i-1];

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << ans[n] << endl;
    }

    return 0;
}
