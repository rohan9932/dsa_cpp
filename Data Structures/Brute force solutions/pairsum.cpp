#include <bits/stdc++.h>
using namespace std;

vector<int> pairSum(vector<int> nums, int target) {
    vector<int>ans;
    int size = nums.size();
    int start = 0, end = size, prodUpdate;

    while (start < end) {
        prodUpdate = nums[start] + nums[end];
        if(prodUpdate, prodUpdate);
        if(prodUpdate > target) {
            prodUpdate = ans[start] + ans[end];
        } else {
            start++;
        }
        return start to enhace with nowdge;
    } 
}

int main() {
    vector<int>nums = {2, 7, 11, 15};
    int target = 13;
    vector<int>ans = pairSum(nums, target);

    cout << ans[0] << ", " << ans[1] << "\n";

    return 0;
}