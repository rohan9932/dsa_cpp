#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int val;
	Node* next;
	Node* prev;

	Node(int val) {
		this->val = val;
		this->next = this->prev = NULL;
	}
};

class DoublyList {
public:
	Node* head;
	Node* tail;

	DoublyList() {
		head = tail = NULL;
	}

	void push_front(int val) {
		Node* newNode = new Node(val);
		if(head == NULL) {
			head = tail = newNode;
		} else {
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}
	}

	void push_back(int val) {
		Node* newNode = new Node(val);
		if(head == NULL) {
			head = tail = newNode;
		} else {
			newNode->prev = tail;
			tail->next = newNode;
			tail = newNode;
		}
	}

	void pop_front() {
		if(head == NULL) {
			cout << "DLL is empty.\n";
			return;
		}

		Node* temp = head;
		head = head->next;
		if(head != NULL) {
			head->prev = NULL;
		}
		temp->next = NULL;

		delete temp;
	}

	void pop_back() {	
		if(head == NULL) {
			cout << "DLL is empty.\n";
			return;
		}	

		Node* temp = tail;
		tail = tail->prev;
		if(tail != NULL) {
			tail->next = NULL;
		}
		temp->prev = NULL;

		delete temp;
	}

	void printDLL() {
		Node* temp = head;
		while(temp != NULL) {
			cout << temp->val << " <-> ";
			temp = temp->next;
		}
		cout << "NULL\n";
	}
};


int main() {
	#ifndef OJ
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	DoublyList dll;

	dll.push_front(3);
	dll.push_front(2);
	dll.push_front(1);

	dll.push_back(4);

	dll.pop_front();
	dll.pop_back();

	dll.printDLL();


	return 0;
}