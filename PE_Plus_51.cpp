#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int primes[10000000];

void precompute(){
    for(int i = 3; i < 10000000; i+=2)
        primes[i] = true;
    primes[2] = true;
    for(int i = 3; i < sqrt(10000000); i+=2){
        if(!primes[i]) continue;
        for(int j = i*i; j < 10000000; j+=2*i)
            primes[j] = false;
    }
}

bool verify(string s, string mask, int l){
    if(l == 1){
        cout << s << endl;
        return true;
    }

    string out = s + " ";

    char val = '?';
    for(int i = 0; i < mask.length(); i++){
        if(mask[i] == ' ') continue;
        if(val == '?') val = s[i];
        else if(s[i] != val) return false;
        s[i] = '.';
    }

    l--;

    for(int i = 0; i < 10; i++){
        if(i == 0 && s[0] == '.') continue;
        if(i == val - '0') continue;
        if(10-i < l) break;
        int num = 0;
        for(int j = 0; j < s.length(); j++){
            if(s[j] == '.')
                num = num * 10 + i;
            else
                num = num * 10 + s[j] - '0';
        }
        // cout << out << endl;
        if(primes[num]){
            l--;
            out += to_string(num) + " ";
            if(l == 0){
                cout << out << endl;
                return true;
            }
        }
    }
    return false;
}

// Test all masks: find any repeated digits, test their incrementations

int main() {
    if(!primes[2]) precompute();

    int n, k, l;
    cin >> n >> k >> l;

    // for numbers with (n-k) digits, create ascending mask, add k dots
    // go through permutations, replace with digits... if L family found, exit


    if(n == k){
        string out;
        int num;
        for(int i = 1; i < 10; i++){
            num = 0;
            for(int j = 0; j < n; j++)
                num = num * 10 + i;
            if(primes[num]){
                out += to_string(num) + " ";
                l--;
                if(l == 0){
                    cout << out << endl;
                    break;
                }
            }
        }
        return 0;
    }

    for(int i = pow(10, n-1) + 1; i < pow(10, n); i+=2){
        if(!primes[i]) continue;
        string mask = "";
        mask.insert(0, k, '.');
        mask.insert(0, n-k, ' ');

        do{
            if(verify(to_string(i), mask, l))
                return 0;
        }while(next_permutation(mask.begin(), mask.end()));
    }
    return 0;
}
