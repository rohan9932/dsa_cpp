#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
	int m = matrix.size(), n = matrix[0].size();
	int sR = 0, endR = m-1;
	
	while(sR <= endR) {
		int midR = sR + (endR - sR)/2;

		if((matrix[midR][0] <= target) && (target <= matrix[midR][n-1])) {
			int st = 0, end = n-1;
			while(st <= end) {
				int mid = st + (end - st)/2;
				if(matrix[midR][mid] == target) {
					return true;
				} else if(matrix[midR][mid] < target) {
					st = mid + 1;
				} else {
					end = mid - 1;
				}
			}
			return false;
		} else if(target < matrix[midR][0]) {
			endR = midR - 1;
		} else {
			sR = midR + 1;
		}
	}       

	return false;
}

int main() {
	vector<vector<int>> matrix(3, vector<int>(4));

	for(int i = 0; i < matrix.size(); i++) {
		for(int j = 0; j < matrix[i].size(); j++) {
			cin >> matrix[i][j];
		}
	}

	cout << searchMatrix(matrix, 123) << "\n";

	return 0;	
}