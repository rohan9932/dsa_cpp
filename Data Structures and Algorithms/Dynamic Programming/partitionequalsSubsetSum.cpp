#include<bits/stdc++.h>
using namespace std;

bool topDown(vector<int>& nums, int idx, int target, vector<vector<int>>& dp) {
    //base case
    if(target == 0) return true;
    if(idx >= nums.size()) return false;
    if(target < 0) return false;

    if(dp[idx][target] != -1) return dp[idx][target];

    bool include = topDown(nums, idx+1, target-nums[idx], dp);
    bool exclude = topDown(nums, idx+1, target, dp);
    dp[idx][target] = include || exclude;

    return dp[idx][target];
}

bool tabulation(vector<int>& nums, int target, vector<vector<int>>& dp) {
    //base case analysis
    for(int i = 0; i < dp.size(); i++) {
        dp[i][0] = 1; //target -> 0 means true for all rows
    }

    for(int idx = nums.size()-2; idx >= 0; idx--) { //as we handled the n-1 case in base case
        for(int tar = 1; tar <= target; tar++) { //as we handled tar == 0 case in base case
            bool include = 0;
            if((tar - nums[idx]) >= 0)
                include = dp[idx+1][tar-nums[idx]];
            bool exclude = dp[idx+1][tar];
            dp[idx][tar] = include || exclude;
        }
    }

    return dp[0][target];
} 

bool spaceOpt(vector<int>& nums, int target) {
    vector<int> currRow(target+1, 0);
    vector<int> nextRow(target+1, 0);
    //base case analysis
    currRow[0] = 1;
    nextRow[0] = 1;

    for(int idx = nums.size()-2; idx >= 0; idx--) { //as we handled the n-1 case in base case
        for(int tar = 1; tar <= target; tar++) { //as we handled tar == 0 case in base case
            bool include = 0;
            if((tar - nums[idx]) >= 0)
                include = nextRow[tar-nums[idx]];
            bool exclude = nextRow[tar];
            currRow[tar] = include || exclude;
        }
        nextRow = currRow;
    }

    return nextRow[target];
} 

bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if(sum % 2 != 0) return false;
    int n = nums.size();
    int target = sum/2;
    // vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
    // return topDown(nums, 0, target, dp);

    //vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
    //return tabulation(nums, target, dp);

    return spaceOpt(nums, target);
}

int main() {
    vector<int> arr1 = {1, 5, 11, 5};
    vector<int> arr2 = {1, 2, 3, 5};
    cout << canPartition(arr1) << endl;
    cout << canPartition(arr2) << endl;
    return 0;
}