#include<bits/stdc++.h>
using namespace std;

/*
    Top Down Dp
*/
int helper(int n, vector<int>& cost, vector<int>& dp) {
    if(n <= 1) return cost[n];
    else if(dp[n] != -1) return dp[n];
    //cost[n] includes as i need to pay while move upwards so need to add it
    dp[n] = min(helper(n-1, cost, dp), helper(n-2, cost, dp)) + cost[n];
    return dp[n];
}

int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    vector<int> dp(n+1, -1);
    dp[n] = min(helper(n-1, cost, dp), helper(n-2, cost, dp));
    return dp[n];
}

/*
    Bottom Up Dp
*/
int minCostClimbingStairsTabulation(vector<int>& cost) {
    int n = cost.size();
    vector<int> dp(n+1, -1);
    //base case
    dp[0] = cost[0], dp[1] = cost[1];

    //tabulation
    for(int i = 2; i <= n-1; i++) {
        dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
    }

    dp[n] = min(dp[n-1], dp[n-2]);
    return dp[n];
}


/*
    Space Optimization
*/
int minCostClimbingStairsSpaceOpt(vector<int>& cost) {
    int n = cost.size();
    //storing them in a variable and updating it to optimize space
    //as by following pattern we can see that the current state is 
    //just dependant on the min of prev1 and prev2 + cost[curr] till n-1 the step

    int prev2= cost[0], prev1 = cost[1];

    for(int i = 2; i <= n-1; i++) {
        int curr = min(prev1, prev2) + cost[i];
        prev2 = prev1;
        prev1 = curr;
    }

    return min(prev1, prev2);
}



int main() {
    vector<int> cost = {1,100,1,1,1,100,1,1,100,1};
    cout << minCostClimbingStairs(cost) << endl;
    return 0;
}