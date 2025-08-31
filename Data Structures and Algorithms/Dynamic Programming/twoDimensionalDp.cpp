#include<bits/stdc++.h>
using namespace std;

int topDown(int capacity, int idx, vector<int> &val, vector<int> &wt, vector<vector<int>>& dp) {
    //base case
    //if only one item left, just compare it to the knapsack capacity
    if(idx == 0) {
        if(wt[0] <= capacity) return val[0];
        else return 0;
    }
    //check cache
    if(dp[idx][capacity] != -1) return dp[idx][capacity];
    
    //including item
    int include = 0;
    if(wt[idx] <= capacity) {
        include = val[idx] + topDown(capacity-wt[idx], idx-1, val, wt, dp);
    }
    
    int exclude = 0 + topDown(capacity, idx-1, val, wt, dp);
    
    //caching
    dp[idx][capacity] = max(include, exclude);
    
    return dp[idx][capacity];
}

int tabulation(int capacity, int idx, vector<int> &val, vector<int> &wt, vector<vector<int>>& dp) {
    //base case analyze
    for(int w = 0; w <= capacity; w++) {
        if(wt[0] <= w) dp[0][w] = val[0];
        else dp[0][w] = 0;
    }
    
    for(int i = 1; i <= idx; i++) {
        for(int w = 0; w <= capacity; w++) {
            //including item
            int include = 0;
            if(wt[i] <= w) {
                include = val[i] + dp[i-1][w-wt[i]];
            }
            
            int exclude = 0 + dp[i-1][w];
    
            //caching 
            dp[i][w] = max(include, exclude);
        }
    }
    
    return dp[idx][capacity];
}

int spaceOpt(int capacity, int idx, vector<int> &val, vector<int> &wt) {
    vector<int> prev(capacity+1, 0);
    vector<int> curr(capacity+1, 0);
    //base case analyze
    for(int w = 0; w <= capacity; w++) {
        if(wt[0] <= w) prev[w] = val[0];
        else prev[w] = 0;
    }
    
    for(int i = 1; i <= idx; i++) {
        for(int w = 0; w <= capacity; w++) {
            //including item
            int include = 0;
            if(wt[i] <= w) {
                include = val[i] + prev[w-wt[i]];
            }
            
            int exclude = 0 + prev[w];
    
            //caching 
            curr[w] = max(include, exclude);
        }
        prev = curr; //shift the row
    }
    
    return prev[capacity];
}

int moreSpaceOpt(int capacity, int idx, vector<int> &val, vector<int> &wt) {
    vector<int> curr(capacity+1, 0);
    //base case analyze
    for(int w = 0; w <= capacity; w++) {
        if(wt[0] <= w) curr[w] = val[0];
        else curr[w] = 0;
    }
    
    for(int i = 1; i <= idx; i++) {   
        for(int w = capacity; w >= 0; w--) {
            //including item
            int include = 0;
            if(wt[i] <= w) {
                include = val[i] + curr[w-wt[i]];
            }
            
            int exclude = 0 + curr[w];
    
            //caching 
            curr[w] = max(include, exclude);
        }
    }
    
    return curr[capacity];
}

int knapsack(int W, vector<int> &val, vector<int> &wt) {
    // code here
    int n = wt.size();
    // vector<vector<int>> dp(n, vector<int>(W+1, -1));
    // return topDown(W, n-1, val, wt, dp);
    
    vector<vector<int>> dp(n, vector<int>(W+1, 0));
    return moreSpaceOpt(W, n-1, val, wt);
}

int main() {
    vector<int> wt = {4, 5, 1};
    vector<int> val = {1, 2, 3};
    cout << knapsack(4, val, wt) << endl;
    return 0;
}