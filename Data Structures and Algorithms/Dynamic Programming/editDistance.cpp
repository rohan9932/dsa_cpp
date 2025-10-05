#include<bits/stdc++.h>
using namespace std;

int topDown(string& word1, string& word2, int i, int j, vector<vector<int>>& dp) {
    if(i == word1.length()) return word2.length()-j;
    if(j == word2.length()) return word1.length()-i;

    if(dp[i][j] != -1) return dp[i][j];

    int ans = 0;
    if(word1[i] == word2[j]) { //char matched so move forward
        ans = topDown(word1, word2, i+1, j+1, dp);
    } else { //3 options
        int replace = 1 + topDown(word1, word2, i+1, j+1, dp);
        int del = 1 + topDown(word1, word2, i+1, j, dp);
        int insert = 1 + topDown(word1, word2, i, j+1, dp);
        ans = min(replace, min(del, insert));
    }

    return dp[i][j] = ans;
}

int tabulation(string& word1, string& word2) {
    //base case analysis
    vector<vector<int>> dp(word1.length()+1, vector<int>(word2.length()+1, 0));
    for(int j = 0; j <= word2.length(); j++) {
        dp[word1.length()][j] = word2.length()-j;
    }
    for(int i = 0; i <= word1.length(); i++) {
        dp[i][word2.length()] = word1.length()-i;
    }

    for(int i = word1.length()-1; i >= 0; i--) {
        for(int j = word2.length()-1; j >= 0; j--) {
            int ans = 0;
            if(word1[i] == word2[j]) { //char matched so move forward
                ans = dp[i+1][j+1];
            } else { //3 options
                int replace = 1 + dp[i+1][j+1];
                int del = 1 + dp[i+1][j];
                int insert = 1 + dp[i][j+1];
                ans = min(replace, min(del, insert));
            }

            dp[i][j] = ans;
        }
    }

    return dp[0][0];
}

int spaceOpt(string& word1, string& word2) {
    //base case analysis
    vector<int> curr(word2.length()+1, 0);
    vector<int> next(word2.length()+1, 0);

    if(word1.length() == 0) return word2.length();
    if(word2.length() == 0) return word1.length();

    //work here
    // for(int j = 0; j <= word2.length(); j++) { -> this potrays every column the last row
    //     dp[word1.length()][j] = word2.length()-j; 
    // }

    for(int j = 0; j <= word2.length(); j++) {
        next[j] = word2.length()-j;
    }

    // for(int i = 0; i <= word1.length(); i++) { -> this potrays last column of each row
    //     dp[i][word2.length()] = word1.length()-i;
    // }

    for(int i = word1.length()-1; i >= 0; i--) {
        for(int j = word2.length()-1; j >= 0; j--) {
            //2nd base case handle(main catch)
            //but as i am handling them in the loop i need to handle 2 base cases when:
                // word1 or word2 has 0 length other one is the answer

            curr[word2.length()] = word1.length()-i;
            
            int ans = 0;
            if(word1[i] == word2[j]) { //char matched so move forward
                ans = next[j+1];
            } else { //3 options
                int replace = 1 + next[j+1];
                int del = 1 + next[j];
                int insert = 1 + curr[j+1];
                ans = min(replace, min(del, insert));
            }

            curr[j] = ans;
        }
        next = curr;
    }

    return next[0];
}

int minDistance(string word1, string word2) {
    // vector<vector<int>> dp(word1.length(), vector<int>(word2.length(), -1));
    // return topDown(word1, word2, 0, 0, dp);

    //return tabulation(word1, word2);

    
    return spaceOpt(word1, word2);
}

int main() {
    string str1 = "horse";
    string str2 = "ose";
    cout << minDistance(str1, str2) << endl;
    return 0;
}