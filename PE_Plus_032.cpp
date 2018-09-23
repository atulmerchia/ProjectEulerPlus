#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solve(int);

int main() {

    // 4 -> 1x1 = 2
    // 5 -> 1x2 = 2
    // 6 -> 1x2 = 3
    // 7 -> 2x2 = 3
    // 8 -> 2x2 = 4
    //   -> 1x3 = 4
    // 9 -> 2x3 = 4
    //   -> 1x4 = 4

    int n = 0;
    cin >> n;
    cout << solve(n) << endl;

    return 0;
}

void permute(long k, string &s) {
    long k0 = k;
    for(int j = 1; j < s.size(); ++j){
        swap(s[k % (j + 1)], s[j]);
        k = k / (j + 1);
    }
}

int solve(int n){
    int sum = 0;

    int seg1Max = (n-1)/3;
    int seg2 = 0;
    int seg3 = n/2;

    long fact = 1;

    string s = "123456789";
    s = s.substr(0, n);
    int fact1, fact2, prod;
    int index = 0;

    vector<int> found;

    for(int seg1 = seg1Max - n/8; seg1 <= seg1Max; seg1++){
        seg2 = n - seg3;

        fact = 1;
        for(int i = 2; i <= n; i++)
            fact *= i;

        while(fact--){
            for(int i = 0; i < n; i++) s[i] = i+1;
            permute(fact, s);

            fact1 = fact2 = prod = 0;

            index = 0;

            while(index < seg1)
                fact1 = fact1 * 10 + s[index++];
            while(index < seg2)
                fact2 = fact2 * 10 + s[index++];
            while(index < n)
                prod = prod * 10 + s[index++];

            if(fact1 * fact2 == prod && find(found.begin(), found.end(), prod) == found.end()){
                sum += prod;
                found.push_back(prod);
            }
        }
    }

    return sum;
}
