#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int sums [200*9*9 + 1] = {0};
    int MOD = 1e9 + 7;
    for(int i = 0; i <= 9; i++)
        sums[i * i]++;

    int k; cin >> k;
    for(int len = 2; len <= k; len++)
        for(int sum = len*9*9; sum > 0; sum--)
            for(int i = 1; i <= 9; i++){
                int square = i*i;
                if(square > sum) break;
                sums[sum] = (sums[sum] + sums[sum - square]) % MOD;
            }

    unsigned long long ans = 0;
    for(int i = 1; i <= k*9*9; i++){
        int sum = i;
        do{
            int copy = sum;
            sum = 0;
            while(copy){
                int digit = copy % 10;
                sum += digit * digit;
                copy /= 10;
            }
        }while(sum != 89 && sum != 1);

        if(sum == 89)
            ans = (ans + sums[i]) % MOD;
    }

    cout << ans;

    return 0;
}
