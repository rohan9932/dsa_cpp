#include <bits/stdc++.h>
using namespace std;

void reverseString(vector<char>& s) {
    int n = s.size();
    int st = 0, end = n-1; 

    while(st <= end) {
        swap(s[st], s[end]);
        st++;
        end--;
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

	vector<char> s;
	for(char ch: str) {
		s.emplace_back(ch);
	}

	reverseString(s);

	for(char ch: s) {
		cout << ch << " ";
	}
	cout << "\n";

	return 0;
}