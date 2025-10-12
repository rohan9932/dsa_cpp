#include<bits/stdc++.h>
using namespace std;

static bool cmp(pair<double, pair<int, int>>& a, pair<double, pair<int, int>>& b) {
    return a.first > b.first;
}

double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
    // code here
    vector<pair<double, pair<int, int>>> valperWt;
    
    for(int i = 0; i < val.size(); i++) {
        double perUnitVal = (double)val[i]/wt[i];
        valperWt.push_back({perUnitVal, {val[i], wt[i]}});
    }
    
    sort(valperWt.begin(), valperWt.end(), cmp);
    
    double maxVal = 0;
    for(int i = 0; i < valperWt.size(); i++) {
        if(valperWt[i].second.second <= capacity) {
            //take full weight's price
            maxVal += valperWt[i].second.first;
            capacity -= valperWt[i].second.second;
        } else { //need to take fraction weight
            maxVal += capacity*valperWt[i].first;
            capacity = 0;
            break;
        }
    }
    
    return maxVal;
}

int main() {
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    cout << fractionalKnapsack(val, wt, 50) << endl;
    return 0;
}