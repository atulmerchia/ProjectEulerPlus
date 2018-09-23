#include <cmath>
#include <cstdio>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct edge{
    int a, b, w;

    bool operator<(const edge other) const{
        return w > other.w;
    }
};

vector<int> root;

int source(int x){
    while(root[x] != x){
        root[x] = root[root[x]];
        x = root[x];
    }
    return x;
}

int main() {
    int n, m; cin >> n >> m;
    root.resize(n);

    for(int i = 0; i < n; i++)
        root[i] = i;

    priority_queue<edge> q;
    for(int i = 0; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        edge e {a, b, w};
        q.push(e);
    }

    int ans = 0;

    for(int i = 0; i < m; i++){
        edge e = q.top();
        q.pop();

        int rootA = source(e.a), rootB = source(e.b);
        if(rootA != rootB){
            ans += e.w;
            root[rootA] = rootB;
        }
    }

    cout << ans;

    return 0;
}
