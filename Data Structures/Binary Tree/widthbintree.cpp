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

int widthOfBinaryTree(TreeNode* root) {
    if(root == NULL) return 0;

    int maxSize = INT_MIN;

    queue<pair<TreeNode*, long long>> q; //track root with it's idx
    q.push({root, 0});
    while(!q.empty()) {
        int size = q.size();
        int start = q.front().second; //idx of leftmost element

        int left = 0, right = 0;
        //level wise traverse and pick up left and rightmost idx
        for(int i = 0; i < size; i++) {
            pair<TreeNode*, long long> temp = q.front();
            q.pop();

            TreeNode* frontNode = temp.first;
            long long idx = temp.second;
            idx = idx - start; //Normalize idx starting from 0 for each level to avoid overflow

            if(i == 0) left = idx;
            if(i == size-1) right = idx;

            if(frontNode->left) {
                q.push({frontNode->left, 2*idx+1});
            }
            if(frontNode->right) {
                q.push({frontNode->right, 2*idx+2});
            }
        }
        maxSize = max(maxSize, (int)(right-left+1));
    }
    return maxSize;
}

int main() {
    return 0;
}