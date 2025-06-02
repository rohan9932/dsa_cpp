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

Node* searchBST(Node* root, int val) {
    if(root == NULL) return NULL;

    if(root->data == val) return root;

    if(val < root->data) {
        return searchBST(root->left, val);
    } else {
        return searchBST(root->right, val);
    }
}

Node* searchBSTiterative(Node* root, int val) {
    Node* temp = root;
    while(temp != NULL) {
        if(temp->data == val) return temp;
        if(val < temp->data) temp = temp->left;
        else temp = temp->right;
    }
    return NULL;
}

int main() { 
    Node* root = NULL;

    cout << "Enter data to create BST: ";
    takeInput(root);

    return 0;
}