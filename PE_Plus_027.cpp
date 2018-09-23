#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

static int primes[291];

static void setUp();
static bool isPrime(int);

int getPrimeString(int, int);

int main() {
	if (primes[0] == 0) setUp();

	int n = 0;
	int a = -1;
	int b = 0;
	int len = 0;
	int maxLen = 0;
	int maxA = 0;
	int maxB = 0;

	cin >> n;

	for(int a = -n; a <= n; a++){
		if (a % 2 == 0) {
			len = getPrimeString(a, 2);
			if (len > maxLen) {
				maxLen = len;
				maxA = a;
				maxB = b;
			}
			continue;
		}
		for (int i = 0; primes[i] <= n; i++) {
			b = primes[i];
			len = getPrimeString(a, b);
			if (len > maxLen) {
				maxLen = len;
				maxA = a;
				maxB = b;
			}
		}
	}
	cout << maxA << " " << maxB << endl;
}

int getPrimeString(int a, int b) {
	int n = 0;
	int num = 0;
	do {
		num = n * (n + a) + b;
		n++;
	} while (num > 0 && num % 2 == 1 && isPrime(num));
	return n;
}

static void setUp() {
	int index = 0;
	int p = 3;
	while (p < 2004) {
		if (isPrime(p)) {
			primes[index++] = p;
		}
		p += 2;
	}
}

static bool isPrime(int n) {
	double cap = sqrt(n);
	for (int i = 3; i <= cap; i += 2)
		if (n % i == 0)
			return false;
	return true;
}
