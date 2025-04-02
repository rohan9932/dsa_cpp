#include <bits/stdc++.h>
using namespace std;

//set approach
void pushSubsets(set<vector<int>>& s, vector<int>& arr, vector<int> subset, int i) {
    if(i == arr.size()) {
        s.insert(subset);
        return;
    }

    pushSubsets(s, arr, subset, i+1);
    subset.push_back(arr[i]);
    pushSubsets(s, arr, subset, i+1);
}


vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    set<vector<int>> s; 
    vector<int> subset;
    pushSubsets(s, nums, subset, 0);

    vector<vector<int>> ans(s.begin(), s.end());
    return ans;
}

//rec approach
void pushSubsetsrec(vector<vector<int>>& ans, vector<int>& arr, vector<int> subset, int i) {
    if(i == arr.size()) {
        ans.push_back(subset);
        return;
    }

    subset.push_back(arr[i]);
    pushSubsetsrec(ans, arr, subset, i+1);
    subset.pop_back();
    int idx = i+1;
    while(idx < arr.size() && arr[idx] == arr[idx-1]) idx++;
    pushSubsetsrec(ans, arr, subset, idx);
}


vector<vector<int>> subsetsWithDuprec(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    vector<int> subset;
    pushSubsetsrec(ans, nums, subset, 0);

    return ans;
}

int main() {
	#ifndef OJ
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	vector<int> arr = {1, 2, 2};
	vector<vector<int>> subsets = subsetsWithDuprec(arr);

	for(auto vec: subsets) {
		for(auto val: vec) {
			cout << val << " ";
		}
		cout << "\n";
	}

	return 0;
}
