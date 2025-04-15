#include <bits/stdc++.h>
using namespace std;

// //Bad Practice -> as num is a local variable and gets deleted after function life span
// int& func(int a) {
// 	int num = a;
// 	int& ans = num;
// 	return ans;
// }

int& func(int& a) {
	return a;
}

int main() {
	#ifndef OJ
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int i = 5;
	int& j = i;

	cout << ++j << "\n";

	cout << func(i) << "\n"; 

	return 0;
}