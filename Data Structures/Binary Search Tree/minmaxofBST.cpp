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

int minBST(Node* root) {
    if(root == NULL) return 0;
    Node* temp = root;
    while(temp->left != NULL) {
        temp = temp->left;
    }
    return temp->data;
}

int maxBST(Node* root) {
    if(root == NULL) return 0;
    Node* temp = root;
    while(temp->right != NULL) {
        temp = temp->right;
    }
    return temp->data;
}

int main() {
    Node* root = NULL;

    cout << "Enter data to create BST: ";
    takeInput(root);

    cout << "Min value is: " << minBST(root) << "\n";
    cout << "Max value is: " << maxBST(root) << "\n";

    return 0;
}