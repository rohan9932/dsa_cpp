#include<bits/stdc++.h>
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

bool helper(TreeNode* root1, TreeNode* root2) {
    //base case
    if(root1 == NULL && root2 == NULL) return true; 
    if((root1 == NULL && root2 != NULL) || (root1 != NULL && root2 == NULL)) return false;

    //check sides (check left with right && right with left)
    bool side1 = helper(root1->left, root2->right);
    bool side2 = helper(root1->right, root2->left);
    return (root1->val == root2->val) && side1 && side2;
}

bool isSymmetric(TreeNode* root) {
    //1. Make a function to check recursively for any two trees 
    //      i. root values are same
    //      ii. root1->left == root2->right
    //2. now pass the left and right nodes in that helper function
    if(root == NULL) return true;
    return helper(root->left, root->right);
}

int main() {
    return 0;
}