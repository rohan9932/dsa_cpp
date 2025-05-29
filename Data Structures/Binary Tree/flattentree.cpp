#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
	int data;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

void buildFromLvlOrder(TreeNode*& root) { //BFS
	queue<TreeNode*> q;
	cout << "Enter data for root: ";
	int data;
	cin >> data;
	root = new TreeNode(data);
	q.push(root);

	while(!q.empty()) {
		TreeNode* temp = q.front();
		q.pop();

		cout << "Enter left node for " << temp->data << ": ";
		int leftData;
		cin >> leftData;
		if(leftData != -1) {
			temp->left = new TreeNode(leftData);
			q.push(temp->left);
		} 

		cout << "Enter right node for " << temp->data << ": ";
		int rightData;
		cin >> rightData;
		if(rightData != -1) {
			temp->right = new TreeNode(rightData);
			q.push(temp->right);
		}
	}
}


TreeNode* nextRight = NULL;
void flatten(TreeNode* root) {
    if(root == NULL) return;

    //r -> l -> root
    flatten(root->right);
    flatten(root->left);
    root->left = NULL;
    root->right = nextRight;
    nextRight = root;
}

void flatteniterative(TreeNode* root) {
	TreeNode* curr = root;
	while(curr != NULL) {
		if(curr->left != NULL) {
			TreeNode* IP = curr->left;
			while(IP->right != NULL) IP = IP->right;
			IP->right = curr->right;
			curr->right = curr->left;
			curr->left = NULL;
		}
		curr = curr->right;
	}
}

int main() {
    return 0;
}