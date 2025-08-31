#include<bits/stdc++.h>
using namespace std;

int topDown(int rodSize, vector<int>& price, vector<int>& dp) {
    if(rodSize == 0) return 0;
    if(rodSize < 0) return INT_MIN; //invalid path
    
    if(dp[rodSize] != -1) return dp[rodSize];
    
    int maximum = INT_MIN;
    for(int i = 1; i <= price.size(); i++) {
        maximum = max(maximum, (topDown(rodSize-i, price, dp) + price[i-1]));
    }
    dp[rodSize] = maximum;
    
    return dp[rodSize];
}

int bottomUp(int rodSize, vector<int>& price, vector<int>& dp) {
    //base case analysis
    dp[0] = 0;
    
    for(int i = 1; i <= rodSize; i++) {
        for(int j = 1; j <= i; j++) { //cut size can't exceed rod length
            dp[i] = max(dp[i], dp[i-j] + price[j-1]);
        }
    }
    
    return dp[rodSize];
}

int cutRod(vector<int> &price) {
    // code here
    int rodSize = price.size();
    vector<int> dp(rodSize+1, INT_MIN);
    
    return bottomUp(rodSize, price, dp);
}

int main() {
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    cout << cutRod(price) << endl;
    return 0;
}