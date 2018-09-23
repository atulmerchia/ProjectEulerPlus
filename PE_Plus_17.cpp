#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

static string postfix [] = {"", "Thousand ", "Million ", "Billion ", "Trillion "};
static string ones [] = {"", "One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine "};
static string tens [] = {"", "Ten ", "Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety "};

static string teens [] = {"Eleven ", "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen "};

string stringify(unsigned long long);
string setOfThree(int);

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t = 0;
    cin >> t;
    unsigned long long n = 0;
    for(int i = 0; i < t; i++){
        cin >> n;
        cout << stringify(n) << endl;
    }
}

string stringify(unsigned long long n){
    int setNum = 0;
    string ans = "";
    while(n > 0){
        if(n % 1000 != 0)
            ans = setOfThree(n % 1000) + postfix[setNum] + ans;
        setNum++;
        n /= 1000;
    }
    return ans;
}

string setOfThree(int n){
    string str = ones[n/100];
    if(n > 100)
        str += "Hundred ";
    n %= 100;
    if(n < 20 && n > 10)
        str += teens[n-11];
    else
        str += tens[n/10] + ones[n%10];
    return str;
}
