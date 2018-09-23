#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

static bool isPrime[1000001];
vector<string> answers;

void getPrimes(){
    for(int i = 0; i < 1000001; i++)
        isPrime[i] = true;

    isPrime[0] = false; isPrime[1] = false;
    for(int i = 2; i <= 1000000; i += 2)
        isPrime[i] = false;
    for(int i = 3; i <= 1000; i += 2){
        if(!isPrime[i]) continue;
        for(int j = 3*i; j <= 1000000; j += 2*i)
            isPrime[j] = false;
    }
}

void extrapolate(vector<int> nums, int k, int n){
    if(nums.size() < k) return;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] > n) return;
        for(int j = i+1; j < nums.size(); j++){
            string s = to_string(nums[i]);
            s += to_string(nums[j]);
            int diff = nums[j] - nums[i];
            int last = nums[j];
            int count = 2;
            for(int x = j + 1; x < nums.size(); x++){
                if(nums[x] == last + diff){
                    s += to_string(nums[x]);
                    count++;
                    last = nums[x];
                }
                if(count == k){
                    answers.push_back(s);
                    break;
                }
            }
        }
    }
}

bool compare(const string& a, const string& b){
    if(a.length() != b.length()) return a.length() < b.length();
    else return a < b;
}

int main() {
    if(!isPrime[2]) getPrimes();

    int maxNum, k;
    cin >> maxNum >> k;

    for(int i = 1000; i < maxNum; i++){
        string s = to_string(i);
        bool ascending = true;
        for(int i = 1; i < s.length(); i++)
            if(s[i-1] > s[i]){
                ascending = false;
                break;
            }
        if(!ascending) continue;
        for(int x = i; x < maxNum; x *= 10){
            vector<int> primePerms;
            do{
                if(s[0] == '0')
                    continue;
                int val = stoi(s);
                if(isPrime[val])
                    primePerms.push_back(val);
            }while(next_permutation(s.begin(), s.end()));
            extrapolate(primePerms, k, maxNum);
            s = "0" + s;
        }
    }

    sort(answers.begin(), answers.end(), compare);
    for(int i = 0; i < answers.size(); i++)
        cout << answers[i] << endl;

    return 0;
}
