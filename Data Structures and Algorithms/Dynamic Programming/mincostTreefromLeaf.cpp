#include<bits/stdc++.h>
using namespace std;

int topDown(vector<int>& arr, int left, int right, map<pair<int, int>, int>& maximum, vector<vector<int>>& dp) {
    //base case
    if(left == right) return 0; //2 leaf nodes is required to make a tree

    if(dp[left][right] != -1) return dp[left][right];

    int minimum = INT_MAX;
    for(int k = left; k < right; k++) {
        minimum = min(minimum, (maximum[{left, k}]*maximum[{k+1, right}]) + topDown(arr, left, k, maximum, dp) + topDown(arr, k+1, right, maximum, dp));
    }

    return dp[left][right] = minimum;
}

int tabulation(vector<int>& arr, map<pair<int, int>, int>& maximum) {
    int n = arr.size();
    //base case analysis
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    for(int left = n-1; left >= 0; left--) {
        for(int right = left+1; right < n; right++) { // as we need atleast 2 leaf nodes
            int minimum = INT_MAX;
            for(int k = left; k < right; k++) {
                minimum = min(minimum, (maximum[{left, k}]*maximum[{k+1, right}]) + dp[left][k] + dp[k+1][right]);
            }

            dp[left][right] = minimum;
        }
    }

    return dp[0][n-1];
}

int mctFromLeafValues(vector<int>& arr) {
    int n = arr.size();
    //precomputing max for each range and storing in hashmap
    map<pair<int, int>, int> maximum;

    for(int i = 0; i < n; i++) {
        maximum[{i, i}] = arr[i];
        for(int j = i+1; j < n; j++) {
            //stores maxi for each range bound
            maximum[{i, j}] = max(maximum[{i, j-1}], arr[j]);
        }
    }

    //vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    //return topDown(arr, 0, n-1, maximum, dp);

    return tabulation(arr, maximum);
}

int main() {
    vector<int> arr = {6, 2, 4};
    cout << mctFromLeafValues(arr) << endl;
    return 0;
}