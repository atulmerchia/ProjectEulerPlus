#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<bool> found;
double delta = 0.00001;

void solve(const vector<double> & nums){
    if(nums.size() == 1){
        double d = nums[0];
        int rd = round(d);
        if(rd >= 0 && abs(rd-d) <= delta){
            if(found.size() <= rd)
                found.resize(rd+1, false);
            found[rd] = true;
        }
        return;
    }

    for(int i = 0; i < nums.size(); i++)
        for(int j = i + 1; j < nums.size(); j++){
            auto temp = nums;
            temp.erase(temp.begin() + j);
            temp.erase(temp.begin() + i);

            temp.push_back(nums[i] + nums[j]);
            solve(temp);
            temp.back() = nums[i]-nums[j];
            solve(temp);
            temp.back() = nums[j] - nums[i];
            solve(temp);
            temp.back() = nums[i] * nums[j];
            solve(temp);
            if(nums[i]){
                temp.back() = nums[j] / nums[i];
                solve(temp);
            }
            if(nums[j]){
                temp.back() = nums[i] / nums[j];
                solve(temp);
            }
        }
}

int main(){
    int m; cin >> m;
    vector<double> nums(m);
    for(double & d : nums) cin >> d;

    solve(nums);

    int i;
    for(i = 1; i < found.size(); i++)
        if(!found[i])
            break;
    cout << i - 1;

    return 0;
}
