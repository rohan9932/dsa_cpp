#include<bits/stdc++.h>
using namespace std;

int topDown(string str1, string str2, int str1Idx, int str2Idx, vector<vector<int>>& dp) {
    //base case
    if(str1Idx >= str1.size() || str2Idx >= str2.size()) return 0;

    if(dp[str1Idx][str2Idx] != -1) return dp[str1Idx][str2Idx];

    int ans = 0;
    if(str1[str1Idx] == str2[str2Idx]) { //char matched
        ans = 1 + topDown(str1, str2, str1Idx+1, str2Idx+1, dp);
    } else {
        ans = max(topDown(str1, str2, str1Idx+1, str2Idx, dp), topDown(str1, str2, str1Idx, str2Idx+1, dp));
    }

    return dp[str1Idx][str2Idx] = ans;
}

int tabulation(string str1, string str2) {
    //base case analysis
    vector<vector<int>> dp(str1.size()+1, vector<int>(str2.size()+1, 0));

    for(int str1Idx = str1.size()-1; str1Idx >= 0; str1Idx--) {
        for(int str2Idx = str2.size()-1; str2Idx >= 0; str2Idx--) {
            int ans = 0;
            if(str1[str1Idx] == str2[str2Idx]) { //char matched
                ans = 1 + dp[str1Idx+1][str2Idx+1];
            } else {
                ans = max(dp[str1Idx+1][str2Idx], dp[str1Idx][str2Idx+1]);
            }

            dp[str1Idx][str2Idx] = ans;
        }
    }

    return dp[0][0];
}

int spaceOpt(string str1, string str2) {
    //base case analysis
    vector<int> currRow(str2.size()+1, 0);
    vector<int> nextRow(str2.size()+1, 0);

    for(int str1Idx = str1.size()-1; str1Idx >= 0; str1Idx--) {
        for(int str2Idx = str2.size()-1; str2Idx >= 0; str2Idx--) {
            int ans = 0;
            if(str1[str1Idx] == str2[str2Idx]) { //char matched
                ans = 1 + nextRow[str2Idx+1];
            } else {
                ans = max(nextRow[str2Idx], currRow[str2Idx+1]);
            }

            currRow[str2Idx] = ans;
        }
        nextRow = currRow;
    }

    return nextRow[0];
}

int longestCommonSubsequence(string text1, string text2) {
    // vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
    // return topDown(text1, text2, 0, 0, dp);

    //return tabulation(text1, text2);

    return spaceOpt(text1, text2);
}


int main() {
    string text1 = "abcde";
    string text2 = "ace";
    cout << longestCommonSubsequence(text1, text2) << endl;
    return 0;
}