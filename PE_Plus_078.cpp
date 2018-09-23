#include <iostream>
#include <vector>

using namespace std;
typedef long long ull;

int main(){
    const ull mod = 1e9 + 7;
    vector<ull> p = {1};

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        if(n < p.size()){
            cout << p[n] << endl;
            continue;
        }

        for(int i = p.size(); i <= n; i++){
            int pent = 1;
            int delt = 4;
            ull res = 0;
            int alt = 1;
            while(pent <= i){
                res = (res + alt * p[i-pent]) % mod;
                pent += delt;
                delt += 3;
                alt *= -1;
            }

            pent = 2;
            delt = 5;
            alt = 1;
            while(pent <= i){
                res = (res + alt * p[i-pent]) % mod;
                pent += delt;
                delt += 3;
                alt *= -1;
            }

            while(res < 0) res += mod;
            p.push_back(res);
        }
        cout << p[n] << endl;
    }

    return 0;
}
