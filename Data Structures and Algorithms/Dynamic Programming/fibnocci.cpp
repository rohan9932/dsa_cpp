#include<bits/stdc++.h>
using namespace std;

/*
    A classical example of top down DP
*/

int helper(int n, vector<int>& dp) {
    if(n <= 1) return n;
    //step 3. check in cache memory
    else if(dp[n] != -1) return dp[n];
    //step 2. store in cache memory
    dp[n] = helper(n-1, dp) + helper(n-2, dp);
    return dp[n];
}
int fib(int n) {
    //step 1. make cache memory
    vector<int> dp(n+1, -1);
    return helper(n, dp);
}


/*
    A classical example of bottom up DP
*/

int fibBottomDown(int n) {
    //step 1. make cache memory
    vector<int> dp(n+1, -1);
    
    //step 2. store base cases
    dp[0] = 0, dp[1] = 1;

    //step 3. make a bottom up approach to store till n
    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main() {
    cout << fib(7) << endl;
    cout << fibBottomDown(7) << endl;
    return 0;
}