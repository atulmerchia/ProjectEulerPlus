#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Number : vector<unsigned>{
    unsigned MOD = 1e5;
    Number(auto n){
        do{
            this->push_back(n % MOD);
            n /= MOD;
        }while(n);
    }

    Number operator+(const Number& n) const{
        auto ans = *this;
        if(n.size() > ans.size())
            ans.resize(n.size(), 0);

        unsigned carry = 0;
        for(int i = 0; i < ans.size(); i++){
            carry += ans[i];
            if(i < n.size())
                carry += n[i];
            else if(carry == 0)
                return ans;
            if(carry < MOD){
                ans[i] = carry;
                carry = 0;
            }
            else{
                ans[i] = carry - MOD;
                carry = 1;
            }
        }
        if(carry) ans.push_back(carry);
        return ans;
    }

    Number operator*(unsigned long long n) const{
        auto ans = *this;

        if(n == 0) return 0;
        if(n == 1) return *this;
        if(n == MOD){
            ans.insert(ans.begin(), 0);
            return ans;
        }

        if(n > MOD)
            return ans * Number(n);

        unsigned long long carry = 0;
        for(int i = 0; i < ans.size(); i++){
            carry += n * ans[i];
            ans[i] = carry % MOD;
            carry /= MOD;
        }
        while(carry){
            ans.push_back(carry % MOD);
            carry /= MOD;
        }
        return ans;
    }

    Number operator*(const Number& n) const{
        Number ans = 0;
        for(int i = n.size() - 1; i >= 0; i--)
            ans = ans * MOD + (*this * n[i]);
        return ans;
    }

    bool operator<(const Number&n) const{
        auto a = *this;
        if(a.size() < n.size()) return true;
        if(n.size() < a.size()) return false;
        for(int i = a.size() - 1; i >= 0; i--)
            if(a[i] != n[i]) return a[i] < n[i];
        return false;
    }
};

int main() {
    int n;
    cin >> n;

    Number best = 3;
    int ans = 2;

    for(int D = 3; D <= n; D++){
        int root = sqrt(D);
        if(root * root == D) continue;

        unsigned mult = root, num = 0, den = 1;
        Number x[3] = {0, 1, root};
        Number y[3] = {0, 0, 1};

        while(true){
            num = den * mult - num;
            den = (D - num * num) / den;
            mult = (root + num) / den;

            x[0] = x[1];
            x[1] = x[2];
            x[2] = x[0] + x[1] * mult;

            y[0] = y[1];
            y[1] = y[2];
            y[2] = y[0] + y[1] * mult;

            auto left = x[2] * x[2];
            auto right = y[2] * y[2] * D + 1;

            if(left == right){
                if(best < x[2]){
                    best = x[2];
                    ans = D;
                }
                break;
            }
        }
    }

    cout << ans;
    return 0;
}
