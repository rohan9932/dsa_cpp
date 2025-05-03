#include <bits/stdc++.h>
using namespace std;

vector<int> prevsmallerelement(vector<int>& arr) {
	stack<int> s;
	vector<int> ans;

	for(int i = 0; i < arr.size(); i++) {
		while(!s.empty() && arr[s.top()] >= arr[i]) {
			s.pop();
		}

		if(s.empty()) ans.push_back(-1);
		else ans.push_back(arr[s.top()]);

		s.push(i);
	}

	return ans;
}

int main() {
	#ifndef OJ
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	vector<int> v = {1, 5, 9, 7, 4};
	vector<int> ans = prevsmallerelement(v);

	for(int val: ans) {
		cout << val << " ";
	}
	cout << "\n";

	return 0;
}