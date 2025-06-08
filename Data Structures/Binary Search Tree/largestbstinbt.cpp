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

class Info {
public:
    int max;
    int min;
    bool isBST;
    int sum;
};

Info solve(TreeNode* root, int& maxSum) { //O(n)
    //base case
    if(root == NULL) {
        return {INT_MIN, INT_MAX, true, 0};
    }

    Info left = solve(root->left, maxSum);
    Info right = solve(root->right, maxSum);

    //curr Node
    Info currNode;
    currNode.sum = left.sum + right.sum + root->val;
    currNode.max = max(root->val, right.max);
    currNode.min = min(root->val, left.min);
    currNode.isBST = left.isBST && right.isBST && (left.max < root->val && root->val < right.min);

    //update answer
    if(currNode.isBST) {
        maxSum = max(currNode.sum, maxSum);
    }
    
    return currNode;
}

int maxSumBST(TreeNode* root) {
    int maxSum = 0;
    Info temp = solve(root, maxSum);
    return maxSum;
}

int main() {
    return 0;
}