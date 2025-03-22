#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> ans;
	unordered_map<int, int> m;

	for(int i = 0; i < nums.size(); i++) {
		int first = nums[i];
		int second = target - first;

		if(m.find(second) != m.end()) {
			ans.push_back(i);
			ans.push_back(m[second]);
			break;
		} else {
			m[first] = i;
		}
	}

	return ans;
}

int main() {
	#ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen("input.txt", "r", stdin);
	//for writing output to output.txt
	freopen("output.txt", "w", stdout);
	#endif

	// your code goes here
	vector<int> nums = {5, 2, 11, 7, 15};
	vector<int> two_sum = twoSum(nums, 9);

	for(auto val: two_sum) {
		cout << val << "\n";
	}

	return 0;
}