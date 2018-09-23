#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <bitset>
using namespace std;

set<string> output;
int n, s;

void recurse(int iter, int inner [], int outer [], int used){
    if(iter == n-1){
        outer[iter] = s - (inner[0] + inner[n-1]);
        if(used & (1 << outer[iter]))
            return;

        for(int i = 1; i < n; i++)
            if(outer[i] < outer[0]) return;

        string ans;
        for(int i = 0; i < n; i++)
            ans += to_string(outer[i]) + to_string(inner[i]) + to_string(inner[(i+1)%n]);
        output.insert(ans);
        return;
    }

    for(int i = 1; i <= 2*n; i++){
        int mask = 1 << i;
        if(used & mask) continue;

        inner[iter+1] = i;
        int temp = used | mask;

        outer[iter] = s - (inner[iter] + i);
        mask = 1 << outer[iter];
        if(temp & mask) continue;
        temp |= mask;

        recurse(iter + 1, inner, outer, temp);
    }
}

int main() {
    cin >> n >> s;

    int mask = ~0;
    for(int i = 1; i <= 2*n; i++)
        mask -= 1 << i;

    int inner [n];
    int outer [n];

    for(int i = 1; i <= 2*n; i++){
        inner[0] = i;
        recurse(0, inner, outer, mask | (1 << i));
    }

    for(string str : output)
        cout << str << endl;

    return 0;
}
