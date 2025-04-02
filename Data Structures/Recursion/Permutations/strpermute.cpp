#include <bits/stdc++.h>
using namespace std;

void printPermutations(string& s, int idx) {
	if(idx == s.length()) {
		cout << s << "\n";
	}

	for(int i = idx; i < s.length(); i++) {
		swap(s[idx], s[i]);
		printPermutations(s, idx+1);
		swap(s[idx], s[i]); //reverting string to original in the previous level
	}
}

int main() {
	#ifndef OJ
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	string s = "abc";
	printPermutations(s, 0);

	return 0;
}