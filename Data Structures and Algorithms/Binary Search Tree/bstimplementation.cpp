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

//--------------------Insert a Node in BST-----------------------
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

//-----------------Delete a node in BST---------------------
Node* minVal(Node* root) {
    Node* inorderSuccessor = root->right;
    while(inorderSuccessor->left != NULL) {
        inorderSuccessor = inorderSuccessor->left;
    }
    return inorderSuccessor;
}

Node* deleteFromBST(Node* root, int val) {
    //base case
    if(root == NULL) return root;

    if(root->data == val) {
        //O child
        if(root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        //1 child
        //left child
        if(root->left != NULL && root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        //right child
        if(root->right != NULL && root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        //2 child
        if(root->left != NULL && root->right != NULL) {
           int min = minVal(root->right)->data;
           root->data = min;
           root->right = deleteFromBST(root->right, min); //recursive call
           return root;
        }
    } else if(val < root->data) {
        root->left = deleteFromBST(root->left, val);
        return root;
    } else {
        root->right = deleteFromBST(root->right, val);
        return root;
    }
}

int main() { 
    Node* root = NULL;

    cout << "Enter data to create BST: ";
    takeInput(root);

    cout << "Level order output: ";
    lvlOrderTraversal(root);

    deleteFromBST(root, 27);
    
    cout << "\nLevel order output: ";
    lvlOrderTraversal(root);
    return 0;
}