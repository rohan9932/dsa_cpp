#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;

	Node(int data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

void buildFromLvlOrder(Node*& root) { //BFS
	queue<Node*> q;
	cout << "Enter data for root: ";
	int data;
	cin >> data;
	root = new Node(data);
	q.push(root);

	while(!q.empty()) {
		Node* temp = q.front();
		q.pop();

		cout << "Enter left node for " << temp->data << ": ";
		int leftData;
		cin >> leftData;
		if(leftData != -1) {
			temp->left = new Node(leftData);
			q.push(temp->left);
		} 

		cout << "Enter right node for " << temp->data << ": ";
		int rightData;
		cin >> rightData;
		if(rightData != -1) {
			temp->right = new Node(rightData);
			q.push(temp->right);
		}
	}
}

bool isSameTree(Node* p, Node* q) {
    if(p == NULL && q == NULL) return true;
    if(p == NULL && q != NULL) return false;
    if(p != NULL && q == NULL) return false;

    bool left = isSameTree(p->left, q->left);
    bool right = isSameTree(p->right, q->right);
    bool currVal = (p->data == q->data);

    return left && right && currVal;
}

int main() {
    Node* root1 = NULL;
    Node* root2 = NULL;
    buildFromLvlOrder(root1);
    buildFromLvlOrder(root2);

    if(isSameTree(root1, root2)) {
        cout << "Identical\n";
    } else {
        cout << "Not Identical\n";
    }

    return 0;
}