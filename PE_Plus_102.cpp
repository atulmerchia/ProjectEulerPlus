#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t; cin >> t;
    int x[3];
    int y[3];

    int count = 0;

    while(t--){
        for(int i = 0; i < 3; i++)
            cin >> x[i] >> y[i];
        int b[3];
        bool pos = false, neg = false;
        for(int i = 0; i < 3; i++){
            long x1 = x[i], x2 = x[(i+1) % 3], y1 = y[i], y2 = y[(i+1) % 3];
            if(x1 * x2 > 0 || x1 == x2){
                b[i] = 0;
                continue;
            }
            double m = (double)(y2 - y1)/(x2-x1);
            double b_i = y1 + m * -x1;
            if(b_i > 0)
                b[i] = 1;
            else if(b_i < 0)
                b[i] = -1;
            else{
                pos = true;
                neg = true;
                break;
            }
        }
        for(int i : b)
            if(i < 0) neg = true;
            else if(i > 0) pos = true;
        count += (neg && pos);
    }

    cout << count;

    return 0;
}
