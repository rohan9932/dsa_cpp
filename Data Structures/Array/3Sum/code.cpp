#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSumBruteForce(vector<int>& nums) {
    vector<vector<int>>ans;
    int n = nums.size();

    set<vector<int>> s; 

    for(int i = 0; i < n; i++) {
    	for(int j = i+1; j < n; j++) {
    		for(int k = j+1; k < n; k++) {
    			if(nums[i] + nums[j] + nums[k] == 0) {
    				vector<int> v = {nums[i], nums[j], nums[k]};
    				sort(v.begin(), v.end());

    				if(s.find(v) == s.end()) {
    					s.insert(v);
    					ans.push_back(v);
    				}    			
    			}
    		}
    	}
    }

    return ans;
}

vector<vector<int>> threeSumHashing(vector<int>& nums) {
    vector<vector<int>> ans;
    int n = nums.size();

    set<vector<int>> vecs;

    for(int i = 0; i < n; i++) {
    	int tar = -nums[i];
    	set<int> s;
    	for(int j = i+1; j < n; j++) {
    		int toFind = tar - nums[j];
    		if(s.find(toFind) == s.end()) {
    			s.insert(nums[j]);
    		} else {
				vector<int> v = {nums[i], nums[j], toFind};
				sort(v.begin(), v.end());
				
				if(vecs.find(v) == vecs.end()) {
					vecs.insert(v);
					ans.push_back(v);
				}
    		}
    	}
    }

    return ans;
}

vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    int n = nums.size();

    for(int i = 0; i < n; i++) {
    	if((i>0) && (nums[i] == nums[i-1])) continue; //for preventing duplicates of ith value

    	int j = i+1, k = n-1;
    	while(j<k) {
    		int sum = nums[i] + nums[j] + nums[k];
    		if(sum<0) j++;
    		else if(sum>0) k--;
    		else {
    			vector<int> v = {nums[i], nums[j], nums[k]};
    			ans.push_back(v);
    			j++, k--;

    			while((j<k) && (nums[j] == nums[j-1])) j++; //for preventing duplicates of jth value and kth will automatically resolve
    		}
    	}
    }

    return ans;
}

int main() {
	#ifndef OJ
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	//code
	vector<int> nums = {-1, 0, 1, 2, -1, 4};

	vector<vector<int>> ans = threeSum(nums);

	for(int i = 0; i < ans.size(); i++) {
		for(int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}