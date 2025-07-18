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

void postordertwoStackcs(Node* root) {
	// 1. Take two stacks
	// 2. Push root to the first stack
	// 3. Traverese the first stack while stack isn't empty
	// 4. Take the top element and push that to other stack
	// 5. If left and right exists of temp push them to current stack
	// 6. when stack 1 is empty traverse the stack 2 and print it.
	if(root == NULL) return;
	stack<Node*> s1, s2;
	s1.push(root);
	while(!s1.empty()) {
		Node* temp = s1.top();
		s1.pop();
		s2.push(temp);
		if(temp->left) {
			s1.push(temp->left);
		}
		if(temp->right) {
			s1.push(temp->right);
		}
	}
	while(!s2.empty()) {
		cout << s2.top() << " ";
		s2.pop();
	}
	cout << "\n";
}

void postorderoneStack(Node* root) {
	if(root == NULL) return;
	vector<int> postorder;
	stack<Node*> s;
	s.push(root);
	while(!s.empty()) {
		Node* temp = s.top();
		s.pop();
		postorder.push_back(temp->data);
		if(temp->left) {
			s.push(temp->left);
		}
		if(temp->right) {
			s.push(temp->right);
		}
	}
	reverse(postorder.begin(), postorder.end());
	cout << "\n";
}

//all traversals using iteration
void inprepostorder(Node* root, vector<int>& preorder, vector<int>& inorder, vector<int>& postorder) {
	if(root == NULL) return;
	stack<pair<Node*, int>> s;
	s.push({root, 1});
	while(!s.empty()) {
		pair<Node*, int> temp = s.top();
		s.pop();
		if(temp.second == 1) { //preorder
			preorder.push_back(temp.first->data);
			temp.second++;
			s.push(temp);
			if(temp.first->left) {
				s.push({temp.first->left, 1});
			}
		} else if(temp.second == 2) { //inorder
			inorder.push_back(temp.first->data);
			temp.second++;
			s.push(temp);
			if(temp.first->right) { //postorder
				s.push({temp.first->right, 1});
			}
		} else {
			postorder.push_back(temp.first->data);
		}
	}
}

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