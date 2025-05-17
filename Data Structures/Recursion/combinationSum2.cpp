#include <bits/stdc++.h>
using namespace std;

void getAllCombinations(vector<int>& candidates, int target, vector<int>& combination, vector<vector<int>>& ans, int i) {
	if(target == 0) {
		ans.push_back(combination);
		return;
	}
	if(i == candidates.size() || target < 0) return; 

	//include an element
	combination.push_back(candidates[i]);
	getAllCombinations(candidates, target-candidates[i], combination, ans, i+1);
	//exclude
	combination.pop_back();
	int idx = i+1;
	while(idx < candidates.size() && candidates[idx] == candidates[idx-1]) idx++; //skip the duplicates
	getAllCombinations(candidates, target, combination, ans, idx);
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> combination;
    getAllCombinations(candidates, target, combination, ans, 0);

    return ans;
}

int main() {
	#ifndef OJ
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	vector<int> v = {10, 1, 2, 7, 6, 1, 5};

	vector<vector<int>> ans = combinationSum2(v, 8);

	for(auto vec: ans){
		for (auto val: vec){
			cout << val << " ";
		}
		cout << "\n";
	}

	return 0;
}