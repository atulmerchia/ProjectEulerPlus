#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int get_tri0(int &a){
    double d = (sqrt(1+8*a) - 1)/2;
    int ans = (d == (int) d) ? d : d + 1;
    a = ans*(ans+1) / 2;
    return ans;
}
int get_squ0(int &a){
    double d = sqrt(a);
    int ans = (d == (int) d) ? d : d+1;
    a = ans*ans;
    return ans;
}
int get_pen0(int &a){
    double d = (1 + sqrt(1 + 24*a))/6;
    int ans = (d == (int) d) ? d : d+1;
    a = ans*(3*ans - 1)/2;
    return ans;
}
int get_hex0(int &a){
    double d = (1+sqrt(1+8*a))/4;
    int ans = (d == (int) d) ? d : d+1;
    a = ans*(2*ans - 1);
    return ans;
}
int get_hep0(int &a){
    double d = (3 + sqrt(9 + 40*a))/10;
    int ans = (d == (int) d) ? d : d+1;
    a = ans * (5*ans - 3) / 2;
    return ans;
}
int get_oct0(int &a){
    double d = (2 + sqrt(4+12*a))/6;
    int ans = (d == (int) d) ? d : d+1;
    a = ans*(3*ans-2);
    return ans;
}

vector<int> orders;
int n = 0;
int i0 = 0;
vector<int> sums;

typedef int (*IntFunctionWithOneParameter) (int &a);
static IntFunctionWithOneParameter func [] = {get_tri0, get_squ0, get_pen0, get_hex0, get_hep0, get_oct0};


void recurse(int oIndex, int match, int sum, vector<int> used){
    if(oIndex == n){
        if(match == i0 / 100)
            sums.push_back(sum);
        return;
    }
    int o = orders[oIndex];
    int num0 = match*100;

    int delta = (o-2)*(func[o-3](num0) - 1) + 1;

    for(int i = num0; i < (match+1) * 100; i += delta){
        if(oIndex == 0) i0 = i;
        if(i % 100 > 9){
            bool repeat = false;
            for(int u : used)
                if(u == i){
                    repeat = true;
                    break;
                }
            if(!repeat){
                used.push_back(i);
                recurse(oIndex+1, i % 100, sum + i, used);
                used.pop_back();
            }
        }
        delta += o-2;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    cin >> n;

    int a;
    for(int i = 0; i < n; i++){
        cin >> a;
        orders.push_back(a);
    }

    do{
        for(int i = 10; i < 100; i++)
        recurse(0, i, 0, {});
    }while(next_permutation(orders.begin(), orders.end()));
    sort(sums.begin(), sums.end());

    if(sums.size())
        cout << sums[0];
    for(int i = 1; i < sums.size(); i++)
        if(sums[i] != sums[i-1])
            cout << endl << sums[i];

    // d0 = (o-2) * n + 1
    // dd = o-2
    // 3 -> 1035, 45th
    // 4 -> 1024, 32nd
    // 5 -> 1001, 26th
    // 6 -> 1035, 23rd
    // 7 -> 1071, 21st
    // 8 -> 1045, 19th

    // tri: n = -1 + sqrt(1 + 8a) / 2
    // squ: n = sqrt(a)
    // pen: 1 + sqrt(1 + 24a) / 6
    // hex: 1 + sqrt(1 + 8a) / 4
    // hep: 3 + sqrt(9 + 40a) / 10
    // oct: 2 + sqrt(4 + 12a) / 6

    return 0;
}
