#include<bits/stdc++.h>
using namespace std;

int recursive(vector<int>& nums, int n, int currIdx, int prevIdx) {
    if(currIdx == n) return 0;

    //include
    int include = 0;
    //as if the next idx element is not greater than curr element it will automatically be excluded
    if(prevIdx == -1 || nums[currIdx] > nums[prevIdx])
        include = 1 + recursive(nums, n, currIdx+1, currIdx);

    //exclude 
    int exclude = 0 + recursive(nums, n, currIdx+1, prevIdx);

    return max(include, exclude);
}

int topDown(vector<int>& nums, int n, int currIdx, int prevIdx, vector<vector<int>>& dp) {
    if(currIdx == n) return 0;
    if(dp[currIdx][prevIdx+1] != -1) return dp[currIdx][prevIdx+1];

    //include
    int include = 0;
    if(prevIdx == -1 || nums[currIdx] > nums[prevIdx])
        include = 1 + topDown(nums, n, currIdx+1, currIdx, dp);

    //exclude 
    int exclude = 0 + topDown(nums, n, currIdx+1, prevIdx, dp);

    dp[currIdx][prevIdx+1] = max(include, exclude); //to avoid invalid idx

    return dp[currIdx][prevIdx+1];
}

int tabulation(vector<int>& nums, int n, vector<vector<int>>& dp) {
    //base case analysis

    for(int currIdx = n-1; currIdx >= 0; currIdx--) {
        for(int prevIdx = currIdx-1; prevIdx >= -1; prevIdx--) {
            //include
            int include = 0;
            if(prevIdx == -1 || nums[currIdx] > nums[prevIdx])
                include = 1 + dp[currIdx+1][currIdx + 1]; //as we are shifting whole co-ordinate to avoid invalid Idx

            //exclude 
            int exclude = 0 + dp[currIdx+1][prevIdx+1]; //to avoid invalid idx

            dp[currIdx][prevIdx+1] = max(include, exclude); //to avoid invalid idx
        }
    }

    return dp[0][0]; //as we are shifting whole co-ordinate to avoid invalid Idx
}

int spaceOpt(vector<int>& nums, int n) {
    vector<int> curr(n+1, 0);
    vector<int> next(n+1, 0);

    for(int currIdx = n-1; currIdx >= 0; currIdx--) {
        for(int prevIdx = currIdx-1; prevIdx >= -1; prevIdx--) {
            //include
            int include = 0;
            if(prevIdx == -1 || nums[currIdx] > nums[prevIdx])
                include = 1 + next[currIdx + 1]; //as we are shifting whole co-ordinate to avoid invalid Idx

            //exclude 
            int exclude = 0 + next[prevIdx+1]; //to avoid invalid idx

            curr[prevIdx+1] = max(include, exclude); //to avoid invalid idx
        }
        next = curr;
    }

    return next[0];
}

int optimalMostSolve(vector<int>& nums, int n) {
    if(n == 0) return 0;

    vector<int> ans;
    ans.push_back(nums[0]);

    for(int i = 1; i < n; i++) {
        if(nums[i] > ans.back()) {
            ans.push_back(nums[i]);
        } else {
            //find the just greater element's index in ans array
            int idx = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin(); //logn (as the data is sorted)
            ans[idx] = nums[i];
        }
    }

    return ans.size();
}

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    //vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    //return topDown(nums, n, 0, -1, dp);

    // vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    // return tabulation(nums, n, dp);

    //return spaceOpt(nums, n);

    return optimalMostSolve(nums, n);
}

int main() {
    vector<int> nums = {0,1,0,3,2,3};
    cout << lengthOfLIS(nums) << endl;
    return 0;
}