#include <iostream>
#include <vector>

using namespace std;

long mod;

struct Big : vector<long>{
    Big(long x){
        push_back(x);
    }

    void operator+=(const Big & other){
        if(size() < other.size())
            resize(other.size(), 0);

        long carry = 0;
        for(int i = 0; i < size(); i++){
            carry += operator[](i);
            if(i < other.size())
                carry += other[i];
            else if(carry == 0)
                return;

            if(carry < mod){
                operator[](i) = carry;
                carry = 0;
            }
            else{
                operator[](i) = carry - mod;
                carry = 1;
            }
        }
        if(carry)
            push_back(carry);
    }
};

bool isPandigital(long x, int digits){
    int maxNum = digits;
    vector<bool> used(digits + 1, false);
    while(x){
        if(!(x % 10) || x%10 > maxNum || used[x%10]) return false;
        used[x%10] = true;
        x /= 10;
        digits--;
    }
    return !digits;
}

int main(){
    int one, two, digits;
    cin >> one >> two >> digits;

    if (one == 1 && digits == 1){
        cout << "1" << endl;
        return 0;
    }

    mod = 1;
    for (int i = 1; i <= digits; i++)
        mod *= 10;

    Big a = one;
    Big b = two;

    for (int i = 2; i <= 2000000; i++){
        if (isPandigital(b.front(), digits)){
            long first = b.back();
            if (first < mod && b.size() > 1)
                first = first * mod + b[b.size() - 2];

            while (first >= mod)
                first /= 10;

            if (isPandigital(first, digits)){
                cout << i << endl;
                return 0;
            }
        }

        a += b;
        swap(a, b);

        if (a.size() > 10){
            a.erase(a.begin() + 2);
            b.erase(b.begin() + 2);
        }
    }

    cout << "no solution" << endl;
    return 0;
}
