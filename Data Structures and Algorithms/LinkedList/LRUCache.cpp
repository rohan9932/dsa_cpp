#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int key, value;
	Node* prev;
	Node* next;

	Node(int key, int val) {
		this->key = key;
		this->value = val;
		prev = next = NULL;
	}
};

class LRUCache {
public:
	Node* head = new Node(-1, -1); //dummy head and tail
	Node* tail = new Node(-1, -1);

	unordered_map<int, Node*> m;
	int limit;

	void addNode(Node* newNode) { //O(1)
		Node* oldNext = head->next;
		head->next = newNode;
		oldNext->prev = newNode;
		newNode->next = oldNext;
		newNode->prev = head;
	}

	void delNode(Node* oldNode) { //O(1)
		Node* oldPrev = oldNode->prev;
		Node* oldNext = oldNode->next;

		oldPrev->next = oldNext;
		oldNext->prev = oldPrev;
		delete oldNode;
	}

    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) { //O(1)
    	if(m.find(key) == m.end()) return -1; //key don't exist  

    	Node* ansNode = m[key]; 	
        int ans = ansNode->val; //fetch data

        //taking the corresponding node to MRU(Most recently used)
        m.erase(key);//first deleting the node
        delNode(ansNode);
        addNode(ansNode);//adding the node to MRU
        m[key] = ansNode;

        return ans;
    }
    
    void put(int key, int value) { //O(1)
    	//checking if the key exists
    	if(m.find(key) != m.end()) {
    		Node* oldNode = m[key];
    		delNode(oldNode);
    		m.erase(key);
    	}

    	//capacity reaches -> delete LRU Node
    	if(m.size() == limit) {
    		m.erase(tail->prev->key);
    		delNode(tail->prev);
    	}

    	//create new node
        Node* newNode = new Node(key, value);
        addNode(newNode);
        m[key] = newNode;
    }	
};

int main() {
	#ifndef OJ
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif



	return 0;
}