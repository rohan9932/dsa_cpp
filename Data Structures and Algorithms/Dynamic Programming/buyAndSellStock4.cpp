#include<bits/stdc++.h>
using namespace std;

/*
    Here we can do k transactions
*/

int topDown(vector<int>& prices, int idx, int buy, int limit, vector<vector<vector<int>>>& dp) {
    //base case
    if(idx == prices.size() || limit == 0) return 0;

    if(dp[idx][buy][limit] != -1) return dp[idx][buy][limit];

    int profit = 0;
    if(buy) { //buy allowed
        int buyProfit = -prices[idx] + topDown(prices, idx+1, 0, limit, dp); //buy
        int skip = 0 + topDown(prices, idx+1, 1, limit, dp); //skip
        profit = max(buyProfit, skip);
    } else { //buy not allowed
        int sellProfit = prices[idx] + topDown(prices, idx+1, 1, limit-1, dp);
        int skip = 0 + topDown(prices, idx+1, 0, limit, dp);
        profit = max(sellProfit, skip);
    }

    return dp[idx][buy][limit] = profit;
}

int tabulation(vector<int>& prices, int k) {
    //base case analysis
    vector<vector<vector<int>>> dp(prices.size()+1, vector<vector<int>>(2, vector<int>(k+1, 0)));

    for(int idx = prices.size()-1; idx >= 0; idx--) {
        for(int buy = 0; buy < 2; buy++) {
            for(int limit = 1; limit <= k; limit++){
                int profit = 0;
                if(buy) { //buy allowed
                    int buyProfit = -prices[idx] + dp[idx+1][0][limit]; //buy
                    int skip = 0 + dp[idx+1][1][limit]; //skip
                    profit = max(buyProfit, skip);
                } else { //buy not allowed
                    int sellProfit = prices[idx] + dp[idx+1][1][limit-1];
                    int skip = 0 + dp[idx+1][0][limit];
                    profit = max(sellProfit, skip);
                }

                dp[idx][buy][limit] = profit;
            }
        }
    }

    return dp[0][1][k];
}

int spaceOpt(vector<int>& prices, int k) {
    //base case analysis
    vector<vector<int>> curr(2, vector<int>(k+1, 0));
    vector<vector<int>> next(2, vector<int>(k+1, 0));

    for(int idx = prices.size()-1; idx >= 0; idx--) {
        for(int buy = 0; buy < 2; buy++) {
            for(int limit = 1; limit <= k; limit++){
                int profit = 0;
                if(buy) { //buy allowed
                    int buyProfit = -prices[idx] + next[0][limit]; //buy
                    int skip = 0 + next[1][limit]; //skip
                    profit = max(buyProfit, skip);
                } else { //buy not allowed
                    int sellProfit = prices[idx] + next[1][limit-1];
                    int skip = 0 + next[0][limit];
                    profit = max(sellProfit, skip);
                }

                curr[buy][limit] = profit;
            }
        }
        next = curr;
    }

    return next[1][k];
}

int maxProfit(int k, vector<int>& prices) {
    // vector<vector<vector<int>>> dp(prices.size()+1, vector<vector<int>>(2, vector<int>(k+1, -1)));
    // return topDown(prices, 0, 1, k, dp);

    //return tabulation(prices, k);

    return spaceOpt(prices, k);
}


int main() {
    int k = 2;
    vector<int> prices = {2, 4, 1};
    cout << maxProfit(k, prices) << endl;
    return 0;
}