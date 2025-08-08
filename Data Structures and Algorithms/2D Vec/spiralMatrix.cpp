#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& mat){
	vector<int> spiral;
	int m = mat.size(), n = mat[0].size();
	int srow = 0, scol = 0, erow = m-1, ecol = n-1;

	while(srow <= erow && scol <= ecol) {
		//top
		for(int j = scol; j <= ecol; j++) {
			spiral.push_back(mat[srow][j]);
		}

		//right
		for(int i = srow+1; i <= erow; i++) {
			spiral.push_back(mat[i][ecol]);
		}

		//bottom
		for(int j = ecol-1; j >= scol; j--) {
			if(srow == erow) {
				break;
			}
			spiral.push_back(mat[erow][j]);
		}

		//left
		for(int i = erow-1; i >= srow+1; i--) {
			if(scol == ecol) {
				break;
			}
			spiral.push_back(mat[i][scol]);
		}

		srow++; scol++; erow--; ecol--;
	}

	return spiral;
}

int main() {
	vector<vector<int>> v = {{1,2,3,4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

	vector<int> sp = spiralOrder(v);

	for(auto val: sp) {
		cout << val << " ";
	}
	cout << "\n";
 
	return 0;
}