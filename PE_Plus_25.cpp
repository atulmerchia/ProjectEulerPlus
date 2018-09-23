#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

static long nDigits[5001];
static void precompute();

int main() {
	if(nDigits[2] == 0) precompute();
	int t = 0;
	cin >> t;
	int n = 0;
	while(t--){
        cin >> n;
        cout << nDigits[n] << endl;
    }
}

static void precompute() {
	int digits = 2;
	long n = 7;
	double logPhi = log10(0.5 * (1 + sqrt(5)));
	double subtrahend = 0.5 * log10(5);
	while (digits < 5001) {
		if (1 + static_cast<int>(n*logPhi - subtrahend) == digits) {
			nDigits[digits] = n;
			digits++;
			n += 2;
		}
		n++;
	}
}
