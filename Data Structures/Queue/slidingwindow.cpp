#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
	vector<int> ans;
	deque<int> dq;

	for(int i = 0; i < k; i++) {
		while(!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
		dq.push_back(i);
	}

	for(int i = k; i < nums.size(); i++) {
		ans.push_back(nums[dq.front()]); //ans
		while(!dq.empty() && dq.front() <= i-k) dq.pop_front(); //just keeping the curr window elements in deque
		while(!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back(); //remove smaller vals
		dq.push_back(i);
	}

	ans.push_back(nums[dq.front()]);

	return ans;
}

int main() {
	vector<int> nums = {1, 3, -1, 3, 5, 3, 6, 7};
	vector<int> ans = maxSlidingWindow(nums, 3);

	for(int val: ans) cout << val << " ";
	cout << "\n";
	return 0;
}