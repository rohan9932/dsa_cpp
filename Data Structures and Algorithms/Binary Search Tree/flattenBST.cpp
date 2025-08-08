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
    if(root == NULL) {
        root = new Node(data);
        return root;
    }
    
    if(data < root->data) {
        root->left = insertToBST(root->left, data);
    } else if(data > root->data) {
        root->right = insertToBST(root->right, data);
    }

    return root;
}

void takeInput(Node*& root) {
    int data;
    cin >> data;

    if(data != -1) {
        root = insertToBST(root, data);
        cin >> data;
    }
}

//Approach
void helper(Node* root, vector<Node*>& inorder) {
    if(root == NULL) return;
    helper(root->left, inorder);
    inorder.push_back(root);
    helper(root->right, inorder);
}

Node *flattenBST(Node *root) {
    // code here
    vector<Node*> inorder;
    helper(root, inorder);
    
    for(int i = 0; i < inorder.size()-1; i++) {
        inorder[i]->left = NULL;
        inorder[i]->right = inorder[i+1];
    }
    inorder[inorder.size()-1]->left = inorder[inorder.size()-1]->right = NULL;
    return inorder[0];
}

int main() {
    return 0;
}