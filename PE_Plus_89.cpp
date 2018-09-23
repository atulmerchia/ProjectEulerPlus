#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string solve(int val){
    string s;
    while(val >= 1000){
        s += "M";
        val -= 1000;
    }
    if(val >= 900){
        s += "CM";
        val -= 900;
    }
    if(val >= 500){
        s += "D";
        val -= 500;
    }
    if(val >= 400){
        s += "CD";
        val -= 400;
    }
    while(val >= 100){
        s += "C";
        val -= 100;
    }
    if(val >= 90){
        s += "XC";
        val -= 90;
    }
    if(val >= 50){
        s += "L";
        val -= 50;
    }
    if(val >= 40){
        s += "XL";
        val -= 40;
    }
    while(val >= 10){
        s += "X";
        val -= 10;
    }
    if(val >= 9){
        s += "IX";
        val -= 9;
    }
    if(val >= 5){
        s += "V";
        val -= 5;
    }
    if(val >= 4){
        s += "IV";
        val -= 4;
    }
    while(val >= 1){
        s += "I";
        val--;
    }
    return s;
}

int unsolve(string s){
    int ans = 0, prev = 0, val;
    bool sub = false;
    for(char c : s){
        switch(c){
            case 'I':
                val = 1;
                break;
            case 'V':
                val = 5;
                break;
            case 'X':
                val = 10;
                break;
            case 'L':
                val = 50;
                break;
            case 'C':
                val = 100;
                break;
            case 'D':
                val = 500;
                break;
            case 'M':
                val = 1000;
                break;
        }
        if(val < prev) sub = 1;
        else if(val > prev) sub = -1;
        ans += sub * val;
        prev = val;
    }
    return ans;
}

int main() {
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        cout << solve(unsolve(s)) << endl;
    }
    return 0;
}
