#include<bits/stdc++.h>
using namespace std;

int topDown(int st, int end, vector<vector<int>>& dp) {
    //base case
    if(st >= end) return 0;

    if(dp[st][end] != -1) return dp[st][end];

    //the most important section of the question
    int minimum = INT_MAX;
    for(int i = st; i <= end; i++) {
        minimum = min(minimum, i + max(topDown(st, i-1, dp), topDown(i+1, end, dp)));
    }

    return dp[st][end] = minimum;
}

int tabulation(int n) {
    //base case analysis
    vector<vector<int>> dp(n+2, vector<int>(n+2, 0)); //already handled

    for(int st = n; st >= 1; st--) {
        for(int end = st; end <= n; end++) {
            if(st == end) continue;
            else {
                int minimum = INT_MAX;
                for(int i = st; i <= end; i++) {
                    minimum = min(minimum, i + max(dp[st][i-1], dp[i+1][end]));
                }
                dp[st][end] = minimum;
            }
        }
    }

    return dp[1][n];
}


int getMoneyAmount(int n) {
    // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    // return topDown(1, n, dp);

    return tabulation(n);
}

int main() {
    cout << getMoneyAmount(7) << endl;
    cout << getMoneyAmount(10) << endl;

    return 0;
}