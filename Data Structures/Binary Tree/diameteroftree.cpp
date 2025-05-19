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

//Naive Approach
int height(Node* root) {
    if(root == NULL) return 0;

    int l_height = height(root->left);
    int r_height = height(root->right);

    int ans = max(l_height, r_height) + 1;
    return ans;
}

int diameterOfBinaryTree(Node* root) {
    if(root == NULL) return 0;

    int op1 = diameterOfBinaryTree(root->left);
    int op2 = diameterOfBinaryTree(root->right);
    int op3 = height(root->left) + height(root->right);

    int ans = max(op1, max(op2, op3));
    return ans;
}

//Optimized Approach
pair<int, int> helper(Node* root) {
    pair<int, int> ans;
    if(root == NULL) {
        ans = make_pair(0, 0);
        return ans;
    }

    pair<int, int> left = helper(root->left);
    pair<int, int> right = helper(root->right);

    int op1 = left.first; //first diameter and second height
    int op2 = right.first;
    int op3 = left.second + right.second; //l_height + r_height

    ans.first = max(op1, max(op2, op3)); //diameter
    ans.second = max(left.second, right.second) + 1;

    return ans;
}

int diameterOfBinaryTreeOptimized(Node* root) {
    return helper(root).first;
}

int main() {
    Node* root = NULL;
    buildFromLvlOrder(root);

    cout << "Diameter of the tree is: " << diameterOfBinaryTreeOptimized(root) << "\n";

    return 0;
}