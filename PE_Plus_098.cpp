#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;

struct info{
    ull big = 0;
    int num = 0;
};

int main() {
    int n; cin >> n;

    ull rt = sqrt(pow(10, n-1));

    map<string, info> m;

    while(true){
        ull sq = rt*rt;
        string s = to_string(sq);
        if(s.length() > n)
            break;
        sort(s.begin(), s.end());
        auto it = m.find(s);
        if(it == m.end())
            m.insert(pair<string, info>(s, {sq, 1}));
        else{
            it->second.big = sq;
            it->second.num++;
        }
        rt++;
    }

    int highNum = 0;
    ull bigAns = 0;

    for(pair<string, info> p : m){
        info i = p.second;
        if(i.num > highNum){
            highNum = i.num;
            bigAns = i.big;
        }
        else if(i.num == highNum)
            bigAns = max(bigAns, i.big);
    }

    cout << bigAns;

    return 0;
}
