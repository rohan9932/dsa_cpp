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
    if(root == NULL) {
        root = new Node(data);
        return root;
    }

    if(data < root->data) {
        root->left = insertToBST(root->left, data);
    }
    if(root->data < data) {
        root->right = insertToBST(root->right, data);
    }
    return root;
}

void takeInput(Node*& root) {
    int data;
    cin >> data;
    while(data != -1) {
        root = insertToBST(root, data);
        cin >> data;
    }
}

//Approach 1
void helper(Node* root, int key, Node*& pred, Node* succ) {
    if(root == NULL) return;

    if(root->data == key) {
        //pred
        if(root->left) {
            Node* temp = root->left;
            while(temp->right != NULL) temp = temp->right;
            pred = temp;
        }
        //succ
        if(root->right) {
            Node* temp = root->right;
            while(temp->left != NULL) temp = temp->left;
            succ = temp;
        }
    } else if(root->data > key) {
        succ = root;
        helper(root->left, key, pred, succ);
    } else {
        pred = root;
        helper(root->right, key, pred, succ);
    }
}

vector<Node*> findPreSuc(Node* root, int key) {
    // code here
    Node* pred = NULL;
    Node* succ = NULL;
    helper(root, key, pred, succ);
    vector<Node*> ans = {pred, succ};
    return ans;
}

//Approach 2
void helper(Node* root, vector<Node*>& inorder) {
    if(root == NULL) return;
    helper(root->left, inorder);
    inorder.push_back(root);
    helper(root->right, inorder);
}

vector<Node*> findPreSuc(Node* root, int key) {
    // code here
    //take out elements according inorder traversal
    vector<Node*> inorder;
    helper(root, inorder);
    
    vector<Node*>ans = {NULL, NULL};
    
    for(int i = 0; i < inorder.size(); i++) {
        //predecessor
        if(inorder[i]->data < key) {
            ans[0] = inorder[i];
        }
        //successor
        else if(inorder[i]->data > key && ans[1] == NULL) {
            ans[1] = inorder[i];
            break;
        }
    }
    
    return ans;
}

int main() {
    return 0;
}