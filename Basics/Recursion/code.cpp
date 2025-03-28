#include <bits/stdc++.h>
using namespace std;

void printNum(int n) {
	if(n == 1) {
		cout << 1 << "\n";
		return;
	}
	cout << n << " ";
	printNum(n-1);
}

int fact(int n) {
	if(n == 0) {
		return 1;
	}

	return n * fact(n-1);
}

int sumofN(int n) {
	if(n == 1) {
		return 1;
	}

	return n + sumofN(n-1);
}

int main() {
	#ifndef OJ
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	printNum(5);

	cout << fact(5) << "\n";

	cout << sumofN(3) << "\n";

	return 0;
}