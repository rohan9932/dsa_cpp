#include<bits/stdc++.h>
using namespace std;

int topDown(vector<int>& satisfaction, int idx, int time, vector<vector<int>>& dp) {
    //base case
    if(idx == satisfaction.size()) return 0;

    if(dp[idx][time] != -1) return dp[idx][time];

    int include = satisfaction[idx]*time + topDown(satisfaction, idx+1, time+1, dp);
    int exclude = topDown(satisfaction, idx+1, time, dp);

    dp[idx][time] = max(include, exclude);
    return dp[idx][time];
}

int tabulation(vector<int>& satisfaction, vector<vector<int>>& dp) {
    int n = satisfaction.size();
    //base case analysis

    for(int idx = n-1; idx >= 0; idx--) {
        for(int time = n; time >= 1; time--) {
            int include = satisfaction[idx]*time + dp[idx+1][time+1];
            int exclude = dp[idx+1][time];

            dp[idx][time] = max(include, exclude);
        }
    }

    return dp[0][1];
}


int spaceOpt(vector<int>& satisfaction) {
    int n = satisfaction.size();
    vector<int> curr(n+1, 0);
    vector<int> next(n+1, 0);

    for(int idx = n-1; idx >= 0; idx--) {
        for(int time = n; time >= 1; time--) {
            int include = satisfaction[idx]*time + next[time+1];
            int exclude = next[time];

            curr[time] = max(include, exclude);
        }
        next = curr;
    }

    return next[1];
}

int maxSatisfaction(vector<int>& satisfaction) {
    int n = satisfaction.size();
    vector<vector<int>> dp(n+1, vector<int>(n+2, 0));
    sort(satisfaction.begin(), satisfaction.end()); //sort first
    //return topDown(satisfaction, 0, 1, dp); 
    return tabulation(satisfaction, dp);
}

int main() {
    vector<int> satisfaction = {-1, -8, 0, 5, -9};
    cout << maxSatisfaction(satisfaction) << endl;
    return 0;
}