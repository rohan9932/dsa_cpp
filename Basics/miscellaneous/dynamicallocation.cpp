#include <bits/stdc++.h>
using namespace std;

int sumofArr(int *arr, int n) {
	int sum = 0;
	for(int i =0 ; i < n; i++) {
		sum += arr[i];
	}

	return sum;
}

int main() {
	#ifndef OJ
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout);
	#endif

	// //variable size array
	// int n;
	// cin >> n;

	// int *arr = new int[n];

	// for(int i = 0; i < n; i++) {
	// 	cin >> arr[i]; // as we know in static mem *arr == arr[i] so we can access all the values here in  dynamic array by arr[i]
	// }

	// cout << sumofArr(arr, n) << "\n";

	// delete []arr; //releasing heap memory


	//2D array
	int row, col;
	cin >> row >> col;

	int** arr2d = new int*[row]; //creating row size arrays dynamically

	//creating cols for dynamic 2d array
	for(int i =0; i < row; i++) {
		arr2d[i] = new int[col];
	}

	//taking input
	for(int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++) {
			cin >> arr2d[i][j];
		}
	}

	//output
	for(int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++) {
			cout << arr2d[i][j] << " ";
		}
		cout << "\n";
	}

	//releasing memory

	//first have to release the memories of ints in the rows
	for(int i = 0; i < row; i++) {
		delete []arr2d[row];
	}

	//then delete the rows array
	delete []arr2d;

	return 0;
}