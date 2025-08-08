#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public: 
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) {
        this->data = data;
        left = right = NULL;
    }
};


int findPos(vector<int>& inorder, int element) {
    for(int i = 0; i < inorder.size(); i++) {
        if(inorder[i] == element) {
            return i;
        }
    }
    return -1; 
}

TreeNode* helper(vector<int>& inorder, vector<int>& preorder, int& idx, int inorderSt, int inorderEnd) {
    //base case
    if(idx >= preorder.size() || inorderSt > inorderEnd) return NULL;

    int element = preorder[idx++]; //including element and then incrementing the idx
    TreeNode* root = new TreeNode(element);
    int pos = findPos(inorder, element);

    //recursive call
    root->left = helper(inorder, preorder, idx, inorderSt, pos-1);
    root->right = helper(inorder, preorder, idx, pos+1, inorderEnd);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int preOrderIdx = 0;
    TreeNode* ans = helper(inorder, preorder, preOrderIdx, 0, inorder.size()-1);
    return ans;
}

//Optimal -> same as previous just use map to find the indexes
TreeNode* helper2(vector<int>& inorder, vector<int>& preorder, int& idx, int inorderSt, int inorderEnd, unordered_map<int, int>& inOrderIdx) {
    //base case
    if(idx >= preorder.size() || inorderSt > inorderEnd) return NULL;

    int element = preorder[idx++]; //including element and then incrementing the idx
    TreeNode* root = new TreeNode(element);
    int pos = inOrderIdx[element];

    //recursive call
    root->left = helper2(inorder, preorder, idx, inorderSt, pos-1, inOrderIdx);
    root->right = helper2(inorder, preorder, idx, pos+1, inorderEnd, inOrderIdx);

    return root;
}

TreeNode* buildTreeOptimal(vector<int>& preorder, vector<int>& inorder) {
    int preOrderIdx = 0;
    unordered_map<int, int> nodeToIdx;

    //create mapping -> storing the indices of the elements in inorder
    for(int i = 0; i < inorder.size(); i++) {
        nodeToIdx[inorder[i]] = i;
    }

    TreeNode* ans = helper(inorder, preorder, preOrderIdx, 0, inorder.size()-1);
    return ans;
}

int main() {
    return 0;
}