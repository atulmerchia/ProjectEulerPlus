#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

static vector<long>answers;
void precompute();
bool areCoprime(int, int);

int main() {
	if(answers.size() == 0) precompute();
	int t;
	cin >> t;
	int n, i;
	while (t--) {
		cin >> n;
		for (i = 0; i < answers.size(); i++)
			if (answers[i] > n) break;
		cout << answers[i - 1] << endl;
	}
	return 0;
}

void precompute() {
	unsigned int perimeters[5000001];
    for(int i = 0; i <= 5e6; i++)
        perimeters[i] = 0;

	for (long m = 1; m <= 2240; m++)
		for (long n = m % 2 + 1; n < m; n += 2)
			if (areCoprime(m, n)){
                long p0 = 2*m*(m+n);
                long copyP = p0;
                while(copyP <= 5e6){
                    perimeters[copyP]++;
                    copyP += p0;
                }
            }

	long max = 0;
	for (int p = 1; p <= 5e6; p++)
		if (perimeters[p] > max) {
			max = perimeters[p];
			answers.push_back(p);
		}
}


bool areCoprime(int m, int n) {
	int t;
    while (n != 0){
		t = n;
        n = m % n;
        m = t;
    }

	return m == 1;
}
