#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<char>>& board, int row, int col, char ch) {
	//row
	for(int j = 0; j < 9; j++) {
		if(board[row][j] == ch) return false;
	}
	//col
	for(int i = 0; i < 9; i++) {
		if(board[i][col] == ch) return false;
	}
	//small 3x3 grid
	int st_row = row - row % 3;
	int st_col = col - col % 3;

	for(int i = st_row; i < st_row+3; i++) {
		for(int j = st_col; j < st_col+3; j++) {
			if(board[i][j] == ch) return false;
		}
	}

	return true;
}

void helper(vector<vector<char>>& board, int cellIdx, bool& solved) {
	if(cellIdx == 81) {
		solved = true;
		return;
	}

	int row = cellIdx / 9;
	int col = cellIdx % 9;

	if(board[row][col] == '.') {
		for(char d = '1'; d <= '9'; d++) {
			if(isSafe(board, row, col, d)) {
				board[row][col] = d;
				helper(board, cellIdx+1, solved);
				if(solved) return; //preventing backtracking if solved
				board[row][col] = '.';
			}
		}
		return; //backtracking if none number can be placed
	} else {
		helper(board, cellIdx+1, solved); //skipping if place is filled
	}
}

void solveSudoku(vector<vector<char>>& board) {
	bool solved = false;
    helper(board, 0, solved);
}

int main() {
	#ifndef OJ
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},
								{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},
								{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};

	solveSudoku(board);

	for(auto row: board) {
		for(auto val: row) {
			cout << val << " ";
		}
		cout << "\n";
	}

	return 0;
}