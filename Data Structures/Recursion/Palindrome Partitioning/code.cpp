#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) {
	int st = 0, end = s.length() - 1;
	while(st <= end) {
		if(s[st] != s[end]) return false;
		st++, end--;
	}

	return true;
}

void getAllPartitions(string s, vector<string>& partitions, vector<vector<string>>& ans) {
	if(s.length() == 0) {
		ans.push_back(partitions);
		return;
	}

	for(int i = 0; i < s.length(); i++) {
		string part = s.substr(0, i+1);
		if(isPalindrome(part)) {
			partitions.push_back(part);
			getAllPartitions(s.substr(i+1), partitions, ans);
			partitions.pop_back(); //backtracking step
		}
	}
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> partitions;
    getAllPartitions(s, partitions, ans);

    return ans;
}

int main() {
	#ifndef OJ
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	string s;
	cin >> s;

	vector<vector<string>> ans = partition(s);

	for(auto vec: ans) {
		for(auto str: vec) {
			cout << str << " ";
		}
		cout << "\n";
	}

	return 0;
}