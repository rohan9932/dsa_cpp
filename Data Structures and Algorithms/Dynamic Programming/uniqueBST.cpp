#include<bits/stdc++.h>
using namespace std;

int topDown(int n, vector<int>& dp) {
    if(n <= 1) return 1;
    if(dp[n] != -1) return dp[n];

    int ans = 0;
    for(int i = 1; i <= n; i++) { //i as root node
        ans += topDown(i-1, dp) * topDown(n-i, dp);
    }
    
    return dp[n] = ans;
}

int tabulation(int n, vector<int>& dp) {
    //base case handle -> done as all the dp values are initialized with 1

    for(int idx = 2; idx <= n; idx++) {
        int ans = 0;
        for(int i = 1; i <= idx; i++) { //i as root node
            ans += dp[i-1] * dp[idx-i];
        }
    
        dp[idx] = ans;
    }

    return dp[n];
}

//maths -> works for small test cases but don't work in recursion as 
//factorials grow very fast in number length
int fact(int n) {
    if(n <= 1) return 1;
    return n*fact(n-1);
}

int mathsCatalanNumber(int n) {
    int ans = fact(2*n)/(fact(n+1)*fact(n));
    return ans;
}

int numTrees(int n) {
    // vector<int> dp(n+1, -1);
    // return topDown(n, dp);

    vector<int> dp(n+1, 1);
    return tabulation(n, dp);
}

int main() {

    return 0;
}