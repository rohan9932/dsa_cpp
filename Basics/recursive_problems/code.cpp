#include <bits/stdc++.h>
using namespace std;

int fib(int n) {
	if(n == 0 || n == 1) {
		return n;
	}

	return fib(n-1) + fib(n-2);
}

bool isSorted(vector<int>& arr, int n) {
	if(n == 0 || n == 1) {
		return true;
	}

	return arr[n-1] >= arr[n-2] && isSorted(arr, n-1);
}

int binSearch(vector<int>& arr, int tar, int st, int end) {
	if(st <= end) {
		int mid = st + (end - st) / 2;

		if(arr[mid] == tar) return mid;
		else if(arr[mid] < tar) return binSearch(arr, tar, mid+1, end);
		else return binSearch(arr, tar, st, mid-1);
	}

	return -1;
}

int main() {
	#ifndef OJ
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	cout << fib(6) << "\n";

	vector<int> arr = {1, 2, 3, 4, 5};

	if(isSorted(arr, arr.size())) {
		cout << "ase" << "\n";
	} else {
		cout << "nai" << "\n";
	}

	cout << binSearch(arr, 5, 0, arr.size()-1) << "\n";

	return 0;
}