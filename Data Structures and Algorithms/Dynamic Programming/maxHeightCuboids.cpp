#include<bits/stdc++.h>
using namespace std;

int spaceOpt(vector<vector<int>>& cuboids, int n) {
    vector<int> curr(n+1, 0);
    vector<int> next(n+1, 0);

    for(int currIdx = n-1; currIdx >= 0; currIdx--) {
        for(int prevIdx = currIdx-1; prevIdx >= -1; prevIdx--) {
            //include
            int include = 0;
            //in every LIS problems changes are made in these next 2 lines only
            if(prevIdx == -1 || (cuboids[prevIdx][2] <= cuboids[currIdx][2] && cuboids[prevIdx][1] <= cuboids[currIdx][1] && cuboids[prevIdx][0] <= cuboids[currIdx][0])) 
                include = cuboids[currIdx][2] + next[currIdx + 1]; //as we are shifting whole co-ordinate to avoid invalid Idx

            //exclude 
            int exclude = 0 + next[prevIdx+1]; //to avoid invalid idx

            curr[prevIdx+1] = max(include, exclude); //to avoid invalid idx
        }
        next = curr;
    }

    return next[0];
}

int maxHeight(vector<vector<int>>& cuboids) {
    //sort all cuiboid's dimesions
    for(auto& vec: cuboids) {
        sort(vec.begin(), vec.end());
    }

    //sort according width or length
    sort(cuboids.begin(), cuboids.end());

    int n = cuboids.size();
    //use LIS logic
    return spaceOpt(cuboids, n);
}

int main() {
    vector<vector<int>> cuboids = {{50, 45, 20}, {95, 37, 57}, {45, 23, 12}};
    vector<vector<int>> cuboids2 = {{7, 11, 17}, {7, 17, 11}, {11, 7, 17}, {11, 17, 7}, {17, 7, 11}, {17, 11, 7}};
    cout << maxHeight(cuboids) << endl;
    cout << maxHeight(cuboids2) << endl;
    return 0;
}