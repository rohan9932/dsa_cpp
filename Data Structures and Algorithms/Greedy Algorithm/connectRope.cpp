#include<bits/stdc++.h>
using namespace std;

int minCost(vector<int>& arr) {
    // code here
    priority_queue<int, vector<int>, greater<int>> pq; //minHeap
    for(int i = 0; i < arr.size(); i++) {
        pq.push(arr[i]);
    }
    
    int totalCost = 0;
    
    //take min 2 ropes in each case and connect the ropes
    while(pq.size() > 1) {
        int subRope1 = pq.top();
        pq.pop(); //->remove the element;
        int subRope2 = pq.top();
        pq.pop();
        
        int addedRope = subRope1 + subRope2;
        totalCost += addedRope; //->adding the cost to totalCost
        //enter it in the heap to count
        pq.push(addedRope);
    }
    
    return totalCost;
}

int main() {
    vector<int> arr = {2, 3, 4, 6};
    cout << minCost(arr) << endl;
    return 0;
}