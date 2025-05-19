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

int height(Node* root) {
    if(root == NULL) return 0;

    int l_height = height(root->left);
    int r_height = height(root->right);

    int ans = max(l_height, r_height) + 1;
    return ans;
}

int minDepth(Node* root) {
	if(root == NULL) return 0;

	//edge case if a branch is missing
	if(root->left == NULL) return minDepth(root->right) + 1;
	if(root->right == NULL) return minDepth(root->left) + 1;

	int l_height = minDepth(root->left);
	int r_height = minDepth(root->right);

	int ans = min(l_height, r_height);
	return ans;
}

int main() {
    Node* root = NULL;

    buildFromLvlOrder(root);
    cout << height(root) << "\n";

    return 0;
}