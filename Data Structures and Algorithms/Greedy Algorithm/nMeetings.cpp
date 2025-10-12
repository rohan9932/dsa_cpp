#include<bits/stdc++.h>
using namespace std;

static bool cmp(pair<int, int>& a, pair<int, int>& b) {
    return a.second < b.second;
}

int maxMeetings(vector<int>& start, vector<int>& end) {
    // Your code here
    vector<pair<int, int>> v; //st , end pair
    
    for(int i = 0; i < start.size(); i++) {
        v.push_back({start[i], end[i]});
    }
    
    sort(v.begin(), v.end(), cmp);
    
    int cnt = 1;
    int currEnd = v[0].second;
    for(int i = 1; i < v.size(); i++) {
        if(v[i].first > currEnd) {
            cnt++;
            currEnd = v[i].second;
        }
    }
    
    return cnt;
}

int main() {
    vector<int> start = {1, 2};
    vector<int> end = {100, 99};
    
    cout << maxMeetings(start, end) << endl;

    return 0;
}