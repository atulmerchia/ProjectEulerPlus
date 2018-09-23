#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

static vector<long> answers;

void precompute();
void getNext(long &);
bool isPrime(long);
void getRotations(long, long*);

int main() {
    if(answers.size() == 0) precompute();
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n = 0;
    int sum = 0;
    cin >> n;
    for(int i = 0; i < answers.size(); i++)
        if(answers[i] < n) sum += answers[i];
        else break;
    cout << sum << endl;
    return 0;
}

void precompute(){
    int* isCircular = new int[1000000];
    for(int i = 0; i < 1000000; i++)
        isCircular[i] = 0;
    isCircular[2] = 1;
    long rotations[6];
    for(long i = 3; i <= 1000000; getNext(i)){
        if(isCircular[i] != 0)
            continue;
        if(isPrime(i)){
            isCircular[i] = 1;
            getRotations(i, rotations);
            for(int j = 0; j < static_cast<int>(log10(i)); j++){
                if(!isPrime(rotations[j])){
                    for(int k = 0; k < static_cast<int>(log10(i)); k++)
                        isCircular[rotations[k]] = -1;
                    isCircular[i] = -1;
                    break;
                }
                else
                    isCircular[rotations[j]] = 1;
            }
        }
    }
    for(int i = 0; i < 1000000; i++)
        if(isCircular[i] == 1)
            answers.push_back(i);
    delete [] isCircular;
}

void getNext(long &i){
    bool evens = false;
    i += 2;
    long mult = 10;
    while(mult < i){
        if(i/mult % 2 == 0)
            i += mult;
        mult *= 10;
    }
}

bool isPrime(long n){
    for(int i = 3; i <= sqrt(n); i += 2){
        if(n % i == 0)
            return false;
    }
    return true;
}

void getRotations(long n, long* rotations){
    int logN = static_cast<int>(log10(n));
    long powN = pow(10, logN);
    for(int i = 0; i < logN; i++){
        n = (n % 10) * powN + n/10;
        rotations[i] = n;
    }
}
