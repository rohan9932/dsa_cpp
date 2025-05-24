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

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << "Enter data for left node of " << temp->data << ": ";
        int l_data;
        cin >> l_data;
        if(l_data != -1) {
            temp->left = new Node(l_data);
        }

        cout << "Enter data for right node of " << temp->right << ": ";
        int r_data;
        cin >> r_data;
        if(r_data != -1) {
            temp->right = new Node(r_data);
        }
    }
}

Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
    //base case
    if(root == NULL) return NULL;
    if(root->data == p->data || root->data == q->data) return root;

    Node* leftAns = lowestCommonAncestor(root->left, p, q);
    Node* rightAns = lowestCommonAncestor(root->right, p, q);

    if(leftAns == NULL && rightAns == NULL) return NULL;
    else if(leftAns == NULL && rightAns != NULL) return rightAns;
    else if(leftAns != NULL && rightAns == NULL) return leftAns;
    else return root;
}

int main() {
    return 0;
}