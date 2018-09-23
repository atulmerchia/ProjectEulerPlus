#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int getPeriod(int n){
    int top = 1, temptop;
    int bot = (int) sqrt(n), tempbot;
    int BOT = bot;
    int count = 0;
    do{
        temptop = bot;
        tempbot = n - bot * bot;
        // cout << temptop << " " << tempbot << endl;
        if(tempbot % top == 0){
            tempbot /= top;
            top = 1;
        }
        // cout << top << " " << tempbot << endl;
        temptop %= tempbot;
        temptop = abs(tempbot - temptop);
        while(temptop + tempbot <= BOT)
            temptop += tempbot;
        top = tempbot;
        bot = temptop;
        count++;
        // cout << top << " " << bot << endl << endl;
    }while(top != 1 || bot != BOT);
    return count;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int n, tot = 0;
    cin >> n;

    for(int i = 2; i <= n; i++){
        if(sqrt(i) == (int) sqrt(i)) continue;
        if(getPeriod(i) % 2 == 1) tot++;
    }

    cout << tot;

    return 0;
}
