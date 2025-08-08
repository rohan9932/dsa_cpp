#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public: 
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        this->val = val;
        left = right = NULL;
    }
};

void mapping(TreeNode* root, map<int, int>& m, int lvl) {
    if(root == NULL) return;
    m[lvl] = root->val;
    mapping(root->left, m, lvl+1);
    mapping(root->right, m, lvl+1);
}
vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    if(root == NULL) return ans;
    map<int, int> m;
    mapping(root, m, 0);
    for(auto i: m){
        ans.push_back(i.second);
    }
    return ans;
}

int main() {
    return 0;
}