#include<bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
    int signum(int a, int b) {
        if(a == b) return 0;
        else if(a > b) return 1;
        else return -1;
    }

    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.size() == 0 && minHeap.size() == 0) { //for first element
            minHeap.push(num);
            return;
        }

        double median = findMedian(); //O(1)
        switch (signum(maxHeap.size(), minHeap.size())) {
            case 0:
                if(num > median) {
                    minHeap.push(num);
                } else {
                    maxHeap.push(num);
                }
                return;
            case 1:
                if(num > median) {
                    minHeap.push(num);
                } else {
                    //balancing both side by keeping size diff <= 1
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();
                    maxHeap.push(num); //entering num;
                }
                return;
            case -1:
                if(num > median) {
                    maxHeap.push(minHeap.top());
                    minHeap.pop();
                    minHeap.push(num);
                } else {
                    maxHeap.push(num);
                }
                return;
        }
    }
    
    double findMedian() { //O(1)
        switch (signum(maxHeap.size(), minHeap.size())) {
            case 0:
                return (double)(maxHeap.top() + minHeap.top())/2;
            case 1:
                return maxHeap.top();
            case -1:
                return minHeap.top();
        }
        return 0.0;
    }
};

int main() {
    return 0;
}