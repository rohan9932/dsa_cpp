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

//helper
void bstToInorder(Node* root, vector<int>& inorder) {
    if(root == NULL) return;
    bstToInorder(root->left, inorder);
    inorder.push_back(root->data);
    bstToInorder(root->right, inorder);
}


//BST to MaxHeap
void buildFromPostorder(Node* &root, vector<int>& inorder, int& idx) {
    if(root == NULL) return;
    buildFromPostorder(root->left, inorder, idx);
    buildFromPostorder(root->right, inorder, idx);
    root->data = inorder[idx++];
}

void convertToMaxHeapUtil(Node* root) {
    // Your code goes here
    //BST to inorder
    vector<int> inorder;
    bstToInorder(root, inorder);
    //build postorder
    int idx = 0;
    buildFromPostorder(root, inorder, idx);
}


//BST to MinHeap
void buildFromPreorder(Node* &root, vector<int>& inorder, int& idx) {
    if(root == NULL) return;
    root->data = inorder[idx++];
    buildFromPreorder(root->left, inorder, idx);
    buildFromPreorder(root->right, inorder, idx);
}

void convertToMinHeap(Node* root) {
    // Your code goes here
    //BST to inorder
    vector<int> inorder;
    bstToInorder(root, inorder);
    //build preorder
    int idx = 0;
    buildFromPreorder(root, inorder, idx);
}

int main() {
    return 0;
}