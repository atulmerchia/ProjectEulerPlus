#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

bool isPalindrome(int p){
    string s = to_string(p);
    int left = 0, right = s.length() - 1;
    while(left < right)
        if(s[left++] != s[right--])
            return false;
    return true;
}

int main() {
    set<int> palins;
    for(int i = 101; i < 1000; i++)
        for(int j = i; j < 1000; j++)
            if(isPalindrome(i*j))
                palins.insert(i*j);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        auto it = palins.begin();
        while(it != palins.end() && *it < n)
            it++;
        it--;
        cout << *it << endl;
    }

    return 0;
}
