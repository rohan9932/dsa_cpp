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

bool isBalanced(Node* root) {
    if(root == NULL) return true;
    
    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);
    bool diff = abs(height(root->left) - height(root->right)) <= 1;

    return (left && right && diff);
}

//OptimizedApproach
pair<bool, int> helper(Node* root) {
    pair<bool, int> ans;
    if(root == NULL) {
        ans.first = true;
        ans.second = 0;
        return ans;
    }

    pair<bool, int> left = helper(root->left);
    pair<bool, int> right = helper(root->right);

    bool left_balanced = left.first;
    bool right_balanced = right.first;
    bool diff = abs(left.second - right.second) <= 1;

    ans.first = left_balanced && right_balanced && diff;
    ans.second = max(left.second, right.second) + 1;
    return ans;
}

bool isBalancedOptimized(Node* root) {
    return helper(root).first;
}

int main() {
    Node* root = NULL;
    buildFromLvlOrder(root);

    if(isBalancedOptimized(root)) {
        cout << "Balanced\n";
    } else {
        cout << "Not Balanced\n";
    }

    return 0;
}