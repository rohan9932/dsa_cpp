#include <bits/stdc++.h>
using namespace std;

class MyCircularQueue {
public:
    int* arr;
    int currSize, cap;
    int f, r;

    MyCircularQueue(int k) {
        cap = k;
        arr = new int[cap];
        f = 0;
        r = -1;
        currSize = 0;
    }
    
    bool enQueue(int value) {
        if(currSize == cap) {
        	cout << "Circular Queue is full\n";
            return false;
        }
        r = (r+1)%cap;
        arr[r] = value;
        currSize++;
        return true;
    }
    
    bool deQueue() {
        if(currSize == 0) {
            return false;
        }
        f = (f+1)%cap;
        currSize--;
        return true;
    }
    
    int Front() {
        return (currSize > 0) ? arr[f] : -1;
    }
    
    int Rear() {
        return (currSize > 0) ? arr[r] : -1;
    }
    
    bool isEmpty() {
        return currSize == 0;
    }
    
    bool isFull() {
        return currSize == cap;
    }

    void printArr() {
    	for(int i = 0; i < cap; i++) {
    		cout << arr[i] << " ";
    	}
    	cout << "\n";
    }
};

int main() {
	#ifndef OJ
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	MyCircularQueue cq(3);

	cq.enQueue(1);
	cq.enQueue(2);
	cq.enQueue(3);
	cq.deQueue();
	cq.enQueue(4);

	cout << cq.Front() << " " << cq.Rear() << "\n";

	cq.printArr();

	while(!cq.isEmpty()) {
		cout << cq.Front() << " ";
		cq.deQueue();
	}

	return 0;
}