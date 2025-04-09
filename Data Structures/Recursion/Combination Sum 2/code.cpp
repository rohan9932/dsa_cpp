#include <bits/stdc++.h>
using namespace std;

void getAllCombinations(vector<int>& candidates, int target, vector<int>& combination, set<vector<int>>& s, int i) {
	if(target == 0) {
		s.insert(combination);
		return;
	}
	if(i == candidates.size() || target < 0) return; 

	//include an element
	combination.push_back(candidates[i]);
	getAllCombinations(candidates, target-candidates[i], combination, s, i+1);
	//exclude
	combination.pop_back();
	int idx = i+1;
	while(idx < candidates.size() && candidates[i] == candidates[i-1]) idx++; //skip the duplicates
	getAllCombinations(candidates, target, combination, s, idx);
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	sort(candidates.begin(), candidates.end());
    set<vector<int>> s;
    vector<int> combination;
    getAllCombinations(candidates, target, combination, s, 0);

    vector<vector<int>> ans(s.begin(), s.end());
    return ans;
}

int main() {
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