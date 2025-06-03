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
    if(data > root->data) {
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

//Recursive Approach
Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
    if(root == NULL) return NULL;

    if(root->data > p->data && root->data > q->data) { //goto left
        return lowestCommonAncestor(root->left, p, q);
    }
    if(root->data < p->data && root->data < q->data) { //goto right
        return lowestCommonAncestor(root->right, p, q);
    }
    
    return root;
}

//Iterative Approach
Node* lcaiterative(Node* root, Node* p, Node* q) {
    while(root != NULL) {
        if(root->data > p->data && root->data > q->data) { //goto left
            root = root->left;
        } else if (root->data < p->data && root->data < q->data) { //goto right
            root = root->right;
        } else {
            return root;
        }
    }
    return NULL; //shouldn't happen if p and q are there
}

int main() {
    return 0;
}