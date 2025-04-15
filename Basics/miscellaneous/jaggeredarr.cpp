#include <bits/stdc++.h>
using namespace std;

int main() {
	#ifndef OJ
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	//jaggered array
	int row, col;
	cin >> row;

	int cols[3] = {2, 3, 5};

	int** jaggeredarr = new int*[row];

	for(int i = 0; i < row; i++) {
		jaggeredarr[i] = new int[cols[i]];
	}

	for(int i = 0; i < row; i++) {
		for(int j = 0; j < cols[i]; j++) {
			cin >> jaggeredarr[i][j];
		}
	}

	for(int i = 0; i < row; i++) {
		for(int j = 0; j < cols[i]; j++) {
			cout << jaggeredarr[i][j] << " ";
		}
		cout << "\n";
	}

	for(int i = 0; i < row; i++) {
		delete []jaggeredarr[i];
	}

	delete []jaggeredarr;

	return 0;
}