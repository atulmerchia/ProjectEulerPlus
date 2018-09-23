#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> ans;
int n;

int solve(int num, int remSum, int remProd, int minFac, int depth){
    if(remProd == 1){
        depth += remSum - 1;
        if(depth <= n && ans[depth] > num){
            ans[depth] = num;
            return true;
        }
        return false;
    }

    int count = 0;
    if(depth != 1){
        if(depth <= n && ans[depth] > num){
            ans[depth] = num;
            return true;
        }

        int temp = depth + remSum - remProd;
        if(temp <= n && ans[temp] > num){
            ans[temp] = num;
            count++;
        }
    }

    for(int i = minFac; i * i <= remProd; i++)
        if(remProd % i == 0)
            count += solve(num, remSum - i, remProd / i, i, depth + 1);
    return count;
}

int main() {
    cin >> n;
    int toGo = n - 1;
    ans.resize(n + 1, __INT_MAX__);

    int i = 4;
    int sum = 0;
    while(toGo){
        int found = solve(i, i, i, 2, 1);
        if(found){
            sum += i;
            toGo -= found;
        }
        i++;
    }

    cout << sum;

    return 0;
}
