#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
	int m = matrix.size(), n = matrix[0].size();
	int row = 0, col = n-1;

	while(row < m && col >= 0) {
		if(target == matrix[row][col]) return true;
		else if(target < matrix[row][col]) col--;
		else row++;
	}

	return false;
}

int main() {
	vector<vector<int>> matrix = {5, vector<int> (5)};

	for(int i = 0; i < matrix.size(); i++) {
		for(int j = 0; j < matrix[i].size(); j++) {
			cin >> matrix[i][j];
		}
	}

	cout << searchMatrix(matrix, 76) << "\n";

	return 0;
}