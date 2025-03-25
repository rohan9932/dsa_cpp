#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
	vector<vector<int>> ans;
	sort(nums.begin(), nums.end());
	int n = nums.size();

	for(int i = 0 ; i < n; i++) {
		if(i > 0 && nums[i] == nums[i-1]) continue;
		for(int j = i+1; j < n; ) {
			int k = j+1, l = n-1;
			while(k < l) {
				long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[k] + (long long)nums[l];
				if(sum == target) {
					ans.push_back({nums[i], nums[j], nums[k], nums[l]});
					k++, l--;
					while((k < l) && nums[k] == nums[k-1]) k++;
				}
				else if(sum < target) k++;
				else l--;
			}

			j++;
			while(j < n && nums[j] == nums[j-1]) j++;
		}
	}

	return ans;
}

int main() {
	#ifndef OJ
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	vector<int> v = {-1, -1, 1, 1, -2, 2, 2};

	vector<vector<int>> ans = fourSum(v, 0);

	for(int i = 0; i < ans.size(); i++) {
		for(int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}

}