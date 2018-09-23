#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isValid(char c){
    if(c >= 65 && c <= 90) return true;
    if(c >= 97 && c <= 122) return true;
    if(c >= 48 && c <= 59) return true;
    if(c == 32 || c == 33) return true;
    if(c >= 39 && c <= 41) return true;
    if(c >= 44 && c <= 46) return true;
    return c == 63;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;

    int arr [n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    for(int cipher = 0; cipher < 3; cipher++){
        char key = 'a';
        for(int i = cipher; i < n; i+=3){
            if(!isValid(arr[i] ^ key)){
                key++;
                i = cipher - 3;
            }
        }
        cout << key;
    }

    return 0;
}
