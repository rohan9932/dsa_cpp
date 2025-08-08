#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterelement1(vector<int>& nums1, vector<int>& nums2) {
	stack<int> s;
	vector<int> ans;
	unordered_map<int, int> m;

	for(int i = nums2.size()-1; i >= 0; i--) {
		while(!s.empty() && nums2[i] >= s.top()) {
			s.pop();
		}

		if(s.empty()) m[nums2[i]] = -1;
		else m[nums2[i]] = s.top();

		s.push(nums2[i]);
	}

	for(int i = 0; i < nums1.size(); i++) {
		ans.push_back(m[nums1[i]]);
	}

	return ans;
}

int main() {
	#ifndef OJ
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	vector<int> nums1 = {4, 1, 2};
	vector<int> nums2 = {1, 3, 4, 2};

	vector<int> ans = nextGreaterelement1(nums1, nums2);

	for(int val: ans) {
		cout << val << " ";
	}
	cout << "\n";

	return 0;
}