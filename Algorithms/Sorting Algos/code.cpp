#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>& arr, int n) {
	for(int i = 0; i < n - 1; i++) {
		for(int j = 0; j < n-i-1; j++) {
			if(arr[j] > arr[j+1]) {
				swap(arr[j], arr[j+1]);
			}
		}
	}
}

void invbubbleSort(vector<int>& arr, int n) {
	for(int i = 0; i < n - 1; i++) {
		for(int j = 0; j < n-i-1; j++) {
			if(arr[j] < arr[j+1]) {
				swap(arr[j], arr[j+1]);
			}
		}
	}
}

void selectionSort(vector<int>& arr, int n) { //O(n^2)
	for(int i = 0; i < n-1; i++) {
		int smallestIdx = i; // unsorted part starting
		for(int j = i+1; j < n; j++) {
			if(arr[j] < arr[smallestIdx]) {
				smallestIdx = j;
			}
		}
		swap(arr[i], arr[smallestIdx]);
	}
}

void invselectionSort(vector<int>& arr, int n) { //O(n^2)
	for(int i = 0; i < n-1; i++) {
		int greatestIdx = i; // unsorted part starting
		for(int j = i+1; j < n; j++) {
			if(arr[j] > arr[greatestIdx]) {
				greatestIdx = j;
			}
		}
		swap(arr[i], arr[greatestIdx]);
	}
}


void insertionSort(vector<int>& arr, int n) { //O(n^2)
	for(int i = 1; i < n; i++) {
		int curr = arr[i];
		int prev = i - 1;
		while(prev >= 0 && arr[prev] > curr) {
			arr[prev+1] = arr[prev];
			prev--;
		}
		arr[prev+1] = curr; //placing the curr element in it's correct position
	}
}

void invinsertionSort(vector<int>& arr, int n) { //O(n^2)
	for(int i = 1; i < n; i++) {
		int curr = arr[i];
		int prev = i - 1;
		while(prev >= 0 && arr[prev] < curr) {
			arr[prev+1] = arr[prev];
			prev--;
		}
		arr[prev+1] = curr; //placing the curr element in it's correct position
	}
}

//Merge Sort
void merge(vector<int>& arr, int st, int mid, int end) {
	vector<int> temporary;
	int i = st, j = mid+1;

	//merging the sorted arrays
	while(i <= mid && j <= end) {
		if(arr[i] <= arr[j]) {
			temporary.push_back(arr[i]);
			i++;
		} else {
			temporary.push_back(arr[j]);
			j++;
		}
	}

	//putting remaining values
	while(i <= mid) {
		temporary.push_back(arr[i]);
		i++;
	}
	while(j <= end) {
		temporary.push_back(arr[j]);
		j++;
	}

	//copy the temp value to main array
	for(int idx = 0; idx < temporary.size(); idx++) {
		arr[st + idx] = temporary[idx];
	}
}

void mergeSort(vector<int>& arr, int st, int end) {
	if(st < end) {
		int mid = st + (end-st)/2;
		mergeSort(arr, st, mid); //left side
		mergeSort(arr, mid+1, end); //right side

		merge(arr, st, mid, end); //merging the left and right arrays
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
	for(int i = 0; i < 5; i++) {
		int n;
		cin >> n;
		arr.push_back(n);
	}

	int n = arr.size();

	mergeSort(arr, 0, n-1);

	for(int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	return 0;

}