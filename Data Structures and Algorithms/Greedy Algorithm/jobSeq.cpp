#include<bits/stdc++.h>
using namespace std;

static bool cmp(pair<int, int>& a, pair<int, int>& b) {
    return a.first > b.first;
}

vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
    // code here
    vector<pair<int, int>> data; //pair<profit, deadline>
    
    for(int i = 0; i < deadline.size(); i++) {
        data.push_back({profit[i], deadline[i]});
    }
    
    sort(data.begin(), data.end(), cmp);
    
    vector<bool> isOccupied(deadline.size()+1, false);
    
    int jobCount = 0;
    int maxProfit = 0;
    
    for(int i = 0; i < data.size(); i++) {
        int ddline = data[i].second;
        for(int k = ddline; k > 0; k--) {
            if(!isOccupied[k]) { 
                isOccupied[k] = true;
                jobCount++;
                maxProfit += data[i].first;
                break;
            } 
        }
    }
    
    vector<int> ans = {jobCount, maxProfit};
    
    return ans;
}

int main() {
    vector<int> deadline = {4, 1, 1, 1};
    vector<int> profit = {20, 10, 40, 30};
    vector<int> ans =  jobSequencing(deadline, profit);
    cout << "Max no. of jobs: " << ans[0] << endl;
    cout << "Max profit: " << ans[1] << endl;
    return 0;
}