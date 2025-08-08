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


pair<int, int> helper(Node* root) {
    pair<int, int> ans;
    //base case
    if(root == NULL) {
        ans = make_pair(0, 0);
        return ans;
    }
    
    //find left and right ans
    pair<int, int> left = helper(root->left);
    pair<int, int> right = helper(root->right);
    
    //here first val is including the node and second val is excluding the node
    ans.first = root->data + left.second + right.second;
    ans.second = max(left.first, left.second) + max(right.first, right.second);
    
    return ans;
}
int getMaxSum(Node *root) {
    // code here
    pair<int, int> ans = helper(root);
    return max(ans.first, ans.second);
}

int main() {
    return 0;
}