#include<bits/stdc++.h>
using namespace std;

int topDown(vector<vector<char>>& matrix, int i, int j, int& maximumSq, vector<vector<int>>& dp) {
    //Base case
    if(i >= matrix.size() || j >= matrix[0].size()) return 0; //idx out of bound
    //check mem
    if(dp[i][j] != -1) return dp[i][j];

    int right = topDown(matrix, i, j+1, maximumSq, dp);
    int down = topDown(matrix, i+1, j, maximumSq, dp);
    int diagonal = topDown(matrix, i+1, j+1, maximumSq, dp);

    if(matrix[i][j] == '1') {
        dp[i][j] = 1 + min(right, min(diagonal, down));
        maximumSq = max(dp[i][j], maximumSq);
    }
    else {
        dp[i][j] = 0;
    }

    return dp[i][j];
}

int tabulation(vector<vector<char>>& matrix, int& maximumSq, vector<vector<int>>& dp) {
    for(int i = matrix.size()-1; i >= 0; i--) {
        for(int j = matrix[0].size()-1; j >= 0; j--) {
            int right = dp[i][j+1];
            int down = dp[i+1][j];
            int diagonal = dp[i+1][j+1];

            if(matrix[i][j] == '1') {
                dp[i][j] = 1 + min(right, min(diagonal, down));
                maximumSq = max(dp[i][j], maximumSq);
            }
            else {
                dp[i][j] = 0;
            }
        }
    }
    return maximumSq;
}

int spaceOpt(vector<vector<char>>& matrix, int& maximumSq) {
    int n = matrix[0].size();
    vector<int> curr(n+1, 0);
    vector<int> next(n+1, 0);
    
    for(int i = matrix.size()-1; i >= 0; i--) {
        for(int j = matrix[0].size()-1; j >= 0; j--) {
            int right = curr[j+1];
            int down = next[j];
            int diagonal = next[j+1];

            if(matrix[i][j] == '1') {
                curr[j] = 1 + min(right, min(diagonal, down));
                maximumSq = max(curr[j], maximumSq);
            }
            else {
                curr[j] = 0;
            }
        }
        next = curr;
    }
    return maximumSq;
}

int maximalSquare(vector<vector<char>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    int maximumSq = 0;
    topDown(matrix, 0, 0, maximumSq, dp);
    return maximumSq*maximumSq;
}

int main() {
    return 0;
}