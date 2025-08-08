#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& nums) {
	int n = nums.size();

	//find the pivot
	int pivot = -1;
	for(int i = n-2; i >= 0; i--) {
		if(nums[i] < nums[i+1]) {
			pivot = i;
			break;
		}
	}

	if(pivot == -1) {
		int i = 0, j = n-1;
		while(i <= j) {
			swap(nums[i], nums[j]);
			i++;
			j--;
		}
		return;
	}

	//find the RME > pivot
	for(int i = n-1; i > pivot; i--) {
		if(nums[i] > nums[pivot]) {
			swap(nums[i], nums[pivot]);
			break;
		}
	}

	//reverse pivot+1 to n-1
	int i = pivot+1, j = n-1;
	while(i <= j) {
		swap(nums[i], nums[j]);
		i++;
		j--;
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
	vector<int> nums;
	int n;

	cin >> n;

	for(int i = 0; i<n; i++) {
		int el;
		cin >> el;
		nums.push_back(el);
	}


	nextPermutation(nums);

	for(int i = 0; i < n; i++) {
		cout << nums[i] << " ";
	}
	cout << "\n";

}