#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<int>& arr, int n, int k, int mid){
    int stu = 1, pages = 0;
    for(int i = 0; i<n; i++) {
        if(arr[i] > mid) {
            return false;
        }
        if(pages + arr[i] <= mid) {
            pages+=arr[i];
        } else {
            stu++;
            pages = arr[i];
        }
    }
    return (stu > k) ? false: true;
}

int findPages(vector<int> &arr, int k) {
    // code here
    int n = arr.size();
    if (k > n) {
        return -1;
    }
    int st = 0, end = accumulate(arr.begin(), arr.end(), 0), ans = -1;
    while(st <= end) {
        int mid = st + (end-st)/2 ;
        if(isValid(arr, n, k, mid)) {
            ans = mid;
            end = mid - 1; // move left
        } else {
            st = mid + 1; // move right
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
	vector<int> arr = {15, 17, 20};
	cout << findPages(arr, 2) << "\n";

	return 0;
}