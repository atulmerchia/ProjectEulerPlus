#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

string id(unsigned long long x){
    string s = to_string(x*x*x);
    sort(s.begin(), s.end());
    return s;
}

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int n;
	int k;
	cin >> n >> k;

    map<string, vector<int>> sets;
	for(int i = 0; i < n; i++)
        sets[id(i)].push_back(i);

    vector<int> ans;

	for(auto set : sets)
        if(set.second.size() == k)
            ans.push_back(set.second[0]);

    sort(ans.begin(), ans.end());
    cout << (unsigned long long) ans[0] * ans[0] * ans[0];
    for(int i = 1; i < ans.size(); i++)
        if(ans[i] != ans[i-1])
            cout << endl << (unsigned long long) ans[i] * ans[i] * ans[i];

	return 0;
}
