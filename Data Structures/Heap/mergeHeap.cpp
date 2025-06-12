#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int>& arr, int idx) {
    int largest = idx;
    int left = 2*idx+1;
    int right = 2*idx+2;
    
    if(left < arr.size() && arr[largest] < arr[left]) largest = left;
    if(right < arr.size() && arr[largest] < arr[right]) largest = right;
    
    if(largest != idx) {
        swap(arr[idx], arr[largest]);
        heapify(arr, largest);
    }
}

vector<int> mergeHeaps(vector<int> &a, vector<int> &b) {
    // your code here
    for(int i = 0; i < b.size(); i++) {
        a.push_back(b[i]);
    }
    
    for(int i = (a.size()/2)-1; i >= 0; i--) {
        heapify(a, i);
    }
    
    return a;
}

int main() {
    return 0;
}