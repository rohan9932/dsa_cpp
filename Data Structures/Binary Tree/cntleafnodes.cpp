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

void inOrder(Node* root, int& cnt) {
    if(root == NULL) return;
    inOrder(root->left, cnt);
    //leaf node cnt
    if(root->left == NULL && root->right == NULL) cnt++;
    inOrder(root->right, cnt);
} 

int noOfLeafNodes(Node*root){
    // Write your code here.
    int cnt = 0;
    inOrder(root, cnt);
    return cnt;
}
 
int main() {
    Node* root = NULL;
    buildFromLvlOrder(root);
    cout << noOfLeafNodes(root) << "\n";
    
    return 0;
}