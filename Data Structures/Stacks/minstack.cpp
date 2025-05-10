#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
	stack<pair<int, int>> s;

	void push(int val) {
		if(s.empty()) {
			s.push({val, val});
		} else {
			int minVal = min(val, s.top().second);
			s.push({val, minVal});
		}
	}

	void pop() {
		s.pop();
	}

	int top() {
		return s.top().first;
	}

	int getmin() {
		return s.top().second;
	}
};

class MinStackApproach2 {
public:
	stack<long long int> s;
	long long int minStack;

	void push(int val) {
		if(s.empty()) { //when first element is inserted
			s.push(val);
			minStack = val;
		} else if(val < minStack) { //new MinVal
			s.push(((long long)2*val) - minStack);
			minStack = val;
		} else { //No new MinVal found
			s.push(val);
		}
	}

	void pop() {
		if(s.top() < minStack) { //changing the minval to previous minval
			minStack = (2*minStack) - s.top();
		}
		s.pop();
	}

	int top() {
		return (s.top() < minStack) ? minStack : s.top();
	}

	int getMin() {
		return minStack;
	}
};

int main() {
	#ifndef OJ
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif



	return 0;
}