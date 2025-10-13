#include<bits/stdc++.h>
using namespace std;

int topDown(vector<int>& arr, int i, int j, vector<vector<int>>& dp) {
    //base case
    if(i == j) return 0;
    
    if(dp[i][j] != -1) return dp[i][j];
    
    int mini = INT_MAX;
    for(int k = i; k < j; k++) {
        int noOfMultiplication = arr[i-1]*arr[k]*arr[j] + topDown(arr, i, k, dp) + topDown(arr, k+1, j, dp);
        mini = min(mini, noOfMultiplication);
    }
    
    return dp[i][j] = mini;
}

int tabulation(vector<int>& arr) {
    int n = arr.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    
    for(int i = n-1; i >= 1; i--) {
        for(int j = i+1; j < n; j++) {
            int mini = INT_MAX;
            for(int k = i; k < j; k++) {
                int noOfMultiplication = arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j];
                mini = min(mini, noOfMultiplication);
            }
            dp[i][j] = mini; 
        }
    }
    
    return dp[1][n-1];
}

int matrixMultiplication(vector<int> &arr) {
    // int n = arr.size();
    // vector<vector<int>> dp(n, vector<int>(n, -1));
    // return topDown(arr, 1, n-1, dp);
    
    return tabulation(arr);
}

int main() {
    vector<int> arr = {10, 20, 30, 40, 50};
    cout << matrixMultiplication(arr) << endl;
    return 0;
}