#include <bits/stdc++.h>
using namespace std;

void printSubsetsIncFirst(vector<int>& arr, vector<int> ans, int i) {
	if(i == arr.size()) {
		for(int val: ans) {
			cout << val << " ";
		}
		cout << "\n";
		return;
	}

	//include
	ans.push_back(arr[i]);
	printSubsetsIncFirst(arr, ans, i+1);

	ans.pop_back(); //backtrack
	//exclude
	printSubsetsIncFirst(arr, ans, i+1);
}

void printSubsetsExcludeFirst(vector<int>& arr, vector<int> ans, int i) {
	if(i == arr.size()) {
		for(int val: ans) {
			cout << val << " ";
		}
		cout << "\n";
		return;
	}

	printSubsetsExcludeFirst(arr, ans, i+1);
	ans.push_back(arr[i]);
	printSubsetsExcludeFirst(arr, ans, i+1);
}



int main() {
	#ifndef OJ
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	//code
	vector<int> arr = {1, 2, 3};
	vector<int> ans;
	printSubsetsIncFirst(arr,ans, 0);
	printSubsetsExcludeFirst(arr, ans, 0);
} 