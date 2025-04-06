#include <bits/stdc++.h>
using namespace std;

void getAllCombinations(vector<int>& candidates, int target, vector<int>& combination, set<vector<int>>& s, int idx) {
    if(idx == candidates.size() || target < 0) return;
    if(target == 0) {
        s.insert(combination);
        return;
    }

    //single inclusion
    combination.push_back(candidates[idx]);
    getAllCombinations(candidates, target-candidates[idx], combination, s, idx+1);
    //multiple inclusion
    getAllCombinations(candidates, target-candidates[idx], combination, s, idx);
    //exclusion
    combination.pop_back(); //backtracking step
    getAllCombinations(candidates, target, combination, s, idx+1);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    set<vector<int>> s;
    vector<int> combination;
    getAllCombinations(candidates, target, combination, s, 0);

    vector<vector<int>> ans(s.begin(), s.end());
    return ans;
}

int main() {
	#ifndef OJ
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	vector<int> vec = {2, 3, 5};
	int target;
	cin >> target;

	vector<vector<int>> ans = combinationSum(vec, target);

	for(auto combination: ans) {
		for(auto val: combination) {
			cout << val << " ";
		}
		cout << "\n";
	}

	return 0;
}