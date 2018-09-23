#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        string s; cin >> s;

        int arr[n];
        for(int i = 0; i < n; i++)
            arr[i] = s[i] - '0';

        long prod = 1;
        for(int i = 0; i < k; i++)
            prod *= arr[i];

        long ans = prod;

        int start = 0, end = k;
        while(end < n){
            if(prod){
                prod /= arr[start++];
                prod *= arr[end++];
            }
            else{
                while(start < n && arr[start])
                    start++;
                while(start < n && !arr[start])
                    start++;
                end = start + k;
                if(end < n){
                    prod = 1;
                    for(int i = start; i < end; i++)
                        prod *= arr[i];
                }
                else break;
            }
            ans = max(ans, prod);
        }

        cout << ans << endl;
    }
    return 0;
}
