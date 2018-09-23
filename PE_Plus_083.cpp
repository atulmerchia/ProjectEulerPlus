#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

typedef unsigned long long ull;

struct cell{
    int x, y;
    ull val;

    bool operator<(cell c) const{
        return val > c.val;
    }
};

cell get(int x, int y, ull val){
    cell c = {x, y, val};
    return c;
}

int main(){
    int n; cin >> n;

    vector<vector<ull>> arr(n, vector<ull>(n));
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> arr[i][j];

    priority_queue<cell> q;
    q.push(get(0, 0, arr[0][0]));

    while(!q.empty()){
        cell c = q.top();
        q.pop();

        if(visited[c.x][c.y])
            continue;

        visited[c.x][c.y] = true;

        if(c.x + 1 == n && c.y + 1 == n){
            cout << c.val;
            break;
        }

        if(c.x > 0)
            q.push(get(c.x - 1, c.y, c.val + arr[c.x-1][c.y]));
        if(c.y > 0)
            q.push(get(c.x, c.y - 1, c.val + arr[c.x][c.y-1]));
        if(c.x + 1 < n)
            q.push(get(c.x + 1, c.y, c.val + arr[c.x+1][c.y]));
        if(c.y + 1 < n)
            q.push(get(c.x, c.y + 1, c.val + arr[c.x][c.y+1]));
    }

    return 0;
}
