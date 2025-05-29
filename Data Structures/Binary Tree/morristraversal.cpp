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

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    if(root == NULL) return ans;

    TreeNode* curr = root;
    while(curr != NULL) {
        if(curr->left == NULL) {
            ans.push_back(curr->data);
            curr = curr->right;
        } else {
            //find the IP
            TreeNode* IP = curr->left;
            while(IP->right != NULL && IP->right != curr) {
                IP = IP->right;
            }

            if(IP->right == NULL) { //establish connection
                IP->right = curr;
                curr = curr->left;
            } else {
                IP->right = NULL;
                ans.push_back(curr->data);//from left->root node print
                curr = curr->right;
            }
        }
    }

    return ans;
}

int main() {
    return 0;
}