#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> lens(1e7 + 1, 0);

int getNext(int n) {
	int copy = 0;
	do{
		int digit = n % 10;
		n /= 10;
		int prod = 1;
		for (int i = 1; i <= digit; i++)
			prod *= i;
		copy += prod;
	}while(n);
	return copy;
}

void solve() {
	lens[1] = lens[2] = lens[145] = lens[40585] = 1;
	lens[871] = lens[872] = lens[45361] = lens[45362] = 2;
	lens[169] = lens[363601] = lens[1454] = 3;

	for (int i = 0; i <= 1e7; i++) {
		if (lens[i])
			continue;

		int n = i, len = 0;
		vector<int> chain;
		do {
			chain.push_back(n);
			n = getNext(n);
			len++;
		} while (!lens[n]);
		len += lens[n];

		for (int i : chain)
			lens[i] = len--;
	}
}

int main() {
	solve();
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int t, n, L;
    bool found;
    cin >> t;

    // for(int i = 0; i <= 1e7; i++) cout << i << "\t" << lens[i] << endl;

    while(t--){
        cin >> n >> L;
        found = false;
        for(int i = 0; i <= n; i++)
            if(lens[i] == L){
                found = true;
                cout << i << " ";
            }
        if(!found)
            cout << -1;
        cout << endl;
    }

    return 0;
}
