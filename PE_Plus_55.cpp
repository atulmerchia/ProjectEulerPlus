#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

typedef vector<int> number;
map<number, int> convergents;

number numerify(int x){
    number ans;
    while(x){
        ans.push_back(x % 10);
        x /= 10;
    }
    return ans;
}

void mirrorDouble(number & x){
    auto backward = x;
    reverse(backward.begin(), backward.end());

    int carry = 0;
    for(int index = x.size() - 1; index >= 0; index--){
        x[index] += backward[index] + carry;
        carry = x[index] / 10;
        x[index] %= 10;
    }

    if(carry)
        x.insert(x.begin(), 1);
}

bool symmetric(number x){
    int left = 0, right = x.size() - 1;
    while(left < right)
        if(x[left++] != x[right--])
            return false;
    return true;
}

int main() {
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        number num = numerify(i);
        int len = 0;

        while(len < 60){
            if(symmetric(num)) break;
            mirrorDouble(num);
            len++;
        }
        if(len != 60){
            unsigned long long convert = 0;
            for(int x : num) convert = convert * 10 + x;
            convergents[num]++;
        }
    }

    number ans;
    int best = 0;
    for(pair<number, int> p : convergents)
        if(p.second > best){
            best = p.second;
            ans = p.first;
        }

    for(int i : ans)
        cout << i;
    cout << " " << best;

    return 0;
}
