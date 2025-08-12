#include<bits/stdc++.h>
using namespace std;

/*
    Top Down
*/
int topDown(vector<int>& arr, int n, vector<int>& dp) {
    if(n < 0) return 0;
    if(n == 0) return arr[0];
    //cache check
    if(dp[n] != -1) return dp[n];
    
    int include = topDown(arr, n-2, dp) + arr[n];
    int exclude = topDown(arr, n-1, dp);
    
    //memoization
    dp[n] = max(include, exclude);
    
    return dp[n];
}

/*
    Bottom Up
*/
int tabulation(vector<int>& arr, int n, vector<int>& dp) {
    //base case analyze
    dp[0] = arr[0];
    
    for(int i = 1; i < n; i++) {
        int include = arr[i];
        if(i > 1) {
            include += dp[i-2];
        }
        int exclude = dp[i-1];
        dp[i] = max(include, exclude);
    }
    
    return dp[n-1];
}

/*
    Space optimization
*/
int spaceOpt(vector<int>& arr, int n) {
    int prev2 = 0;
    int prev1 = arr[0];
    
    for(int i = 1; i < n; i++) {
        int include = arr[i];
        if(i > 1) {
            include += prev2;
        }
        int exclude = prev1;
        int currMax = max(include, exclude);
        prev2 = prev1;
        prev1 = currMax;
    }
    
    return prev1;
}



// calculate the maximum sum with out adjacent
int findMaxSum(vector<int>& arr) {
    // code here
    int n = arr.size();
    //vector<int> dp(n+1, -1);
    //vector<int> dp(n+1, 0);
    
    int ans = spaceOpt(arr, n);
    
    return ans;
}

int main() {
    vector<int> arr = {9, 9, 8, 2};
    cout << findMaxSum(arr) << endl;
    return 0;
}