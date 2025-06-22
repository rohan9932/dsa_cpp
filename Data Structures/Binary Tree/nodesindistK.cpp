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

//1. 
void mapping(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentMap) {
    if(root == NULL) return;
    if(root->left != NULL) {
        parentMap[root->left] = root;
    }
    if(root->right != NULL) {
        parentMap[root->right] = root;
    }
    mapping(root->left, parentMap);
    mapping(root->right, parentMap);
}

//2.
void findNodesinDistanceK(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentMap, unordered_map<TreeNode*, bool>& isVisited, int dist, int k, vector<int>& ans) {
    if(root == NULL || isVisited[root]) return;
    isVisited[root] = true;
    if(dist == k) {
        ans.push_back(root->val);
        return;
    }
    findNodesinDistanceK(parentMap[root], parentMap, isVisited, dist+1, k, ans);
    findNodesinDistanceK(root->left, parentMap, isVisited, dist+1, k, ans);
    findNodesinDistanceK(root->right, parentMap, isVisited, dist+1, k, ans);
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    //1.Map every node with it's parent.
    //2.Start traversing from target node and put a dist var.
    //  if dist at any time becomes equal to k just push the root val

    vector<int> ans;
    if(root == NULL) return ans;

    unordered_map<TreeNode*, TreeNode*> parentMap;
    parentMap[root] = NULL;
    mapping(root, parentMap);

    unordered_map<TreeNode*, bool> isVisited;
    findNodesinDistanceK(target, parentMap, isVisited, 0, k, ans);

    return ans;
}

int main() {
    return 0;
}