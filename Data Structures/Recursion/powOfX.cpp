#include <bits/stdc++.h>
using namespace std;

int pow(int x, int n) {
	long long N = n;
	if(N < 0) {
		x = 1/x;
		N = -N;
	}
	if(N == 0) {
		return 1;
	}

	double half = pow(x, N/2);

	return (n%2 == 0) ? half*half : x*half*half;
}

int main() {
	#ifndef OJ
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int x, n;
	cin >> x >> n;

	cout << pow(x, n) << "\n";

	return 0;
}