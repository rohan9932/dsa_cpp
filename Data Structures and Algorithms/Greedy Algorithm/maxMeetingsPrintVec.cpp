#include<bits/stdc++.h>
using namespace std;

static bool cmp(pair<int, int>& a, pair<int, int>& b) {
    return a.second < b.second;
}

vector<int> maxMeetings(int N, vector<int> &S, vector<int> &F) {
    vector<pair<int, int>> v;
    
    for(int i = 0; i < S.size(); i++) {
        v.push_back({S[i], F[i]});
    }
    
    map<pair<int, int>, int> m;
    for(int i = 0; i < v.size(); i++) {
        //edge case handle -> handle same meeting slot
        if(m.find(v[i]) == m.end()) {
            m[v[i]] = i+1;
        }
    }
    
    sort(v.begin(), v.end(), cmp);
    
    vector<int> ans;
    int currEnd = v[0].second;
    ans.push_back(m[v[0]]);
    for(int i = 1; i < v.size(); i++) {
        if(v[i].first > currEnd) {
            ans.push_back(m[v[i]]);
            currEnd = v[i].second;
        } 
    }
    
    sort(ans.begin(), ans.end()); //question requirement
    
    return ans;
}


int main() {
    vector<int> start = {4, 3, 1, 7, 5};
    vector<int> end = {4, 5, 3, 8, 6};

    vector<int> ans = maxMeetings(start.size(), start, end);

    for(auto val: ans) cout << val << " ";
    cout << endl;

    return 0;
}