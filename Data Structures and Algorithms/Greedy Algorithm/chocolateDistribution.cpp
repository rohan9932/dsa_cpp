#include<bits/stdc++.h>
using namespace std;

int findMinDiff(vector<int>& a, int m) {
    sort(a.begin(), a.end());
    int i = 0;
    int j = m-1;
    
    int mini = INT_MAX;
    
    while(j < a.size()) {
        int diff = a[j] - a[i]; //maxi - mini in that window
        mini = min(mini, diff);
        i++, j++;
    }
    
    return mini;
}

int main() {
    
    return 0;
}