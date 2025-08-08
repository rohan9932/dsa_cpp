#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterelement2(vector<int>& nums) {
	int n = nums.size();
	stack<int> s;
	vector<int> ans(n, -1);

	for(int i = (2*n)-1; i >= 0; i--) {
		while(!s.empty() && nums[s.top()] <= nums[i%n]) s.pop();
		if(!s.empty()) ans[i%n] = nums[s.top()];
		s.push(i%n);
	}

	return ans;
}

int main() {
	#ifndef OJ
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	vector<int> nums = {1, 2, 3, 4, 3};
	vector<int> ans = nextGreaterelement2(nums);

	for(int val: ans) cout << val << " ";
	cout << "\n";

	return 0;
}