#include<bits/stdc++.h>
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

//helper of step 1
void inorder(Node* root, int& cntNode) {
    if(root == NULL) return;
    inorder(root->left, cntNode);
    cntNode++;

    inorder(root->right, cntNode);
}

bool helper(Node* root, int idx, int cntNode) {
    if(root == NULL) return true;
    else if(idx > cntNode) return false;
    else {
        bool leftAns = helper(root->left, 2*idx, cntNode);
        bool rightAns = helper(root->right, 2*idx+1, cntNode);
        return leftAns && rightAns;
    }
}

//step 1
bool isCompleteTree(Node* root) {
    int cntNode = 0;
    inorder(root, cntNode);
    return helper(root, 1, cntNode);
}

//step 2
bool isMaxHeap(Node* root) {
    //Leaf nodes
    if(root->left == NULL && root->right == NULL) return true;
    else if(root->right == NULL) { //1 child
        return root->data > root->left->data;
    } else { //both children
        return root->data > root->left->data && root->data > root->right->data && isMaxHeap(root->left) && isMaxHeap(root->right);
    }
}

bool isHeap(Node* root) {
    // code here
    if(isCompleteTree(root) && isMaxHeap(root)) {
        return true;
    }
    return false;
}

int main() {
    return 0;
}