#include<bits/stdc++.h>
using namespace std;

//------------------------Top Down------------------------//

int topDown(vector<int>& slices, int idx, int endIdx, int slicesNo, vector<vector<int>>& dp) {
    //base case
    if(slicesNo == 0 || idx > endIdx) return 0;
    if(dp[idx][slicesNo] != -1) return dp[idx][slicesNo];
    
    int include = slices[idx] + topDown(slices, idx+2, endIdx, slicesNo-1, dp);
    int exclude = 0 + topDown(slices, idx+1, endIdx, slicesNo, dp);

    dp[idx][slicesNo] = max(include, exclude);
    return dp[idx][slicesNo];
}

//--------------------Tabulation--------------------//

int tabulationHelper(vector<int>& slices, int k, int stIdx, int endIdx, vector<vector<int>>& dp) {
    for(int idx = endIdx; idx >= stIdx; idx--) {
        for(int slicesNo = 1; slicesNo <= k/3; slicesNo++) { //as 0 slice case is already handled
            int include = slices[idx] + dp[idx+2][slicesNo-1];
            int exclude = 0 + dp[idx+1][slicesNo];

            dp[idx][slicesNo] = max(include, exclude);
        }
    }

    return dp[stIdx][k/3];
}

int tabulation(vector<int>& slices, int k) {
    vector<vector<int>> dp1(k+2, vector<int>((k/3)+2, 0)); //for out of bound idx safety
    vector<vector<int>> dp2(k+2, vector<int>((k/3)+2, 0));

    int case1 = tabulationHelper(slices, k, 0, k-2, dp1);
    int case2 = tabulationHelper(slices, k, 1, k-1, dp2);

    return max(case1, case2);
}

//--------------------Space Optimization----------------------//

int spaceOptHelper(vector<int>& slices, int k, int stIdx, int endIdx, vector<int>& prev, vector<int>& curr, vector<int>& next) {
    for(int idx = endIdx; idx >= stIdx; idx--) {
        for(int slicesNo = 1; slicesNo <= k/3; slicesNo++) { //as 0 slice case is already handled
            int include = slices[idx] + next[slicesNo-1];
            int exclude = 0 + curr[slicesNo];

            prev[slicesNo] = max(include, exclude);
        }
        next = curr;
        curr = prev;
    }

    return curr[k/3];
}

int spaceOpt(vector<int>& slices, int k) {
    vector<int> prev1((k/3)+2, 0);
    vector<int> curr1((k/3)+2, 0);
    vector<int> next1((k/3)+2, 0);

    vector<int> prev2((k/3)+2, 0);
    vector<int> curr2((k/3)+2, 0);
    vector<int> next2((k/3)+2, 0);

    int case1 = spaceOptHelper(slices, k, 0, k-2, prev1, curr1, next1);
    int case2 = spaceOptHelper(slices, k, 1, k-1, prev2, curr2, next2);

    return max(case1, case2);
}

int maxSizeSlices(vector<int>& slices) {
    int k = slices.size();
    // vector<vector<int>> dp1(k, vector<int>((k/3) + 1, -1));
    // vector<vector<int>> dp2(k, vector<int>((k/3)+1, -1));
    // int case1 = topDown(slices, 0, k-2, k/3, dp1);
    // int case2 = topDown(slices, 1, k-1, k/3, dp2);
    // return max(case1, case2);

    //return tabulation(slices, k);

    return spaceOpt(slices, k);
}

int main() {
    vector<int> slices = {8, 9, 8, 6, 1, 1};
    cout << maxSizeSlices(slices) << endl;
    return 0;
}