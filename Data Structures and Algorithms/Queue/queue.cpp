#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* next;

	Node(int val) {
		data = val;
		next = NULL;
	}
};

class Queue {
	Node* head;
	Node* tail;

public:
	Queue() {
		head = tail = NULL;
	}

	void push(int data) { //insert data at tail O(1)
		Node* newNode = new Node(data);

		if(empty()) {
			head = tail = newNode;
		} else {
			tail->next = newNode;
			tail = newNode;
		}
	}

	void pop() { //pop head O(1)
		if(empty()) {
			cout << "Queue is empty.\n";
			return;
		}

		Node* temp = head;
		head = head->next;
		delete temp;
	}

	int front() { //O(1)
		if(empty()) {
			cout << "Queue is empty.\n";
			return -1;
		}

		return head->data;
	}

	bool empty() { //O(1)
		return head == NULL;
	}
};

int main() {
	#ifndef OJ
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	Queue q;

	for(int i = 1; i <= 5; i++) {
		q.push(i);
	}

	while(!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
	cout << "\n";

	return 0;
}