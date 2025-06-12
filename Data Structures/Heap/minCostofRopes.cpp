#include<bits/stdc++.h>
using namespace std;

int minCost(vector<int>& arr) {
    // code here
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    for(int i = 0; i < arr.size(); i++) {
        minHeap.push(arr[i]);
    }
    
    int minCost = 0;
    
    while(minHeap.size() > 1) {
        //finding 2 minimum values, poping the values and figuring out their sum
        int a = minHeap.top();
        minHeap.pop();
        int b = minHeap.top();
        minHeap.pop();
        int sum = a + b;
        //then just adding the value to the minCost and pushing the sum to heap
        minCost += sum;
        minHeap.push(sum);
    }
    
    return minCost;
}

int main() {
    vector<int> arr = {4, 3, 2, 6};
    cout << minCost(arr) << "\n";
    return 0;
}