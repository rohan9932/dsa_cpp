#include<bits/stdc++.h>
using namespace std; 

static bool cmp(vector<int> a, vector<int> b) {
    if(a[0] == b[0]) return a[1] > b[1];
    return a[0] < b[0];
}

int longestIncreasingSubsequence(vector<int>& heights) {
    vector<int> ans;
    ans.push_back(heights[0]);

    for(int i = 1; i < heights.size(); i++) {
        if(heights[i] > ans.back()) {
            ans.push_back(heights[i]);
        } else {
            int idx = lower_bound(ans.begin(), ans.end(), heights[i]) - ans.begin();
            ans[idx] = heights[i];
        }
    }
    return ans.size();
}

int maxEnvelopes(vector<vector<int>>& envelopes) {
    //sort the vector by increasing according witdth and if same width then decreasing according height
    sort(envelopes.begin(), envelopes.end(), cmp);
    //take the array of height
    vector<int> heights;
    for(int i = 0; i < envelopes.size(); i++) {
        heights.push_back(envelopes[i][1]);
    }
    //perform Longest Increasing Subsequence on the height array 
    return longestIncreasingSubsequence(heights);
}

int main() {
    vector<vector<int>> envelopes = {{5, 4}, {6, 4}, {6, 7}, {2, 3}};
    cout << maxEnvelopes(envelopes) << endl;
    return 0;
}