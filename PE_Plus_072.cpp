#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int size = 1e6 + 1;

    vector<int> tot (size);

    for(int i = 0; i < size; i++)
        tot[i] = i;

    for(int i = 2; i < size; i++)
        if(tot[i] == i)
            for(int k = 1; k * i < size; k++)
                tot[k*i] -= tot[k*i] / i;

    vector<unsigned long long> sums(size, 0);
    for(int i = 2; i < size; i++)
        sums[i] = sums[i-1] + tot[i];

    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        cout << sums[n] << endl;
    }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
