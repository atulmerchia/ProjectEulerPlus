#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MOD = 1000;

vector<int> add(vector<int> a, vector<int> x){
    vector<int> num = a;
    long carry = 0, dig;

    if(x.size() > num.size())
        for(int i = num.size(); i < x.size(); i++)
            num.insert(num.begin(), 0);
    else
        for(int i = x.size(); i < num.size(); i++)
            x.insert(x.begin(), 0);

    for(int ind = num.size() - 1; ind >= 0; ind--){
        dig = num[ind] + x[ind] + carry;
        num[ind] = dig % MOD;
        carry = dig / MOD;
    }
    while(carry){
        num.insert(num.begin(), carry % MOD);
        carry /= MOD;
    }
    return num;
}

vector<int> times(vector<int> v, long mult){
    vector<int> num = v;
    long carry = 0, dig;
    for(int i = v.size() - 1; i >= 0; i--){
        dig = num[i] * mult + carry;
        num[i] = dig % MOD;
        carry = dig / MOD;
    }
    while(carry){
        num.insert(num.begin(), carry % MOD);
        carry /= MOD;
    }

    return num;
}

int main() {
    int n;
    cin >> n;

    vector<int> a = {0}, b = {1}, c = {2};

    for(int i = 2; i <= n; i++){
        int mult = 1;
        if(i % 3 == 0) mult = i / 3 * 2;

        a = b;
        b = c;
        c = add(a, times(b, mult));
    }

    int sum = 0;
    for(int i : c){
        while(i){
            sum += i % 10;
            i /= 10;
        }
    }
    cout << sum;

    return 0;
}
