#include<bits/stdc++.h>
using namespace std;

/*
    Top Down DP
*/

int helper(vector<int>& coins, int amount, vector<int>& dp) {
    //base case
    if(amount == 0) return 0;
    if(amount < 0) return INT_MAX;

    //check in cache
    if(dp[amount] != -1) return dp[amount];

    int mini = INT_MAX;

    for(int i = 0; i < coins.size(); i++) {
        int ans = helper(coins, amount-coins[i], dp);
        if(ans != INT_MAX) {
            mini = min(mini, 1+ans);
        }
    } 
    //momoization
    dp[amount] = mini;

    return dp[amount];
}

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount+1, -1);
    int ans = helper(coins, amount, dp);
    return (ans != INT_MAX) ? ans: -1;
}


/*
    Bottom Up DP
*/

int helperTab(vector<int>& coins, int amount, vector<int>& dp) {
    //base case analyze 
    dp[0] = 0;

    for(int i = 1; i <= amount; i++) {
        //choice for each coin
        for(int j = 0; j < coins.size(); j++) {
            if(i-coins[j] >= 0 && dp[i-coins[j]] != INT_MAX) {
                dp[i] = min(dp[i], 1 + dp[i-coins[j]]);
            }
        }
    }

    return dp[amount];
}

int coinChangeTab(vector<int>& coins, int amount) {
    vector<int> dp(amount+1, INT_MAX);
    int ans = helper(coins, amount, dp);
    return (ans != INT_MAX) ? ans: -1;
}



int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout << coinChange(coins, amount) << endl;
    return 0;
}