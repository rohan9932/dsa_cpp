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

Node* buildTree(Node* root) {
	cout << "Enter the data: ";
	int data;
	cin >> data;
	root = new Node(data);

	if(data == -1) return NULL;

	cout << "Enter data for inserting in left of " << data << "\n";
	root->left = buildTree(root->left);
	cout << "Enter data for inserting in right of " << data << "\n";
	root->right = buildTree(root->right);

	return root; 
}

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

void levelOrderTraversal(Node* root) {
	queue<Node*> q;
	q.push(root);
	q.push(NULL);

	while (!q.empty())
	{
		Node* temp = q.front();
		q.pop();

		if(temp == NULL) { //completed traversal of the previous level
			cout << "\n";
			if(!q.empty()) { //queue still has child nodes
				q.push(NULL);
			}
		} else {
			cout << temp->data << " ";
			if(temp->left) {
				q.push(temp->left);
			}
			if(temp->right) {
				q.push(temp->right);
			}
		}	
	}
}

void revLvlOrderTraversal(Node* root) {
	queue<Node*> q;
	stack<Node*> s;

	q.push(root);
	q.push(NULL);
	
	while(!q.empty()) {
		Node* temp = q.front();
		q.pop();

		s.push(temp);

		if(temp != NULL) {
			if(temp->right) {
				q.push(temp->right);
			}
			if(temp->left) {
				q.push(temp->left);
			}
		} else {
			if(!q.empty()) q.push(NULL);
		}
	}

	while(!s.empty()) {
		if(s.top() == NULL) {
			cout << "\n";
		} else {
			cout << s.top()->data << " ";
		}

		s.pop();
	}
}	

void inorder(Node* root) {
	if(root == NULL) return;

	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

void preorder(Node* root) {
	if(root == NULL) return;

	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}

void postorder(Node* root) {
	if(root == NULL) return;

	postorder(root->left);
	postorder(root->right);
	cout << root->data << " ";
}

//this using iteration

int main() {
	Node* root = NULL;

	//creating a tree

	buildFromLvlOrder(root);
	revLvlOrderTraversal(root);

	// root = buildTree(root);
	// levelOrderTraversal(root);

	// inorder(root);
	// cout << "\n";
	// preorder(root);
	// cout << "\n";
	// postorder(root);
	// cout << "\n";

	return 0;
}