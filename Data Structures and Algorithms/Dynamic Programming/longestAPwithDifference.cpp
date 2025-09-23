#include<bits/stdc++.h>
using namespace std;

int longestSubsequence(vector<int>& arr, int difference) {
    unordered_map<int, int> map; //here the map stores the longestAP(value) till that idx(key)
    int ans = 0;

    for(int i = 0; i < arr.size(); i++) {
        int cnt = 1; //as count will be default 1
        int requiredNum = arr[i]-difference;
        if(map.find(requiredNum) != map.end()) 
            cnt = 1 + map[requiredNum]; //requiredNum's longestAp + 1(including current Element)

        map[arr[i]] = cnt;
        ans = max(ans, map[arr[i]]);
    }

    return ans;
}

int main() {
    vector<int> arr = {1, 5, 7, 8, 5, 3, 4, 2, 1};
    int difference = -2;
    cout << longestSubsequence(arr, difference) << endl;
    return 0;
}