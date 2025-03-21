#include <bits/stdc++.h>
using namespace std;

bool isPallindrome(string str) {
	string rev_str = str;
	reverse(rev_str.begin(), rev_str.end());

	if(str == rev_str) {
		return true;
	} else {
		return false;
	}
}

int main() {
	#ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen("input.txt", "r", stdin);
	//for writing output to output.txt
	freopen("output.txt", "w", stdout);
	#endif

	// your code goes here
	string str;
	getline(cin, str);
		
	if(isPallindrome(str)) {
		cout << "Pallindrome" << "\n";
	} else {
		cout << "Not Pallindrome" << "\n";
	}

	return 0;

}