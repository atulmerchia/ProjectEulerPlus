#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, k;
    cin >> n >> k;

    int benchmark = 1e6 / k;

    for(unsigned int i = 125874; i <= n; i++){
        string s1 = to_string(i);
        sort(s1.begin(), s1.end());
        bool valid = true;
        for(int j = 2; j <= k; j++){
            string sn = to_string(i*j);
            sort(sn.begin(), sn.end());
            if(sn != s1){
                valid = false;
                break;
            }
        }
        if(valid){
            for(int num = i; num <= i*k; num += i)
                cout << num << " ";
            cout << endl;
        }
        if(i == benchmark){
            i = benchmark * k;
            benchmark *= 10;
        }
    }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
