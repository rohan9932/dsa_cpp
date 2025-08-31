#define MOD 1000000007
#include<bits/stdc++.h>
using namespace std;


long long int topDown(int n, vector<long long int>&dp) {
    //Base case
    if(n == 1) return 0;
    if(n == 2) return 1;

    if(dp[n] != -1) return dp[n];

    dp[n] = (n-1)*(topDown(n-1, dp) + topDown(n-2, dp))%MOD;
    return dp[n];
}

long long int tabulation(int n, vector<long long int>&dp) {
    dp[1] = 0;
    dp[2] = 1;

    for(int i = 3; i <= n; i++) {
        dp[i] = (i-1)*(dp[i-1] + dp[i-2])%MOD;
    }

    return dp[n];
}

long long int spaceOpt(int n) {
    long long int prev2 = 0;
    long long int prev1 = 1;
    for(int i = 3; i <= n; i++) {
        long long int curr = (i-1)*(prev1 + prev2)%MOD;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

long long int countDerangements(int n) {
    // Write your code here.  
    vector<long long int> dp(n+1, -1);
    long long int ans = spaceOpt(n);
    return ans;
}


int main() {
    cout << countDerangements(3) << endl;
    return 0;
}