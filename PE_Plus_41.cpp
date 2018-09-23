#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

static vector<unsigned int> answers;

bool isPandigital(unsigned int n, int base){
    bool* used = new bool [base+1];
    for(int i = 0; i <= base; i++)
        used[i] = false;
    while(n > 0){
        int digit = n % 10;
        if(digit == 0 || digit > base || used[digit]){
            delete [] used;
            return false;
        }
        used[digit] = true;
        n /= 10;
    }

    delete [] used;
    return true;
}

bool isPrime(unsigned int n, bool isComposite[]){
    if(n%2 == 0) return false;
    for(int i = 3; i <= sqrt(n); i += 2)
        if(!isComposite[i] && n % i == 0)
            return false;
    return true;
}

void precompute(){
    bool* isComposite = new bool [2767];
    for(int i = 3; i < 53; i+=2)
        for(int j = 3*i; j < 2767; j += 2*i)
            isComposite[j] = true;

    for(unsigned int i = 1243; i <= 4321; i += 2)
        if(isPandigital(i, 4) && isPrime(i, isComposite))
            answers.push_back(i);
    for(unsigned int i = 1234567; i <= 7654321; i += 2)
        if(isPandigital(i, 7) && isPrime(i, isComposite))
            answers.push_back(i);

    delete [] isComposite;
}

int main() {
    if(answers.size() == 0) precompute();
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t, i;
    long int n;
    cin >> t;
    while(t--){
        cin >> n;
        for(i = answers.size() - 1; i >= 0; i--)
            if(answers[i] <= n){
                cout << answers[i] << endl;
                break;
            }
        if(i < 0)
            cout << -1 << endl;
    }
}
