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

void helper(TreeNode* root, string path, vector<string>& paths) {
    if(root == NULL) return;
    string rootStr = to_string(root->val);
    path = path + "->" + rootStr;
    //check leaf
    if(root->left == NULL && root->right == NULL) {
        path.erase(0, 2); //remove "->" from start
        paths.push_back(path);
    }
    helper(root->left, path, paths);
    helper(root->right, path, paths);
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> paths;
    string path = "";
    helper(root, path, paths);
    return paths;
}

int main() {
    return 0;
}