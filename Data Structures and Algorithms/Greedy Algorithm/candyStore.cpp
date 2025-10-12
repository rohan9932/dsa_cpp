#include<bits/stdc++.h>
using namespace std;

vector<int> minMaxCandy(vector<int>& prices, int k) {
    // Code here
    sort(prices.begin(), prices.end());
    //min Price
    int minPrice = 0;
    int buy = 0;
    int free = prices.size()-1;
    
    while(buy <= free) {
        minPrice += prices[buy];
        buy++;
        free -= k;
    }
    
    //maxPrice 
    int maxPrice = 0;
    buy = prices.size()-1;
    free = 0;
    
    while(free <= buy) {
        maxPrice += prices[buy];
        buy--;
        free += k;
    }
    
    return vector<int>({minPrice, maxPrice});
}

int main() {
    vector<int> prices = {9, 8, 7, 6, 5, 4, 3};
    int k = 3;

    vector<int> ans = minMaxCandy(prices, k);
    for(auto val: ans) cout << val << " ";
    cout << endl;
    
    return 0;
}