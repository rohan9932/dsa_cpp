#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = this->right = NULL;
    }
};

void lvlOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) {
            cout << "\n";
            if(!q.empty()) q.push(NULL);
        } else {
            cout << temp->data << " ";
            if(temp->left) {
                q.push(temp->left);
            }
            if(temp->right) {
                q.push(temp->right);
            }
        }
    }
}


Node* insertToBST(Node* root, int data) {
    //base case
    if(root == NULL) {
        root = new Node(data);
        return root;
    }

    //right
    if(data > root->data) {
        root->right = insertToBST(root->right, data);
    }
    //left 
    else {
        root->left = insertToBST(root->left, data);
    }

    return root;
}

void takeInput(Node*& root) {
    int data;
    cin >> data;

    while(data != -1) {
        root = insertToBST(root, data); //root will not change as returning root in each level in the end
        cin >> data;
    }
}

//-----ValidBST--------
//Approach 1
void helper(Node* root, vector<int>& inorder) {
    if(root == NULL) return;
    helper(root->left, inorder);
    inorder.push_back(root->data);
    helper(root->right, inorder);
}

bool isValidBST(Node* root) {
    vector<int> inorder;
    helper(root, inorder);
    bool ans = true;
    for(int i = 1; i < inorder.size(); i++) {
        if(!(inorder[i-1] < inorder[i])) {
            ans = false;
        }
    }

    return ans;
}

//Approach 2
bool helper(Node* root, int min, int max) {
    //base case
    if(root == NULL) return true;

    if(root->data > min && root->data < max) {
        bool left = helper(root->left, min, root->data);
        bool right = helper(root->right, root->data, max);
        return left && right;
    } else {
        return false;
    }
}

bool isValidBST(Node* root) {
    return helper(root, LLONG_MIN, LLONG_MAX);
}

int main() {
    return 0;
}