#include<bits/stdc++.h>
using namespace std;

int topDown(vector<int>& nums1, vector<int>& nums2, int idx, bool swapped, vector<vector<int>>& dp) {
    if(idx == nums1.size()) return 0;
    if(dp[idx][swapped] != -1) return dp[idx][swapped];

    int ans = INT_MAX;
    int prev1 = nums1[idx-1];
    int prev2 = nums2[idx-1];

    if(swapped) swap(prev1, prev2);

    //swap
    if(nums1[idx] > prev2 && nums2[idx] > prev1) 
        ans = 1 + topDown(nums1, nums2, idx+1, 1, dp);
    //no swap
    if(nums1[idx] > prev1 && nums2[idx] > prev2) 
        ans = min(ans, topDown(nums1, nums2, idx+1, 0, dp)); 

    dp[idx][swapped] = ans;
    return dp[idx][swapped];
}


int tabulation(vector<int>& nums1, vector<int>& nums2) {
    //dp array and base case analysis
    vector<vector<int>> dp(nums1.size()+1, vector<int>(2, 0)); //to handle out of bound idx

    for(int idx = nums1.size()-1; idx >= 1; idx--) {
        for(int swapped = 1; swapped >= 0; swapped--) {
            int ans = INT_MAX;
            int prev1 = nums1[idx-1];
            int prev2 = nums2[idx-1];

            if(swapped) swap(prev1, prev2);

            //swap
            if(nums1[idx] > prev2 && nums2[idx] > prev1) 
                ans = 1 + dp[idx+1][1];
            //no swap
            if(nums1[idx] > prev1 && nums2[idx] > prev2) 
                ans = min(ans, dp[idx+1][0]); 

            dp[idx][swapped] = ans;
        }
    }
    return dp[1][0];
}


int spaceOpt(vector<int>& nums1, vector<int>& nums2) {
    //base case
    int currSwap, currNoSwap;
    int nextSwap = 0, nextNoSwap = 0; //seeing tabulation base case

    for(int idx = nums1.size()-1; idx >= 1; idx--) {
        for(int swapped = 1; swapped >= 0; swapped--) {
            int ans = INT_MAX;
            int prev1 = nums1[idx-1];
            int prev2 = nums2[idx-1];

            if(swapped) swap(prev1, prev2);

            //swap
            if(nums1[idx] > prev2 && nums2[idx] > prev1) 
                ans = 1 + nextSwap; //-> swap referes to swap box of next dp idx
            //no swap
            if(nums1[idx] > prev1 && nums2[idx] > prev2) 
                ans = min(ans, nextNoSwap); //-> noSwap referes to not swapped box of next dp idx

            if(swapped) currSwap = ans;
            else currNoSwap = ans;
        }
        nextSwap = currSwap;
        nextNoSwap = currNoSwap;
    }
    return nextNoSwap; //dp[1][0] -> no swap of first idx
}   


int minSwap(vector<int>& nums1, vector<int>& nums2) {
    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);
    // int n = nums1.size();
    // vector<vector<int>> dp(n, vector<int>(2, -1));
    // return topDown(nums1, nums2, 1, 0, dp);

    //return tabulation(nums1, nums2);
    
    return spaceOpt(nums1, nums2);
}

int main() {
    vector<int> nums1 = {0, 4, 4, 5, 9};
    vector<int> nums2 = {0, 1, 6, 8, 10};
    cout << minSwap(nums1, nums2);
    return 0;
}