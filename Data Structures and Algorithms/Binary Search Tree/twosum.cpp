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

//Approach
void helper(TreeNode* root, vector<int>& inorder) { //inorder traversal in a vector
    if(root == NULL) return;
    helper(root->left, inorder);
    inorder.push_back(root->val);
    helper(root->right, inorder);
} 

bool findTarget(TreeNode* root, int k) {
    vector<int> inorder;
    helper(root, inorder);
    int st = 0, end = inorder.size()-1;
    while(st < end) { //finding with 2 sum method
        int sum = inorder[st] + inorder[end];
        if(sum == k) return true;
        else if(sum > k) end--;
        else st++;
    }
    return false;
}

int main() {
    return 0;
}