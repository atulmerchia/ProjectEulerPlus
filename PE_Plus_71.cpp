#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;

bool isLess(ull a, ull b, ull c, ull d){
    return (unsigned __int128) a * (unsigned __int128) d < (unsigned __int128) c * (unsigned __int128) b;
}

int main() {
    int t;
    cin >> t;

    ull a, b, c, d, num, den, bound, medN, medD;

    while(t--){
        cin >> num >> den >> bound;

        a = 0;
        b = c = d = 1;

        while(b + d <= bound){
            medN = a+c;
            medD = b+d;

            if(isLess(medN, medD, num, den)){
                a = medN;
                b = medD;
            }
            else{
                c = medN;
                d = medD;
                if(c == num && d == den)
                    break;
            }
        }

        if(bound >= b + d){
            ull diff = bound - b - d;
            ull rep = 1 + diff / d;
            a += rep * c;
            b += rep * d;
        }

        cout << a << " " << b << endl;
    }

    return 0;
}
