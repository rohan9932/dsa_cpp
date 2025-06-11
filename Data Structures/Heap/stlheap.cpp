#include<bits/stdc++.h>
using namespace std;

int main() {
    //max heap
    priority_queue<int> pq;
    for(int i = 1; i <= 5; i++) {
        pq.push(i);
    }

    cout << "Element at top: " << pq.top() << "\n";
    pq.pop();
    cout << "Element at top: " << pq.top() << "\n";

    cout << "Size: " << pq.size() << "\n";


    //min heap
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for(int i = 1; i <= 5; i++) {
        minHeap.push(i);
    }

    cout << "Element at top: " << minHeap.top() << "\n";
    minHeap.pop();
    cout << "Element at top: " << minHeap.top() << "\n";

    cout << "Size: " << minHeap.size() << "\n";

    return 0;
}