#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();
    int st = 0, end = n - 1;
    
    while(st < end) {
        int mid = st + (end - st)/2 ;

        if(mid % 2 != 0) {
        	mid--;
        }
        if(nums[mid] == nums[mid+1]){
        	st = mid + 2;
        } else {
        	end = mid;
        }
    }

    return nums[st];
}

int main() {
	#ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen("input.txt", "r", stdin);
	//for writing output to output.txt
	freopen("output.txt", "w", stdout);
	#endif

	// your code goes here
	vector<int>nums = {1,1,2,3,3,4,4,8,8};
	cout << singleNonDuplicate(nums) << "\n";
}