#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

string power(int n, int p){
    vector<int> num = {1};
    int carry = 0;
    while(p--){
        for(int index = num.size() - 1; index >= 0; index--){
            num[index] = num[index] * n + carry;
            carry = num[index] / 10;
            num[index] %= 10;
        }
        while(carry != 0){
            num.insert(num.begin(), carry % 10);
            carry /= 10;
        }
    }
    string s = "";
    for(int i : num)
        s += to_string(i);
    return s;
}

int main() {
    double n;
    cin >> n;
    int min = ceil(pow(10, (n-1) / n));
    cout << fixed << setprecision(0);
    for(int i = min; i < 10; i++)
        cout << power(i, n) << endl;
    return 0;
}
