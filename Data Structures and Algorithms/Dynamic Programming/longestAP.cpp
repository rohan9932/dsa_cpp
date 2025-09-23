#include<bits/stdc++.h>
using namespace std;

int helper(vector<int>& nums, int idx, int diff) {
    if(idx < 0) return 0;

    int ans = 0;
    for(int j = idx-1; j >= 0; j--) {
        if(nums[idx] - nums[j] == diff) {
            //recursive call 
            ans = max(ans, 1 + helper(nums, j, diff));
        }
    }

    return ans;
}

int helperTopDown(vector<int>& nums, int idx, int diff, vector<unordered_map<int,int>>& dp) {
    if(idx < 0) return 0;
    
    if(dp[idx].count(diff)) return dp[idx][diff];

    int ans = 0;
    for(int j = idx-1; j >= 0; j--) {
        if(nums[idx] - nums[j] == diff) {
            //recursive call 
            ans = max(ans, 1 + helperTopDown(nums, j, diff, dp));
        }
    }

    return dp[idx][diff] = ans;
}

int longestAP(vector<int>& nums) {
    int n = nums.size();
    if(n <= 2) return n;

    vector<unordered_map<int,int>> dp(n+1);

    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            ans = max(ans, 2 + helperTopDown(nums, i, nums[j]-nums[i], dp)); //as length 2 are already present in AP
        }
    }

    return ans;
}

int longestAPTabulation(vector<int>& nums) {
    int ans = 0;
    int n = nums.size();

    if(n <= 2) return n;

    vector<unordered_map<int, int>> dp(n+1);

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            int diff = nums[i] - nums[j];
            int cnt = 1; //as current ith idx will always include
            
            //check if ans already present for jth idx(check if j can be included)
            if(dp[j].count(diff)) cnt = dp[j][diff]; //max AP for jth idx with diff

            dp[i][diff] = 1 + cnt; //as in the len ith idx count will also be included so count+1
            ans = max(ans, dp[i][diff]);
        }
    }

    return ans;
}

int longestArithSeqLength(vector<int>& nums) {
    return longestAPTabulation(nums);
}

int main() {
    vector<int> arr = {3, 6, 9, 12};
    cout << longestArithSeqLength(arr) << endl;
    return 0;
}