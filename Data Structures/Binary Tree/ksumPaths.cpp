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
    root = new Node(root->data);
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

void helper(Node* root, int k, int& count, vector<int> path) {
    //base case
    if(root == NULL) return;

    path.push_back(root->data);

    //left and right call
    helper(root->left, k, count, path);
    helper(root->right, k, count, path);

    //check if k sum exists
    int sum = 0;
    for(int i = path.size()-1; i >= 0; i--) {
        sum += path[i];
        if(sum == k) count++;
    }

    //backtracking step
    path.pop_back();
}

int sumK(Node* root, int k) {
    vector<int> path;
    int count = 0;
    helper(root, k, count, path);
    return count;
}

int main() {
    return 0;
}