#include <bits/stdc++.h>
using namespace std;

void helper(vector<vector<int>> &mat, int row, int col, string path, vector<string>& ans) {
	int n = mat.size();
	//Base case
	if(row < 0 || col < 0 || row >= n || col >= n || mat[row][col] == 0 || mat[row][col] == -1) {
		return;
	}
	if(row == n-1 && col == n-1) {
		ans.push_back(path);
		return;
	}

	mat[row][col] = -1;

	helper(mat, row-1, col, path+"U", ans); //not needing to remove string while backtracking as it is passed by value
	helper(mat, row+1, col, path+"D", ans);
	helper(mat, row, col+1, path+"R", ans);
	helper(mat, row, col-1, path+"L", ans); 

	mat[row][col] = 1; //backtracking
}

vector<string> findPath(vector<vector<int>> &mat) {
    vector<string> ans;
    string path = "";
    helper(mat, 0, 0, path, ans);

    return ans;
}

int main() {
	#ifndef OJ
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	vector<vector<int>> mat = {{1, 0, 0, 0},
								{1, 1, 0, 1},
								{1, 1, 0, 0},
								{0, 1, 1, 1}};

	vector<string> ans = findPath(mat);

	for(auto str: ans) {
		cout << str << "\n";
	}

	return 0;
}