#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int val;
	Node* next;

	Node(int val) {
		this->val = val;
		this->next = NULL;
	}
};

class CircularList {
public:
	Node* head;
	Node* tail;

	CircularList() {
		head = tail = NULL;
	}

	void insert_at_head(int val) {
		Node* newNode = new Node(val);
		if(head == NULL) {
			head = tail = newNode;
			tail->next = head;
		} else {
			newNode->next = head;
			head = newNode;
			tail->next = head;
		}
	}

	void insert_at_tail(int val) {
		Node* newNode = new Node(val);
		if(head == NULL) {
			head = tail = newNode;
			tail->next = head;
		} else {
			tail->next = newNode;
			newNode->next = head;
			tail = newNode;
		}
	}

	void delete_at_head() {
		if(head == NULL) return;
		else if(head == tail) {
			delete head;
			head = tail = NULL;
		} else {
			Node* temp = head;
			head = head->next;
			tail->next = head;
			temp->next = NULL;
			delete temp;
		}
	}

	void delete_at_tail() {
		if(head == NULL) return;
		else if(head == tail) {
			delete tail;
			head = tail = NULL;
		} else {
			Node* temp = tail;
			Node* prev = head;

			while(prev->next != tail) {
				prev = prev->next;
			}

			tail = prev;
			tail->next = head;
			temp->next = NULL;
			delete temp;
		}
	}

	void printCLL() {
		if(head == NULL) return;

		cout << head->val << "->";
		Node* temp = head->next;

		while(temp != head) {
			cout << temp->val << "->";
			temp = temp->next;
		}

		cout << temp->val << "\n";
	}
};

int main() {
	#ifndef OJ
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	CircularList cll;
	cll.insert_at_head(3);
	cll.insert_at_head(2);
	cll.insert_at_head(1);

	cll.insert_at_tail(4);
	cll.insert_at_tail(5);
	cll.insert_at_tail(6);

	cll.delete_at_head();
	cll.delete_at_tail();
	cll.delete_at_tail();

	cll.printCLL();


	return 0;
}