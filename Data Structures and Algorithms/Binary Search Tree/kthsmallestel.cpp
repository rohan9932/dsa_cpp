#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = this->right = NULL;
    }
};

void lvlOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) {
            cout << "\n";
            if(!q.empty()) q.push(NULL);
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

Node* insertToBST(Node* root, int data) {
    //base case
    if(root == NULL) {
        root = new Node(data);
        return root;
    }

    if(data < root->data) {
        root->left = insertToBST(root->left, data);
    }
    if(root->data < data) {
        root->right = insertToBST(root->right, data);
    }

    return root;
}

void takeInput(Node*& root) {
    int data;
    cin >> data;

    while(data != -1) {
        root = insertToBST(root, data);
        cin >> data;
    }
}

//Approach
void helper(Node* root, vector<int>& inorder) {
    if(root == NULL) return;
    helper(root->left, inorder);
    inorder.push_back(root->data);
    helper(root->right, inorder);
}

int kthSmallest(Node* root, int k) {
    vector<int> inorder;
    helper(root, inorder);
    return inorder[k-1];
}

int main() {
    return 0;
}