#include<bits/stdc++.h>
using namespace std;

int topDown(int n, vector<int>& days, vector<int>& costs, int idx, vector<int>& dp) { //O(n)
    //Base case
    if(idx >= n) return 0;
    if(dp[idx] != -1) return dp[idx];

    //1 day
    int op1 = costs[0] + topDown(n, days, costs, idx+1, dp);

    //7 days
    int nextIdx;
    //using this loop to increase the idx according our condition
    for(nextIdx = idx; nextIdx < n && days[nextIdx] < days[idx] + 7; nextIdx++);
    int op2 = costs[1] + topDown(n, days, costs, nextIdx, dp);

    //30 days
    for(nextIdx = idx; nextIdx < n && days[nextIdx] < days[idx] + 30; nextIdx++);
    int op3 = costs[2] + topDown(n, days, costs, nextIdx, dp);

    dp[idx] = min(op1, min(op2, op3));

    return dp[idx];
}

int tabulation(int n, vector<int>& days, vector<int>& costs, vector<int>& dp) { //O(n)
    dp[n] = 0;

    for(int i = n-1; i >= 0; i--) {
        //1 day
        int op1 = costs[0] + dp[i+1];

        //7 days
        int nextIdx;
        //using this loop t o increase the idx according our condition
        for(nextIdx = i; nextIdx < n && days[nextIdx] < days[i] + 7; nextIdx++);
        int op2 = costs[1] + dp[nextIdx];

        //30 days 
        for(nextIdx = i; nextIdx < n && days[nextIdx] < days[i] + 30; nextIdx++);
        int op3 = costs[2] + dp[nextIdx];

        dp[i] = min(op1, min(op2, op3));
    }

    return dp[0];
}

int spaceOpt(int n, vector<int>& days, vector<int>& costs) {
    int ans = 0;
    queue<pair<int, int>> weekly; //pair<day, cost>
    queue<pair<int, int>> monthly;

    for(auto day: days) {
        //Step 1: Remove all the out of time frame entries from queue
        while(!weekly.empty() && weekly.front().first + 7 <= day) weekly.pop();
        while(!monthly.empty() && monthly.front().first + 30 <= day) monthly.pop();

        //Step 2: Enter today's entry
        weekly.push({day, ans + costs[1]});
        monthly.push({day, ans + costs[2]});

        ans = min(ans+costs[0] , min(weekly.front().second, monthly.front().second));
    }
    return ans;
}

int mincostTickets(vector<int>& days, vector<int>& costs) {
    int n = days.size();
    vector<int> dp(n+1, INT_MAX);
    return tabulation(n, days, costs, dp);
}

int main() {
    
    return 0;
}