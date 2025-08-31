#include<bits/stdc++.h>
using namespace std;

int topDown(int n, int k, vector<int>& dp) {
    //base case
    if(n == 1) return k;
    if(n == 2) return k*k;
    
    //check cache
    if(dp[n] != -1) return dp[n];
    
    dp[n] = (topDown(n-1, k, dp) + topDown(n-2, k, dp))*(k-1);
    
    return dp[n];
}

int tabulation(int n, int k, vector<int>& dp) {
    dp[1] = k;
    dp[2] = k*k;
    
    for(int i = 3; i <= n; i++) {
        dp[i] = (dp[i-1] + dp[i-2])*(k-1);
    }
    
    return dp[n];
}

int spaceOpt(int n, int k) {
    if(n == 1) return k;
    if(n == 2) return k*k;
    
    int prev2 = k;
    int prev1 = k*k;
    
    for(int i = 3; i <= n; i++) {
        int curr = (prev2 + prev1)*(k-1);
        prev2 = prev1;
        prev1 = curr;
    }
    
    return prev1;
}

int countWays(int n, int k) {
    // code here
    vector<int> dp(n+1, -1);
    return spaceOpt(n, k);
}

int main() {
    cout << countWays(3,3) << endl;
    return 0;
}