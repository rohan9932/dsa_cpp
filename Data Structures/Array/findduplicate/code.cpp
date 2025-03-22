#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int>& nums) {
    int slow = 0, fast = 0;
    do {
    	slow = nums[slow];
    	fast = nums[nums[fast]];
    } while (slow != fast);

    slow = 0;
    while(slow != fast) {
    	slow = nums[slow];
    	fast = nums[fast];
    }

    return slow;
}

int findDuplicateset(vector<int>& nums) {
    unordered_set<int> s;

    for(auto val: nums) {
    	if(s.find(val) != s.end()) {
    		return val;
    	} else {
    		s.emplace(val);
    	}
    }

    return -1;
}

int main() {
	#ifndef OJ
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	//code
	vector<int> nums = {1, 3, 4, 2, 2};

	cout << findDuplicate(nums) << "\n";
	cout << findDuplicateset(nums) << "\n";

	return 0;
}