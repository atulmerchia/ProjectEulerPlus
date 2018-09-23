#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

unsigned long long index(int den, int n){
    vector<unsigned> arr(n + 1);
    for(int i = 0; i <= n; i++)
        arr[i] = i / den;

    for(int i = 1; i <= n; i++)
        for(int j = 2*i; j <= n; j+=i)
            arr[j] -= arr[i];

    unsigned long long sum = 0;
    for(int i : arr)
        sum += i;

    return sum;
}

int main() {
    int a, d;
    cin >> a >> d;

    cout << index(a, d) - index(a + 1, d) - 1;

    return 0;
}
