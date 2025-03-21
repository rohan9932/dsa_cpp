#include <bits/stdc++.h>
using namespace std;

pair<int, int> linearSearch(int arr[][3], int rows, int columns, int key) {
	pair<int, int> p = {-1, -1};
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++) {
			if(arr[i][j] == key) {
				p = {i, j};
			}
		}
	}

	return p;
}

int maxRowSum(int arr[][3], int rows, int columns) {
	int maxSum = INT_MIN;
	for(int i = 0; i < rows; i++) {
		int rowSum = 0;
		for(int j = 0; j < columns; j++) {
			rowSum += arr[i][j];
		}
		maxSum = max(rowSum, maxSum);
	}

	return maxSum;
}

int maxColSum(int arr[][3], int rows, int columns) {
	int maxSum = INT_MIN;
	for(int j = 0; j < columns; j++) {
		int colSum = 0;
		for(int i = 0; i < rows; i++) {
			colSum += arr[i][j];
		}
		maxSum = max(colSum, maxSum);
	}
	return maxSum;
}

int diagonalSum_nSq(int arr[][4], int n) {
	int digSum = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(i == j) {
				digSum += arr[i][j]; //Primary Diagonal
			} else if(j == n-1-i) {
				digSum += arr[i][j]; //Secondary Diagonal
			}
		}
	}

	return digSum;
}

int diagonalSum_n(int arr[][4], int n) {
	int digSum = 0;

	//pd -> i == j
	//sd -> j == n-1-i

	for(int i = 0; i < n; i++) {
		digSum += arr[i][i];
		//for avoiding common value
		if(i != n-1-i) {
			digSum += arr[i][n-1-i];
		}
	}

	return digSum;
}

int main() {
	// int matrix[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}}; //2D array
	// int rows = 4;
	// int columns = 3;

	// //------------print a 2D array-----------
	// for(int i = 0; i < rows; i++) {
	// 	for(int j = 0; j < columns; j++) {
	// 		cout << matrix[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }

	// //------------2D arr input-----------
	// int matrix2[4][3];
	// for(int i = 0; i < rows; i++) {
	// 	for(int j = 0; j < columns; j++) {
	// 		cin >> matrix2[i][j];
	// 	}
	// }

	// for(int i = 0; i < rows; i++) {
	// 	for(int j = 0; j < columns; j++) {
	// 		cout << matrix2[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }


	// //----------Linear Search----------
	// int target = 8;

	// for(int i = 0; i < rows; i++) {
	// 	for(int j = 0; j < columns; j++) {
	// 		if(matrix[i][j] == target) {
	// 			cout << i << " " << j << "\n";
	// 		}
	// 	}
	// }

	// pair<int, int> p = linearSearch(matrix, 4, 3, 11);
	// cout << p.first << " " << p.second << "\n";


 
	// //--------------MAXIMUM ROW SUM-------------
	// cout << maxRowSum(matrix, rows, columns) << "\n";
	// cout << maxColSum(matrix, rows, columns) << "\n";


	// //--------------DIAGONAL SUM-----------------
	// int sq_matrix[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}}; //2D array
	// int n = 4;

	// cout << diagonalSum_nSq(sq_matrix, 4) << "\n";
	// cout << diagonalSum_n(sq_matrix, 4) << "\n";



	//----------------2D VECTORS---------------
	vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6, 10, 11, 12}, {7, 8, 9}};

	// rows -> matrix.size()  columns -> matrix[i].size()

	for(int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}


	return 0;
}