#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data; //value
	Node* next; //next node address

	Node(int val) {
		this->data = val;
		this->next = NULL;
	}
};

class List {
public:
	Node* head;
	Node* tail;

	List() {
		head = tail = NULL;
	}

	void push_front(int val) { //O(1)
		Node* newNode = new Node(val); //node object dynamically as we want to access it in main program
		if(head == NULL) {
			head = tail = newNode;
		} else {
			newNode->next = head;
			head = newNode;
		}
	}

	void push_back(int val) { //O(1)
		Node* newNode = new Node(val); //dynamic
		if(head == NULL) {
			head = tail = newNode;
		} else {
			tail->next = newNode;
			tail = newNode;
		}
	}

	void insert(int val, int position) { //O(N)
		if(position < 0) {
			cout << "Invalid Position.\n";
			return;
		} 
		if(position == 0) {
			push_front(val);
			return;
		} 

		Node* newNode = new Node(val); //creating new node
		Node* temp = head;
		//find posiion's prev node
		for(int i = 0; i < position-1; i++) {
			if(temp == NULL) { //for positions out of bound
				cout << "Invalid Position.\n";
				return;
			}
			temp = temp->next;
		}
		newNode->next = temp->next; //storing next node pos of the inserted node
		temp->next = newNode; //deleting connection of prevnode -> afternode and establishing connection of prevNode -> newNode
	}

	void pop_front() { //O(1)
		if(head == NULL) { 
			cout << "LL is empty.\n";
			return;
		}

		Node* temp = head; //temp var to store head address for deleting later
		head = head->next; //changing the head -> next node
		temp->next = NULL; //disconnect the node from the list
		delete temp; //deleting the node
	}

	void pop_back() { //O(N)
		if(head == NULL) {
			cout << "LL is empty.\n";
			return;
		}

		Node* temp = head;
		while(temp->next->next != NULL) {
			temp = temp->next; // updating the temp to the next until prev node of tail
		}
		//delete connection
		temp->next = NULL; //here temp is equal to prev node of tail
		delete tail; //deleting last node
		tail = temp; //updating tail to previous node
	}

	int search(int key) { //O(N)
		int pos = 0;
		Node* temp = head;
		while(temp != NULL) { //traverse the ll
			if(temp->data == key) {
				return pos;
			}
			pos++;
			temp = temp->next;
		}

		return -1; //if key not found
	}

	void printLL() { //O(N)
		Node* temp = head;
		while(temp != NULL) {
			cout << temp->data << "->";
			temp = temp->next;
		}
		cout << "NULL" << "\n";
	}
};

Node *detectCycle(Node *head) {
    Node* slow = head;
    Node* fast = head;
    bool isCycle = false;

    while(fast != NULL && fast->next != NULL) {
    	slow = slow->next;
    	fast = fast->next->next;

    	if(slow == fast) {
    		isCycle = true;
    		break;
    	}
    }

    if(!isCycle) return NULL;

    slow = head;
    while (slow != fast) {
    	slow = slow->next;
    	fast = fast->next;
    }

    return slow;
}

void removeCycle(Node *head) {
    Node* slow = head;
    Node* fast = head;
    bool isCycle = false;

    while(fast != NULL && fast->next != NULL) {
    	slow = slow->next;
    	fast = fast->next->next;

    	if(slow == fast) {
    		isCycle = true;
    		break;
    	}
    }

    if(!isCycle) return;

    slow = head;
    Node* prev = NULL;
    while (slow != fast) {
    	slow = slow->next; 
    	prev = fast; //storing fast address before updating fast (for storing previous value of fast)
    	fast = fast->next;
    }
    prev->next = NULL;
}


int main() {
	#ifndef OJ
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	List ll;
	ll.push_back(1);
	ll.push_back(2);
	ll.push_back(3);

	ll.tail->next = ll.head;

	Node* cycle_start = detectCycle(ll.head);

	cout << cycle_start->data << "\n";

	return 0;
}