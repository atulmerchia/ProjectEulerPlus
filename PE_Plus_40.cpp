#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int process(unsigned long long int);
void process2(unsigned long long int &, int);

int main() {
    int t;
    long prod;
    unsigned long long int i_n;
    cin >> t;
    while(t--){
        prod = 1;
        for(int i = 0; i < 7; i++){
            cin >> i_n;
            prod *= process(i_n);
        }
        cout << prod << endl;
    }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;

    // 1 -> 9 = 1 * 9
    // 10 -> 99 = 2 * 90
    // 100 -> 999 = 3 * 900
    // 1000 -> 9999 = 4 * 9000

    // sum = 9*(4321)

    // get to nearest 10^n (find order of digits)
    // divide away higher values
    // left with i_n
}

int process(unsigned long long int n){
    int digits = 1;
    unsigned long long int mult = 1;
    unsigned long long int digitsSkipped = 0;


    while(digitsSkipped + 9 * mult * digits < n){
        digitsSkipped += digits * 9 * mult;
        mult *= 10;
        digits++;
    }

    auto parentNum = mult;
    while(mult > 1){
        while(digitsSkipped + digits * 9 * mult < n){
            digitsSkipped += digits * 9 * mult;
            parentNum += 9 * mult;
        }
        mult /= 10;
    }

    while(digitsSkipped + digits < n){
        parentNum++;
        digitsSkipped += digits;
    }

    n -= digitsSkipped + 1;

    string s = to_string(parentNum);

    return s[n] - '0';
}
