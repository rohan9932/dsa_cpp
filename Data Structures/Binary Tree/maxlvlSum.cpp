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


int maxLevelSum(TreeNode* root) {
    int lvl = 0, maxLvl = 1;
    int maxSum = INT_MIN;
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        //manage lvl
        int size = q.size();
        int sum = 0;
        lvl += 1;
        for(int i = 0; i < size; i++) {
            TreeNode* temp = q.front();
            q.pop();

            sum += temp->data;
            if(temp->left) {
                q.push(temp->left);
            }
            if(temp->right) {
                q.push(temp->right);
            }
        }
        if(sum > maxSum) { //update if maxSum found
            maxLvl = lvl;
            maxSum = sum;
        }
    }
    return maxLvl;
}

int main() {
    return 0;
}