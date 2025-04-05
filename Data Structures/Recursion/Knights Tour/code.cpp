#include <bits/stdc++.h>
using namespace std;

void helper(vector<vector<int>>& grid, int row, int col, int cellNo, bool& possible, int n) {
    //base case
    if(cellNo == n*n - 1) {
        possible = true;
        return;
    }
    
    vector<pair<int,int>> positions = {{-2, -1}, {-2,1} , {2, -1}, {2, 1}, {1,-2}, {1,2}, {-1,-2}, {-1,2}};
    
    for(auto pos: positions) {
        int new_row = row + pos.first;
        int new_col = col + pos.second;
        
        if(new_row >= 0 && new_col >= 0 && new_row < n && new_col < n) { //grid boundary 
            if(grid[new_row][new_col] == cellNo + 1) { //checking the next move cell
                helper(grid, new_row, new_col, cellNo+1, possible, n);
                if(possible) return; //early return if true
             }
        }
    }
}

bool checkValidGrid(vector<vector<int>>& grid) {
    bool possible = false;
    if(grid[0][0] != 0) return false;
    helper(grid, 0, 0, 0, possible, grid.size());
    return possible;
}

int main() {
	#ifndef OJ
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	vector<vector<int>> grid = {{0,11,16,5,20},{17,4,19,10,15},{12,1,8,21,6},{3,18,23,14,9},{24,13,2,7,22}};

	cout << (checkValidGrid(grid) ? "Possible" : "Not Possible") << "\n";

	return 0;
}