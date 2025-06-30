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

//Approach 1
class Approach1 {
public:
    void inorderVec(TreeNode* root, vector<TreeNode*>& inorder) { //pair -> node val, idx in arr
        if(root == NULL) return;
        inorderVec(root->left, inorder);
        inorder.push_back(root); //stored location of the node
        inorderVec(root->right, inorder);
    }

    void recoverTree(TreeNode* root) { // TC: O(NlogN) SC:O(N)
        //1.Take the inorder nodes
        //2. Take inorder value and sort them(inorder valid bst is sorted)
        //3. Now traverse the node vec and change if at a certain point values don't match

        //1.
        vector<TreeNode*> inorder;
        inorderVec(root, inorder);

        //2.
        vector<int> inorderVal;
        for(int i = 0; i < inorder.size(); i++) { //O(N)
            inorderVal.push_back(inorder[i]->val);
        }
        vector<int> sortedInorder = inorderVal;
        sort(sortedInorder.begin(), sortedInorder.end()); //O(NlogN)

        //3.
        for(int i = 0; i < inorder.size(); i++) { //O(N)
            if(inorderVal[i] != sortedInorder[i]) {
                inorder[i]->val = sortedInorder[i];
            }
        }
    }
};


//Approach 2
class Approach2 {
private:
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;
    TreeNode* prev;

public: 
    void inorder(TreeNode* root) {
        if(root == NULL) return;
        inorder(root->left);

        //work
        if(prev != NULL && (root->val < prev->val)) {
            //if first violation then store first and middle
            if(first == NULL) { 
                first = prev;
                middle = root;
            }
            //if second violation just store last
            else {
                last = root;
            }
        }
        prev = root; //move forward

        inorder(root->right);
    }

    void recoverTree(TreeNode* root) { // TC: O(NlogN) SC:O(N)
        first = middle = last = NULL;
        //set prev pointer
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if(first && last) swap(first->val, last->val);
        else if(first && middle) swap(first->val, last->val);
    }
};


int main() {
    return 0;
}