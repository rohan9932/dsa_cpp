#include <bits/stdc++.h>
using namespace std;

class Node {
public: 
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

void buildLvlOrder(Node*& root) {
    queue<Node*> q;
    cout << "Enter data for root node: ";
    int root_data;
    cin >> root_data;
    root = new Node(root_data);
    q.push(root);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << "Enter data for the left node of " << temp->data << ": ";
        int l_data;
        cin >> l_data;
        if(l_data != -1) {
            temp->left = new Node(l_data);
            q.push(temp->left);
        } 

        cout << "Enter data for the right node of " << temp->data << ": ";
        int r_data;
        cin >> r_data;
        if(r_data != -1) {
            temp->right = new Node(r_data);
            q.push(temp->right);
        }
    }
}

void helper(Node* root, int k, vector<int>path, int node, int& ans) {
    //base case
    if(root == NULL) return;
    
    path.push_back(root->data);
    
    //left and right call
    helper(root->left, k, path, node, ans);
    helper(root->right, k, path, node, ans);

    //if target node found
    if(root->data == node) {
        int idx = path.size() - k - 1;
        ans = path[idx];
    }

    //backtracking
    path.pop_back();
}

int kthAncestor(Node* root, int k, int node) {
    // Code here
    vector<int> path;
    int ans = -1;
    helper(root, k, path, node, ans);
    return ans;
}

//without path approach
Node* helper(Node* root, int& k, int node) { 
    if(root == NULL) return NULL;
    if(root->data == node) return root;

    //call for left and right
    Node* leftAns = helper(root->left, k, node);
    Node* rightAns = helper(root->right, k, node);

    if(leftAns != NULL && rightAns == NULL) {
        k--;
        if(k <= 0) {
            k = INT_MAX; //for locking answer
            return root;
        }
        else return leftAns;
    }
    if(rightAns != NULL && leftAns == NULL) {
        k--;
        if(k <= 0) {
            k = INT_MAX; //for locking answer
            return root;
        }
        else return rightAns;        
    }

    return NULL;
}

int kthAncestorwithoutPath(Node* root, int k, int node) {
    Node* ans = helper(root, k, node);
    return (ans == NULL || ans->data == node) ? -1: ans->data; //handling edge case of input node being root node
}

int main() {
    Node* root = NULL;
    buildLvlOrder(root);
    cout << kthAncestorwithoutPath(root, 2, 8) << "\n";
    return 0;
}