#include <bits/stdc++.h>
using namespace std;

class MyStack {
public:
	queue<int> q1;
	queue<int> q2;

    MyStack() {
        
    }
    
    void push(int x) { //O(n)
        while(!q1.empty()) {
        	q2.push(q1.front());
        	q1.pop();
        }
        q1.push(x);
        while(!q2.empty()) {
        	q1.push(q2.front());
        	q2.pop();
        }
    }
    
    int pop() { //O(1)
    	int ans = q1.front();
        q1.pop();
        return ans;
    }
    
    int top() { //O(1)
        return q1.front();
    }
    
    bool empty() { //O(1)
        return q1.empty();
    }
};

int main() {

	return 0;
}