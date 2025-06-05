#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

TreeNode* insertToBST(TreeNode* root, int val) {
    if(root == NULL) {
        root = new TreeNode(val);
        return root;
    }

    if(val < root->val) {
        root->left = insertToBST(root, val);
    } else {
        root->right = insertToBST(root, val);
    }

    return root;
}

void takeInput(TreeNode*& root) {
    int data;
    cin >> data;
    if(data != -1) {
        root = insertToBST(root, data);
        cin >> data;
    } 
}

//Code
void helper(TreeNode* root, vector<TreeNode*>& inorder) {
    if(root == NULL) return;
    helper(root->left, inorder);
    inorder.push_back(root);
    helper(root->right, inorder);
}

TreeNode* inorderToBST(int st, int end, vector<TreeNode*>& inorder) {
    //base case
    if(st > end) return NULL;

    int mid = st + (end - st)/2;
    TreeNode* root = inorder[mid];
    root->left = inorderToBST(st, mid-1, inorder);
    root->right = inorderToBST(mid+1, end, inorder);
    
    return root;
}

TreeNode* balanceBST(TreeNode* root) {
    vector<TreeNode*> inorder;
    helper(root, inorder);
    return inorderToBST(0, inorder.size()-1, inorder);
}

int main() {
    return 0;
}