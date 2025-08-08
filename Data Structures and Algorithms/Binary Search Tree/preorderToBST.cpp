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


//Approach 1
TreeNode* helper(vector<int>& preorder, int& idx, int min, int max) {
    if(idx >= preorder.size()) return NULL; //traversed all nodes
    if(preorder[idx] < min || preorder[idx] > max) return NULL; //out of range

    TreeNode* root = new TreeNode(preorder[idx++]);
    root->left = helper(preorder, idx, min, root->val);
    root->right = helper(preorder, idx, root->val, max);
    return root;
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
    int idx = 0;  
    return helper(preorder, idx, INT_MIN, INT_MAX);
}


//Approach 2 (taking inorder and making BST from inorder and preorder)
TreeNode* createBST(vector<int>& preorder, vector<int>& inorder, int& idx, int st, int end, unordered_map<int, int>& inorderIdx) {
    //base case
    if(idx > preorder.size() || st > end) return NULL;

    int el = preorder[idx++];
    TreeNode* root = new TreeNode(el);
    int pos = inorderIdx[el];

    //recursive call
    root->left = createBST(preorder, inorder, idx, st, pos-1, inorderIdx);
    root->right = createBST(preorder, inorder, idx, pos+1, end, inorderIdx);

    return root;
} 

TreeNode* bstFromPreorder2(vector<int>& preorder) {
    vector<int> inorder = preorder;
    sort(inorder.begin(), inorder.end()); //inorder

    unordered_map<int, int> inorderIdx;
    for(int i = 0; i < inorder.size(); i++) {
        inorderIdx[inorder[i]] = i;
    }
    
    int idx = 0;
    return createBST(preorder, inorder, idx, 0, preorder.size()-1, inorderIdx);
}

int main() {
    return 0;
}