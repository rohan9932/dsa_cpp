#include <bits/stdc++.h>
using namespace std;

string revWords(string s) {
	reverse(s.begin(), s.end());
	string ans = "";

	int n = s.length();
	for(int i = 0; i < n; i++) {
		string word = "";
		while(i < n && s[i] != ' ') {
			word += s[i];
			i++;
		}

		reverse(word.begin(), word.end());
		if(word.length() > 0) {
			ans += " " + word;
		}
	}

	return ans.substr(1);
}

int main() {
	string s;
	getline(cin, s);

	cout << revWords(s) << "\n";

	return 0;
}