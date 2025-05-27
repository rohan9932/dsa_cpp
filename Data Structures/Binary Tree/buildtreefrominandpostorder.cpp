#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public: 
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) {
        this->data = data;
        right = left = NULL;
    }
};

TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int& idx, int inorderSt, int inorderEnd, unordered_map<int, int>& inorderIdx) {
    //base case 
    if(idx > inorder.size() || inorderSt > inorderEnd) return NULL;

    int el = postorder[idx--]; //takes element and update idx
    TreeNode* root = new TreeNode(el);
    int pos = inorderIdx[el];

    //recursive call
    root->right = helper(inorder, postorder, idx, pos+1, inorderEnd, inorderIdx);
    root->left = helper(inorder, postorder, idx, inorderSt, pos-1, inorderIdx); 

    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int postOrderIdx = postorder.size()-1;
    unordered_map<int, int> inorderelIdx;

    for(int i = 0; i < inorder.size(); i++) { //storing in map
        inorderelIdx[inorder[i]] = i;
    }

    TreeNode* root = helper(inorder, postorder, postOrderIdx, 0, inorder.size()-1, inorderelIdx);
    return root;
}

int main() {
    return 0;
}