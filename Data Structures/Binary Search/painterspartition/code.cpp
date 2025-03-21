#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<int> &arr, int N, int M, int mid) {
	int painter = 1, time = 0;
	for(int i = 0; i < N; i++) { //O(N)
		if(arr[i] > mid) {
			return false;
		}
		if(arr[i] + time <= mid) {
			time += arr[i];
		} else {
			painter++;
			time = arr[i];
		}
	}
	return (painter > M) ? false: true;
}

int paintersPartition(vector<int> &arr, int N, int M) {
	int st = 0, end = accumulate(arr.begin(), arr.end(), 0), ans = -1;
	while(st <= end) { //O(log(sum))
		int mid = st + (end - st)/2 ;
		if(isValid(arr, N, M, mid)) {
			ans = mid;
			end = mid - 1;
		} else {
			st = mid + 1;
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
	vector<int> arr = {40, 30, 10, 20};
	cout << paintersPartition(arr, 4, 2) << "\n";

}