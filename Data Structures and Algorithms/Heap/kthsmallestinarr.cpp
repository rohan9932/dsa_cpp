#include <bits/stdc++.h>
using namespace std;

//Approach 1
int kthSmallest(vector<int>& arr, int k) {
    sort(arr.begin(), arr.end());
    return arr[k-1];
}

//Approach 2
int kthSmallest2(vector<int>& arr, int k) {
    priority_queue<int> maxHeap;
    for(int i = 0; i < k; i++) { //push first k el to heap
        maxHeap.push(arr[i]);
    }
    //check for rest
    for(int i = k; i < arr.size(); i++) {
        if(arr[i] < maxHeap.top()) {
            maxHeap.pop();
            maxHeap.push(arr[i]);
        }
    }

    return maxHeap.top(); //kth smallest is in top of heap
}


//kth largest
int kthLargest(vector<int>& arr, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap; 
    for(int i = 0; i < k; i++) {
        minHeap.push(arr[i]);
    }
    for(int i = k; i < arr.size(); i++) {
        if(arr[i] > minHeap.top()) {
            minHeap.pop();
            minHeap.push(arr[i]);
        }
    }
    return minHeap.top();
}

int main() {
    vector<int> arr = {3, 34, 5, 22, 4};
    cout << kthSmallest(arr, 3) << "\n";
    return 0;
}