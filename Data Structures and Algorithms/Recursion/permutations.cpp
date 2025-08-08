#include <bits/stdc++.h>
using namespace std;

void getPermms(vector<int>& nums, int idx, vector<vector<int>>& ans) {
	if(idx == nums.size()) {
		ans.push_back(nums);
		return;
	}

	for(int i = idx; i < nums.size(); i++) {
		swap(nums[idx], nums[i]); //idx place -> ith element choice
		getPermms(nums, idx+1, ans);
		swap(nums[idx], nums[i]); //making nums arr like before before returning
	}
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    getPermms(nums, 0, ans);
    return ans;
}

int main() {
	#ifndef OJ
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	//code 
	vector<int> nums = {1, 2, 3};

	vector<vector<int>> ans = permute(nums);

	for(auto row: ans) {
		for(auto val: row) {
			cout << val << " ";
		} 
		cout << "\n";
	}

	return 0;
}