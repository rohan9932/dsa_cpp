#include <bits/stdc++.h>
using namespace std;

int power(int x, int n) {
	if(n == 0) {
		return 1;
	}

	return (n%2 == 0) ? power(x, n/2)*power(x,n/2) : x*power(x, n/2)*power(x,n/2);
}

int pow(int x, int n) {
	if(n < 0) {
		x = 1/x;
		n = -n;
	}

	return power(x, n);
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