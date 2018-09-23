#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct input{
    double b,e;
    void print(){
        cout << (int) b << " " << (int) e;
    }
};

bool compare(input l, input r){
    return l.e/r.e < log10(r.b) / log10(l.b);
}

int main() {
    int n; cin >> n;
    vector<input> vec(n);
    for(input & i : vec){
        cin >> i.b;
        cin >> i.e;
    }
    sort(vec.begin(), vec.end(), compare);

    int k; cin >> k;
    vec[k-1].print();

    return 0;
}
