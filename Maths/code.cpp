#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	while(a > 0 && b > 0) {
		if(a > b) {
			a %= b;
		} else {
			b %= a;
		}
	}

	if(a == 0) return b;
	return a;
}

vector<bool> sieve_of_erathosthenes(int n) {
	vector<bool> isPrime(n+1, true);
	int ans = 0;
	for(int i = 2; i < n; i++) {
		if(isPrime[i]) {
			ans++;
			for(int j = i*2; j < n; j+=i){
				isPrime[j] = false;
			}
		}
	}

	return isPrime;
}

int revInt(int a) {
	int revNum = 0;

	while(a != 0) {
		int digit = a % 10;
		a /= 10;

		revNum = (revNum * 10) + digit;
	}

	return revNum;
}

int main() {
	#ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen("input.txt", "r", stdin);
	//for writing output to output.txt
	freopen("output.txt", "w", stdout);
	#endif

	// int n;
	// cin >> n;

	// vector<bool> isPrime = sieve_of_erathosthenes(n);

	// for(int i = 2; i < n; i++) {
	// 	if(isPrime[i]) {
	// 		cout << i << " ";
	// 	}
	// }
	// cout << "\n";

	cout << gcd(6, 24) << "\n";

	cout << revInt(5789) << "\n";

	return 0;
}