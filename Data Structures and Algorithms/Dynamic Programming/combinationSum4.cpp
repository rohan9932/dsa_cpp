#include<bits/stdc++.h>
using namespace std;

int topDown(vector<int>& nums, int target, vector<int>& dp) {
    //base case
    if(target == 0) return 1;
    if(target < 0) return 0;
    if(dp[target] != -1) return dp[target];

    dp[target] = 0;
    for(int i = 0; i < nums.size(); i++) {
        dp[target] += topDown(nums, target-nums[i], dp);
    }
    return dp[target];
}

//using unsigned int for handling int overflow in leetcode
int tabulation(vector<int>& nums, int target, vector<unsigned int>& dp) {
    dp[0] = 1;

    for(int i = 1; i <= target; i++) {
        for(int j = 0; j < nums.size(); j++) {
            if(i-nums[j] >= 0) {
                dp[i] += dp[i-nums[j]];
            }
        }
    }

    return dp[target];
}

int combinationSum4(vector<int>& nums, int target) {
    vector<unsigned int> dp(target+1, 0);
    return tabulation(nums, target, dp);
}

int main() {
    vector<int> nums = {1, 2, 5};
    int target = 4;

    cout << combinationSum4(nums, target) << endl;
    
    return 0;
}