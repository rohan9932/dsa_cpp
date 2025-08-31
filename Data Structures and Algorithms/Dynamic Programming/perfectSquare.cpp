#include<bits/stdc++.h>
using namespace std;

int topDown(int n, vector<int>& dp) {
    //base case
    if(n <= 0) return 0;
    if(dp[n] != -1) return dp[n];

    dp[n] = n;
    for(int i = 1; i*i <= n; i++) {
        dp[n] = min(dp[n], topDown(n-(i*i), dp) + 1);
    }

    return dp[n];
}

int tabulation(int n, vector<int>& dp) {
    dp[0] = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j*j <= i; j++) {
            if((i-(j*j)) >= 0) {
                dp[i] = min(dp[i], dp[i-(j*j)] + 1);
            }
        }
    }

    return dp[n];
}

int numSquares(int n) {
    vector<int> dp(n+1, n);
    return tabulation(n, dp);
}

int main() {
    cout << numSquares(100) << endl;
    return 0;
}