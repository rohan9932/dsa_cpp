#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
	vector<int> ans;
	unordered_set<int> s;
	int n = grid.size();
	int a, b;

	int expSum = (n*n)*((n*n)+ 1)/2, actSum = 0;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			//calculate sum
			actSum += grid[i][j];

			//missing el find
			if(s.find(grid[i][j]) != s.end()) {
				a = grid[i][j];
				ans.push_back(a);
				break;
			} else {
				s.emplace(grid[i][j]);
			}
		}
	}

	b = expSum + a - actSum;
	ans.push_back(b);

	return ans;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	//code
	vector<vector<int>> grid = {{1,3}, {2,2}};

	vector<int> ans_vec = findMissingAndRepeatedValues(grid);
	for(auto val: ans_vec) {
		cout << val << " ";
	}

	return 0;
}