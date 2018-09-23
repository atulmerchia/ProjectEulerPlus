#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool test(const vector<unsigned> & vec){
    unsigned total = 0;
    for(unsigned u : vec)
        total += u;

    vector<bool> sums(total + 1, false);

    vector<unsigned> maxSum(vec.size() + 1, 0);
    vector<unsigned> minSum(vec.size() + 1, total + 1);

    minSum[0] = maxSum[0] = 0;

    unsigned full = (1 << vec.size()) - 1;

    for(unsigned mask = 1; mask <= full; mask++){
        unsigned sum = 0, size = 0;
        for(int i = 0; i < vec.size(); i++){
            unsigned bit = 1 << i;
            if((mask & bit) == 0)
                continue;
            sum += vec[i];
            size++;
        }

        if(sums[sum])
            return false;
        sums[sum] = true;

        if(minSum[size] > sum)
            minSum[size] = sum;
        if(maxSum[size] < sum)
            maxSum[size] = sum;
    }

    for(int i = 1; i < vec.size(); i++)
        if(maxSum[i] > minSum[i + 1])
            return false;
    return true;
}

int main() {
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<unsigned> vec(n);
        for(unsigned & u : vec)
            cin >> u;

        if(n < 30)
            cout << (test(vec) ? "YES\n" : "NO\n");
        else
            cout << "NO\n";
    }
    return 0;
}
