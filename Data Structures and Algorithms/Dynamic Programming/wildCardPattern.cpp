#include<bits/stdc++.h>
using namespace std;

bool topDown(string& s, string& p, int i, int j, vector<vector<int>>& dp) {
    //base case handle
    if(i < 0 && j < 0) return true;
    if(i >= 0 && j < 0) return false; 
    if(i < 0 && j >= 0) {
        for(int k = 0; k <= j; k++) {
            if(p[k] != '*') return false;
        }
        return true;
    }

    if(dp[i][j] != -1) return dp[i][j];

    bool ans;
    if(s[i] == p[j] || p[j] == '?') {
        ans = topDown(s, p, i-1, j-1, dp);
    } else if(p[j] == '*') {
        ans = topDown(s, p, i, j-1, dp) || topDown(s, p, i-1, j, dp); //emptyStr || strArr replace
    } else { //character haven't matched
        return false;
    }

    return dp[i][j] = ans;
}

bool tabulation(string& s, string& p) {
    //base case handle
    vector<vector<int>> dp(s.length()+1, vector<int>(p.length()+1, 0));
    //as in base case we had < 0 in topDown so we need to shift that solution 
    //to 1 based idxing to solve in tabulation

    dp[0][0] = true;//1.
    //2. not needed as dp is initialized with 0
    //3.
    for(int j = 1; j <= p.length(); j++) {
        bool flag = true;
        for(int k = 1; k <= j; k++) {
            if(p[k-1] != '*') { //as p is 0 idx based
                flag = false;
                break;
            }
        }
        dp[0][j] = flag;
    }

    for(int i = 1; i <= s.length(); i++) {
        for(int j = 1; j <= p.length(); j++) {
            bool ans;
            if(s[i-1] == p[j-1] || p[j-1] == '?') { //as i converted to 1 based idxing
                ans = dp[i-1][j-1];
            } else if(p[j-1] == '*') {
                ans = dp[i][j-1] || dp[i-1][j]; //emptyStr || strArr replace
            } else { //character haven't matched
                ans = false;
            }
            dp[i][j] = ans;
        }
    }

    return dp[s.length()][p.length()];
}

bool spaceOpt(string& s, string& p) {
    //base case handle
    //as in base case we had < 0 in topDown so we need to shift that solution 
    //to 1 based idxing to solve in tabulation
    vector<int> prev(p.length()+1, 0);
    vector<int> curr(p.length()+1, 0);

    prev[0] = true;//1. (initially prev is dp[0])
    //2. not needed as dp is initialized with 0
    //3.
    for(int j = 1; j <= p.length(); j++) {
        bool flag = true;
        for(int k = 1; k <= j; k++) {
            if(p[k-1] != '*') { //as p is 0 idx based
                flag = false;
                break;
            }
        }
        prev[j] = flag; //as initially prev is dp[0]
    }

    for(int i = 1; i <= s.length(); i++) {
        for(int j = 1; j <= p.length(); j++) {
            bool ans;
            if(s[i-1] == p[j-1] || p[j-1] == '?') { //as i converted to 1 based idxing
                ans = prev[j-1];
            } else if(p[j-1] == '*') {
                ans = curr[j-1] || prev[j]; //emptyStr || strArr replace
            } else { //character haven't matched
                ans = false;
            }
            curr[j] = ans;
        }
        prev = curr;
    }

    return prev[p.length()];
}

bool isMatch(string s, string p) {
    // vector<vector<int>> dp(s.length(), vector<int>(p.length(), -1));
    // return topDown(s, p, s.length()-1, p.length()-1, dp);

    //return tabulation(s, p);

    return spaceOpt(s, p);
}

int main() {
    string s = "cb", p = "?b";
    cout << isMatch(s, p) << endl;
    return 0;
}