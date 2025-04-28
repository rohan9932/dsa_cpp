#include <bits/stdc++.h>
using namespace std;

class Stack {
	vector<int> v;

public:
	void push(int val) { //0(1)
		v.push_back(val);
	}

	void pop() { //O(1)
		v.pop_back();
	}

	int top() { //O(1)
		return v[v.size()-1];
	}

	bool empty() {
		if(v.size() == 0) return true;
		else return false;
	}
};

class StackwithLL {
	list<int> ll;

public:
	void push(int val) { //O(1)
		ll.push_front(val);
	}

	void pop() { //O(1)
		ll.pop_front();
	}

	int top() { //O(1)
		return ll.front();
	}

	bool empty() {
		if(ll.empty()) return true;
		else return false;
	}
};

int main() {
	StackwithLL s;

	for(int i = 1; i <= 10; i++) {
		s.push(i);
	}

	while(!s.empty()) {
		cout << s.top() << "\n";
		s.pop();
	}
	cout << "\n";


	//C++ STL
	stack<int> stack;

	for(int i = 1; i <= 10; i++) {
		stack.push(i);
	}

	while(!stack.empty()) {
		cout << stack.top() << "\n";
		stack.pop();
	}


	return 0;
}