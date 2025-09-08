#include<bits/stdc++.h>
using namespace std;

int topDown(vector<int>& obstacles, int currLane, int position, vector<vector<int>>& dp) {
    //base case
    if(position == obstacles.size()-1) return 0;
    
    //check cache
    if(dp[currLane][position] != -1) return dp[currLane][position];

    if(obstacles[position+1] != currLane) {
        return topDown(obstacles, currLane, position+1, dp); //move forward
    } else {
        int ans = INT_MAX;
        for(int i = 1; i <= 3; i++) {
            if(currLane != i && obstacles[position] != i) {
                ans = min(ans, 1 + topDown(obstacles, i, position, dp));
            }
        }
        dp[currLane][position] = ans; //store in cache
        return dp[currLane][position];
    }
}

int tabulation(vector<int>& obstacles, vector<vector<int>>& dp) {
    int n = obstacles.size()-1;
    //analyze base case
    for(int i = 0; i <= 3; i++) {
        dp[i][n] = 0;
    }

    for(int position = n-1; position >= 0; position--) {
        for(int lane = 1; lane <= 3; lane++) {
            if(obstacles[position+1] != lane) {
                dp[lane][position] = dp[lane][position+1]; //move forward
            } else {
                int ans = INT_MAX;
                for(int i = 1; i <= 3; i++) {
                    if(lane != i && obstacles[position] != i) {
                        ans = min(ans, 1 + dp[i][position+1]); // pos + 1 for handling edge case
                    }
                }
                dp[lane][position] = ans; //store in cache
            }
        }
    }
    return min(dp[2][0], min(1 + dp[1][0], 1 + dp[3][0]));
}

int spaceOpt(vector<int>& obstacles) {
    int n = obstacles.size()-1;

    //2 columns
    vector<int> curr(4, INT_MAX);
    vector<int> next(4, INT_MAX);

    for(int i = 0; i < 4; i++) {
        next[i] = 0;
    }

    for(int position = n-1; position >= 0; position--) {
        for(int lane = 1; lane <= 3; lane++) {
            if(obstacles[position+1] != lane) {
                curr[lane] = next[lane];
            } else {
                int ans = INT_MAX;
                for(int i = 1; i <= 3; i++) {
                    if(lane != i && obstacles[position] != i) {
                        ans = min(ans, 1 + next[i]);
                    }
                }
                curr[lane] = ans;
            }
        }
        next = curr; //updating next column
    }
    return min(next[2], min(1 + next[1], 1 + next[3]));
}

int minSideJumps(vector<int>& obstacles) {
    int n = obstacles.size();
    vector<vector<int>> dp(4, vector<int>(n, 1e9)); // as n is already total positions + 1 accordin question
    //return topDown(obstacles, 2, 0, dp);
    //return tabulation(obstacles, dp);
    return spaceOpt(obstacles);
}

int main() {
    vector<int> obstacles = {0, 1, 2, 3, 0};
    cout << minSideJumps(obstacles) << endl;
    return 0;
}