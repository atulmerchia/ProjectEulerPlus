#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> counts (5e6 + 1, 0);

void solve(){
    int rt = sqrt(5e6);
    for(int m = 2; m <= rt; m++)
        for(int n = (m + 1) % 2; n < m; n += 2)
            if(__gcd(m,n) == 1){
                int perim = 2*m*(m+n);
                for(int k = perim; k <= 5e6; k += perim)
                    counts[k]++;
            }
    int sum = 0;
    for(int i = 0; i <= 5e6; i++){
        if(counts[i] == 1) sum++;
        counts[i] = sum;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    solve();

    int t, n, ans;
    cin >> t;
    while(t--){
        cin >> n;
        cout << counts[n] << endl;
    }

    return 0;
}
