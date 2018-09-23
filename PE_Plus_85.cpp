#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

static vector<int> area;

void solve(){
    int max = 2001001;
    area.resize(max, 0);

    int triangles[2001] = {0};
    for(int i = 1; i < 2001; i++)
        triangles[i] = triangles[i-1] + i;

    for(int i = 1; i < 2001; i++)
        for(int j = i; j < 2001; j++){
            unsigned long long prod = triangles[i] * triangles[j];
            if(prod >= max)
                break;
            else
                if(i * j > area[prod])
                    area[prod] = i*j;
        }
}

int main(){
    if(!area.size()) solve();

    int t; cin >> t;

    int target;
    while(t--){
        cin >> target;
        for(int dist = 0; ; dist++)
            if(area[target - dist] != 0 || area[target + dist] != 0){
                cout << max(area[target - dist], area[target + dist]) << endl;
                break;
            }
    }

    return 0;
}
