#include <bits/stdc++.h>
using namespace std;
 
void bruteForce(vector<int>& arr, int n) { //O(n^2)
	for(int i = 0; i < n; i++) {
		int currIdx = i; 
		for(int j = i+1; j < n; j++) { // start of the inner arr except the sorted
			if(arr[j] < arr[i]){
				currIdx = j;
			}
		}
		swap(arr[i], arr[currIdx]);
	}
}

void easybruteForce(vector<int>& arr) { //O(nlogn)
	sort(arr.begin(), arr.end());
}

void slightOptimized(vector<int>& arr, int n) { //O(n) -> Single Pass
	int count_zero = 0, count_one = 0, count_two = 0;
	for(int i = 0; i < n; i++) {
		if(arr[i] == 0) {
			count_zero++;
		} else if(arr[i] == 1) {
			count_one++;
		} else {
			count_two++;
		}
	}

	arr.clear();

	//overwrite 
	for(int i = 0; i < count_zero; i++) {
		arr.push_back(0);
	}
	for (int i = 0; i < count_one; i++) {
		arr.push_back(1);
	}
	for(int i = 0; i < count_two; i++) {
		arr.push_back(2);
	}
}

void dNF(vector<int>& arr) { //O(N) //SC:O(1)
	int n = arr.size();
	int mid = 0, high = n-1, low = 0;
	while(mid <= high) {
		if(arr[mid] == 0) {
			swap(arr[low], arr[mid]);
			low++;
			mid++;
		} else if(arr[mid] == 1) {
			mid++;
		} else {
			swap(arr[high], arr[mid]);
			high--;
		}
	}
}

int main() {
	#ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen("input.txt", "r", stdin);
	//for writing output to output.txt
	freopen("output.txt", "w", stdout);
	#endif

	// your code goes here
	vector<int> arr;

	for(int i = 0; i < 10; i++) {
		int el;
		cin >> el;
		arr.push_back(el);
	}

	int n = arr.size();

	// bruteForce(arr, n);
	dNF(arr);

	for(int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";

	return 0;
}