#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    ull limit = 1e18;
    vector<ull> pos = {1, 5};
    vector<ull> neg = {1, 17};

    vector<ull> ans = {16, 50};

    while(ans.back() < limit + 4){
        ull nextPos = 14 * pos[1] - pos[0] - 4;
        ull nextNeg = 14 * neg[1] - neg[0] + 4;

        pos[0] = pos[1];
        pos[1] = nextPos;
        neg[0] = neg[1];
        neg[1] = nextNeg;

        ans.push_back(3*nextPos + 1);
        ans.push_back(3*nextNeg - 1);
    }

    sort(ans.begin(), ans.end());

    int t; cin >> t;
    while(t--){
        ull n; cin >> n;
        ull sum = 0;
        for(ull u : ans)
            if(u <= n)
                sum += u;
            else break;
        cout << sum << endl;
    }

    return 0;
}
