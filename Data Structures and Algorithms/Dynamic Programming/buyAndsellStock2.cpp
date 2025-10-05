#include<bits/stdc++.h>
using namespace std;

/*
    Here multiple buy and sell are allowed so we need to return the max profit
*/

int topDown(vector<int>& prices, int idx, int buy, vector<vector<int>>& dp) {
    //base case
    if(idx == prices.size()) return 0;

    if(dp[idx][buy] != -1) return dp[idx][buy];

    int profit = 0;
    if(buy) { //buy allowed
        int buyProfit = -prices[idx] + topDown(prices, idx+1, 0, dp); //buy
        int skip = 0 + topDown(prices, idx+1, 1, dp); //skip
        profit = max(buyProfit, skip);
    } else { //buy not allowed
        int sellProfit = prices[idx] + topDown(prices, idx+1, 1, dp);
        int skip = 0 + topDown(prices, idx+1, 0, dp);
        profit = max(sellProfit, skip);
    }

    return dp[idx][buy] = profit;
}

int tabulation(vector<int>& prices) {
    //base case analysis
    vector<vector<int>> dp(prices.size()+1, vector<int>(2, 0));

    for(int idx = prices.size()-1; idx >= 0; idx--) {
        for(int buy = 0; buy < 2; buy++) {
            int profit = 0;
            if(buy) { //buy allowed
                int buyProfit = -prices[idx] + dp[idx+1][0]; //buy
                int skip = 0 + dp[idx+1][1]; //skip
                profit = max(buyProfit, skip);
            } else { //buy not allowed
                int sellProfit = prices[idx] + dp[idx+1][1];
                int skip = 0 + dp[idx+1][0];
                profit = max(sellProfit, skip);
            }

            dp[idx][buy] = profit;
        }
    }

    return dp[0][1];
}

int spaceOpt(vector<int>& prices) {
    //base case analysis
    vector<int> curr(2, 0);
    vector<int> next(2, 0);

    for(int idx = prices.size()-1; idx >= 0; idx--) {
        for(int buy = 0; buy < 2; buy++) {
            int profit = 0;
            if(buy) { //buy allowed
                int buyProfit = -prices[idx] + next[0]; //buy
                int skip = 0 + next[1]; //skip
                profit = max(buyProfit, skip);
            } else { //buy not allowed
                int sellProfit = prices[idx] + next[1];
                int skip = 0 + next[0];
                profit = max(sellProfit, skip);
            }

            curr[buy] = profit;
        }
        next = curr;
    }

    return next[1];
}

int maxProfit(vector<int>& prices) {
    // vector<vector<int>> dp(prices.size()+1, vector<int>(2, -1));
    // return topDown(prices, 0, 1, dp);

    //return tabulation(prices);

    return spaceOpt(prices);
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices) << endl;
    return 0;
}