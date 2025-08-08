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

void inorderVec(Node* root, vector<int>& inorder) {
    if(root == NULL) return;
    inorderVec(root->left, inorder);
    inorder.push_back(root->data);
    inorderVec(root->right, inorder);
}

int findCeil(Node* root, int input) {
    // Your code here
    int ceil = -1; //when no ceil is available
    if(root == NULL) return ceil;
    
    vector<int> inorder;
    inorderVec(root, inorder);
    //as inorder in BST is sorted, we are looking for the first value which is = or > the input 
    //which is the answer
    for(int i = 0; i < inorder.size(); i++) { 
        if(inorder[i] >= input) {
            ceil = inorder[i];
            break;
        }
    }
    return ceil;
}

int floor(Node* root, int key) {
    // Your code goes here
    int floor = -1;
    if(root == NULL) return floor;
    
    vector<int> inorder;
    inorderVec(root, inorder);
    for(int i = inorder.size()-1; i >= 0; i--) {
        if(inorder[i] <= key) {
            floor = inorder[i];
            break;
        }
    }
    return floor;
}

int main() {
    return 0;
}