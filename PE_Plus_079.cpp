#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

int main() {

    set<char> prev [127];
    set<char> post [127];

    int t; cin >> t;
    while(t--){
        string s; cin >> s;

        prev[s[1]].insert(s[0]);
        prev[s[2]].insert(s[0]);
        prev[s[2]].insert(s[1]);

        post[s[0]].insert(s[1]);
        post[s[0]].insert(s[2]);
        post[s[1]].insert(s[2]);
    }

    priority_queue<char, vector<char>, greater<char>> q;
    int distinct = 0;

    for(char c = 33; c < 127; c++){
        if(prev[c].size() || post[c].size())
            distinct++;
        if(!prev[c].size() && post[c].size()){
            q.push(c);
        }
    }

    string login;
    while(!q.empty()){
        distinct--;
        char c = q.top(); q.pop();
        for(char p : post[c]){
            prev[p].erase(c);
            if(!prev[p].size())
                q.push(p);
        }
        login += c;
    }

    if(distinct) cout << "SMTH WRONG\n";
    else cout << login << endl;

    return 0;
}
