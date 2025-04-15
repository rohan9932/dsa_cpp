#include <bits/stdc++.h>
using namespace std;

#define PI 3.1416

//inline func -> same concept like macro just in case of a function
//1 line -> inline
//1-3 line -> depends on compiler
//>3 line -> impossible for inline 
inline int max(int& a, int& b) {
	return (a > b) ? a : b;
}

//default argument -> start from rightmost argument always
void print(int arr[], int n, int start = 0) {
	for(int i = start; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
}

int main() {
	#ifndef OJ
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int r;
	cin >> r;
	double area = PI * r * r;

	cout << area << "\n";

	cout << max(5, 7) << "\n";

	int arr[] = {1, 2, 3, 4, 5};

	print(arr, 5, 3);


	return 0;
} 