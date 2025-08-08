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

void buildfromLvlOrder(Node* root) {
    queue<Node*> q;
    int data;
    cout << "Enter data for root node: ";
    cin >> data;
    root = new Node(data);
    q.push(root);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << "Enter data for left node of " << temp->left << ": ";
        int l_data;
        cin >> l_data;
        if(l_data != -1) {
            temp->left = new Node(l_data);
            q.push(temp->left);
        } 

        cout << "Enter data for right node of " << temp->right << ": ";
        int r_data;
        cin >> r_data;
        if(r_data != -1) {
            temp->right = new Node(r_data);
            q.push(temp->right);
        } 
    }
}

void traverseLeft(Node* root, vector<int>& ans) {
    //base case
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL) return;

    ans.push_back(root->data); //store
    if(root->left) {
        traverseLeft(root->left, ans);
    } else {
        traverseLeft(root->right, ans);
    }
}

void traverseLeaf(Node* root, vector<int>& ans) {
    if(root == NULL) return;

    if(root->left == NULL && root->right == NULL) {
        ans.push_back(root->data);
        return;
    }

    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}

void traverseRight(Node* root, vector<int>& ans) {
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL) return;
    
    if(root->left) {
        traverseRight(root->right, ans);
    } else {
        traverseRight(root->left, ans);
    }

    //came back
    ans.push_back(root->data);
}

vector<int> boundaryTraversal(Node* root) {
    vector<int> ans;
    if(root == NULL) return ans;

    ans.push_back(root->data);

    //left part
    traverseLeft(root->left, ans);

    //traverse leaf nodes
    //left 
    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);

    //right part
    traverseRight(root->right, ans);

    return ans;
}

int main() {

}