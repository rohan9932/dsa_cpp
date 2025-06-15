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

int helper(TreeNode* root, int& maxSum) {
    if(root == NULL) return 0;
    //if we get negative from a path just ignore the path
    int leftSum = max(0, helper(root->left, maxSum));
    int rightSum = max(0, helper(root->right, maxSum));
    maxSum = max(maxSum, root->val + leftSum + rightSum); //for each node figuring out sum
    //and comparing with maxSum, if currSum > maxSum change maxSum
    return root->val + max(leftSum, rightSum); //return maxSumPath(left or right) at that level
}
int maxPathSum(TreeNode* root) {
    int maxSum = INT_MIN;
    helper(root, maxSum);
    return maxSum;
}

int main() {
    return 0;
}