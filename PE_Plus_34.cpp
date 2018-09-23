#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

static vector<int> answers;
void precompute();

int main() {
    if(answers.size() == 0) precompute();

    int n = 0;
    int sum = 0;
    cin >> n;
    for(int i = 0; i < answers.size(); i++)
        if(answers[i] < n)
            sum += answers[i];
        else
            break;

    cout << sum;

    return 0;
}

void precompute(){
    unsigned long long int factSum = 0;
    long babyFact = 1;
    int iCopy, digit;
    for(int i = 10; i <= 1e5; i++){
        iCopy = i;
        factSum = 0;
        while(iCopy > 0){
            digit = iCopy % 10;
            babyFact = 1;
            for(int j = 2; j <= digit; j++)
                babyFact *= j;
            factSum += babyFact;
            iCopy /= 10;
        }
        if(factSum % i == 0)
            answers.push_back(i);
    }
}
