#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<int>& arr, int N, int C, int mid) {
	int cows = 1, lastPos = arr[0];
	for(int i = 1; i < N; i++) {
		if((arr[i] - lastPos) >= mid) {
			cows++;
			lastPos = arr[i];
		}
		if(cows == C) {
			return true;
		}
	}
	return false;
}

int AggressiveCows(vector<int>& arr, int N, int C) {
	sort(arr.begin(), arr.end()); 
	int st = 0, end = arr[N-1] - arr[0], ans = -1;
	while (st <= end) {
		int mid = st + (end - st)/2 ;
		if(isValid(arr, N, C, mid)) { // right
			ans = mid;
			st = mid + 1;
		} else { // left
			end = mid - 1;
		}
	}
	return ans;
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
	int N, C;

	cin >> N >> C;

	for(int i = 0; i < N; i++) {
		int position;
		cin >> position;
		arr.push_back(position);
	}

	cout << AggressiveCows(arr, N, C) << "\n";

	return 0;

}