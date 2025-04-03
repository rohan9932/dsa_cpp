#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<string>& board, int row, int col, int n) {
	//vertical
	for(int i = 0; i < n; i++) {
		if(board[i][col] == 'Q') return false; 
	} 
	//horizontal
	for(int j = 0; j < n; j++) {
		if(board[row][j] == 'Q') return false;
	}
	//diagonal
	for(int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--) {
		if(board[i][j] == 'Q') return false;
	}
	for(int i = row-1, j = col+1; i >= 0 && j <= n; i--, j++) {
		if(board[i][j] == 'Q') return false;
	}

	return true;
}

void nqueens(vector<string>& board, int row, int n, vector<vector<string>>& ans) {
	if(row == n) {
		ans.push_back(board);
		return;
	}

	for(int j = 0; j < n; j++) {
		if(isSafe(board, row, j, n)) {
			board[row][j] = 'Q';
			nqueens(board, row+1, n, ans);
			board[row][j] = '.';
		}
	}
}

vector<vector<string>> solveNQueens(int n) {
	vector<string> board(n, string(n, '.'));
	vector<vector<string>> ans;
    nqueens(board, 0, n, ans);
    return ans;
}

int main() {
	#ifndef OJ
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin >> n;

	vector<vector<string>> ans = solveNQueens(n);

	for(auto vec: ans) {
		for(auto str: vec) {
			cout << str << "\n";
		}
		cout << "\n\n";
	}

	return 0;
}