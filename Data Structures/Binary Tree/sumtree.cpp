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

pair<bool, int> helper(Node* root) {
    //base case
    pair<bool, int> ans;
    if(root == NULL) {
        ans = make_pair(true, 0);
        return ans;
    }
    if(root->left == NULL && root->right == NULL) {
        ans = make_pair(true, root->data);
        return ans;
    }
    
    pair<bool, int> left = helper(root->left);
    pair<bool, int> right = helper(root->right);
    
    int sumTree = left.second + right.second;
    
    ans.first = left.first && right.first && (sumTree == root->data);
    ans.second = root->data + sumTree;
    return ans;
}

bool isSumTree(Node* root) {
    // Your code here
    return helper(root).first;
}

int main() {
    Node* root = NULL;
    buildFromLvlOrder(root);

    if(isSumTree(root)) {
        cout << "Sum Tree\n";
    } else {
        cout << "Not Sum Tree\n";
    }
    
    return 0;
}