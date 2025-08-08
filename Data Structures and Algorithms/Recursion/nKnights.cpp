#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<string>& board, int row, int col, int n) {
	vector<pair<int, int>> avoiding_positions = {{-2, -1}, {2, -1}, {-2, 1}, {2, 1},
												 {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

	for(auto pos: avoiding_positions) {
		int new_row = row + pos.first;
		int new_col = col + pos.second;

		if(new_row >= 0 && new_row < n && new_col >= 0 && new_col < n && board[new_row][new_col] == 'K') {
			return false;
		}
	}

	return true;
}

void nKnights(vector<string>& board, int placedKnight, int cellIdx, int n, vector<vector<string>>& ans) {
	if(placedKnight == n) {
		ans.push_back(board);
		return;
	}

	for(int cell = cellIdx; cell < n*n; cell++) {
		//find out row and col from cell num
		int row = cell / n; 
		int col = cell % n;

		if(isSafe(board, row, col, n)) {
			board[row][col] = 'K';
			nKnights(board, placedKnight+1, cell+1, n, ans);
			board[row][col] = '.'; //backtracking step
		}
	}

}

vector<vector<string>> solveNKnights(int n) {
	vector<vector<string>> ans;
	vector<string> board(n, string(n, '.'));
	nKnights(board, 0, 0, n, ans);

	return ans;
}

int main() {
	#ifndef OJ
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin >> n;
	vector<vector<string>> ans = solveNKnights(n);

	for(auto vec: ans) {
		for(auto str: vec) {
			for(auto ch: str) {
				cout << ch << " ";
			}
			cout << "\n";
		}
		cout << "\n\n";
	}

	return 0;
}