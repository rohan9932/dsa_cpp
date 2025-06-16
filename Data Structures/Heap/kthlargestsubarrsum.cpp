#include<bits/stdc++.h>
using namespace std;

//Approach 1 (O(n^2logn)) sc: O(n^2)
int kthLargest(vector<int> &arr, int k) {
    // code here
    vector<int> sumStore;
    int n = arr.size();
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += arr[j];
            sumStore.push_back(sum);
        }
    }
    sort(sumStore.begin(), sumStore.end());
    return sumStore[sumStore.size()-k];
}

//Approach 2 (O(n^2)) sc:O(k)
int kthLargest2(vector<int>& arr, int k) {
    int n = arr.size();
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += arr[j];
            if(minHeap.size() < k) {
                minHeap.push(sum);
            } else {
                if(sum > minHeap.top()) {
                    minHeap.pop();
                    minHeap.push(sum);
                }
            }
        }
    }
    return minHeap.top();
}

int main() {
    vector<int> arr = {2, 6, 4, 1};
    cout << kthLargest2(arr, 3) << "\n";
    return 0;
}