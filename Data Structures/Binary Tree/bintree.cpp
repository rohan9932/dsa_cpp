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

void inorderIterative(Node* root) {
	//1.Push the root to the stack and start going to left (while the node is not NULL)
	//2.If we get NULL then return to root and print by printing the top node on stack (then pop it)
	//3. Move to right
	//4. If at any point stack is empty then traversal is over and break the loop
	if(root == NULL) return;

	stack<Node*> s;
	Node* temp = root;

	while(true) {
		if(temp != NULL) {
			s.push(temp);
			temp = temp->left;
		} else {
			if(s.empty()) break;
			temp = s.top();
			s.pop();
			cout << temp->data << " ";
			temp = temp->right;
		}
	}
}

void preorder(Node* root) {
	if(root == NULL) return;

	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}

void preorderIterative(Node* root) {
	//1. Take a stack. Push root to it
	//2. like level order traversal traverse while stack is not empty
	//3. take the top element(which is the root of that subtree) and pop it from stack. 
	//4. print the root
	//5. push the right and then left element of the root in the stack
	if(root == NULL) return;

	stack<Node*> s;
	s.push(root);
	while(!s.empty()) {
		Node* root = s.top();
		s.pop();
		cout << root->data << " ";
		//first right then left (As stack is LIFO(reversed output))
		if(root->right) {
			s.push(root->right);
		}
		if(root->left) {
			s.push(root->left);
		}
	}
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