#include<bits/stdc++.h>
using namespace std;

/*
    Top Down Dp
*/

int helper(int n, vector<int>& dp) {
    if(n <= 1) return 1;
    else if(dp[n] != -1) return dp[n]; //restore from cache memory
    dp[n] = helper(n-1, dp) + helper(n-2, dp);
    return dp[n];
}

int climbStairs(int n) {
    vector<int> dp(n+1, -1); //memoization
    return helper(n, dp);
}

/*
    Bottom Up Dp
*/
int climbStairsBtmUp(int n) {
    vector<int> dp(n+1, -1);
    //base case
    dp[0] = 1, dp[1] = 1;
    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2]; //tabulation
    }
    return dp[n];
}


/*
    space optimization
*/




int main() {
    cout << climbStairs(45) << endl;
    return 0;
}