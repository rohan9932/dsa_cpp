#include<bits/stdc++.h>
using namespace std;

int topDown(vector<int>& values, int i, int j, vector<vector<int>>& dp) {
    //base case
    if(i+1 == j) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    int ans = INT_MAX;
    for(int k = i+1; k < j; k++) {
        ans = min(ans, (values[i]*values[j]*values[k]) + topDown(values, i, k, dp) + topDown(values, k, j, dp));
    }

    dp[i][j] = ans;

    return dp[i][j];
}

int tabulation(vector<int>& values, vector<vector<int>>& dp) {
    int n = values.size();
    for(int i = n-1; i >= 0; i--) {
        for(int j = i+2; j < n; j++) { //base case handled from topDown
            int ans = INT_MAX;
            for(int k = i+1; k < j; k++) {
                ans = min(ans, (values[i]*values[j]*values[k]) + dp[i][k] + dp[k][j]);
            }

            dp[i][j] = ans;
        }
    }
    return dp[0][n-1];
}

int minScoreTriangulation(vector<int>& values) {
    int n = values.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    return tabulation(values, dp);
}

int main() {
    vector<int> values = {3, 7, 4, 5};
    cout << minScoreTriangulation(values) << endl;
    return 0;
}