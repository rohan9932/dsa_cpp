#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreater(vector<int>& arr) {
	stack<int> s;
	vector<int> ans;

	for(int i = arr.size()-1; i >= 0; i--) {
		while(!s.empty() && s.top() <= arr[i]) {
			s.pop();
		}

		if(s.empty()) ans.push_back(-1);
		else ans.push_back(s.top());

		s.push(arr[i]);
	}
	reverse(ans.begin(), ans.end());

	return ans;
}

int main() {
	#ifndef OJ
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	vector<int> arr = {6, 8, 0, 1, 3};
	vector<int> ans = nextGreater(arr);

	for(int val: ans) {
		cout << val << " ";
	}
	cout << "\n";

	return 0;
}