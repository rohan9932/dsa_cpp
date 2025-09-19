#include<bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int topDown(int dice, int faces, int target, vector<vector<int>>& dp) {
    //base case
    if(target < 0) return 0;
    if(dice != 0 && target == 0) return 0;
    if(target != 0 && dice == 0) return 0;
    if(target == 0 && dice == 0) return 1; //1 way just do nothing

    if(dp[dice][target] != -1) return dp[dice][target];

    int ans = 0;
    for(int i = 1; i <= faces; i++) {
        ans = (ans + topDown(dice-1, faces, target-i, dp))%MOD;
    }

    dp[dice][target] = ans;

    return dp[dice][target];
}

int tabulation(int dice, int faces, int target, vector<vector<int>>& dp) {
    //base case analysis
    //as all the values are initialized to 0 so we need to handle only one case
    dp[0][0] = 1;

    for(int dc = 1; dc <= dice; dc++) {
        for(int tar = 1; tar <= target; tar++) {
            int ans = 0;
            for(int i = 1; i <= faces; i++) {
                if(tar-i >= 0) { //handling negative idx
                    ans = (ans + dp[dc-1][tar-i])%MOD;
                }
            }

            dp[dc][tar] = ans;
        }
    }

    return dp[dice][target];
}

int spaceOpt(int dice, int faces, int target) {
    //base case analysis
    //as all the values are initialized to 0 so we need to handle only one case
    vector<int> prev(target+1, 0);
    vector<int> curr(target+1, 0);
    prev[0] = 1;

    for(int dc = 1; dc <= dice; dc++) {
        for(int tar = 1; tar <= target; tar++) {
            int ans = 0;
            for(int i = 1; i <= faces; i++) {
                if(tar-i >= 0) {
                    ans = (ans + prev[tar-i])%MOD;
                }
            }
            curr[tar] = ans;
        }
        prev = curr;
    }

    return prev[target];
}

int numRollsToTarget(int n, int k, int target) {
    vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
    return topDown(n, k, target, dp);
}


int main() {
    cout << numRollsToTarget(3, 2, 6) << endl;
    cout << numRollsToTarget(30, 30, 500) << endl;
    return 0;
}