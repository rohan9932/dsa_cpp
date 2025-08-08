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

void buildLvlOrder(Node* root) {
    queue<Node*> q;
    cout << "Enter data for root node: ";
    int root_data;
    cin >> root_data;
    root = new Node(root_data);
    q.push(root);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << "Enter data for left node of " << temp->data << ": ";
        int l_data;
        cin >> l_data;
        if(l_data != -1) {
            temp->left = new Node(l_data);
            q.push(temp->left);
        }

        cout << "Enter data for right node of " << temp->data << ": ";
        int r_data;
        cin >> r_data;
        if(r_data != -1) {
            temp->left = new Node(r_data);
            q.push(temp->right);
        }
    }
}

vector<int> leftView(Node* root) {
    vector<int> ans;

    if(root == NULL) return ans;

    queue<pair<Node*, int>> q;
    map<int, int> leftNode;
    q.push(make_pair(root, 0)); 

    while(!q.empty()) {
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int lvl = temp.second;

        //check if it's the front node or not in the lvl
        if(leftNode.find(lvl) == leftNode.end()) {
            leftNode[lvl] = frontNode->data;
        }

        if(frontNode->left) {
            q.push(make_pair(frontNode->left, lvl+1));
        } 
        if(frontNode->right) {
            q.push(make_pair(frontNode->right, lvl+1));
        }
    }
    for(auto i: leftNode) {
        ans.push_back(i.second); //the leftmost val of each lvl
    }
    return ans;
}

//Recursive Approach
void helper(Node* root, vector<int>& ans, int lvl) {
    if(root == NULL) return;
    //entered new levevl
    if(lvl == ans.size()) {
        ans.push_back(root->data);
    }
    //left and right call
    helper(root->left, ans, lvl+1);
    helper(root->right, ans, lvl+1);
}

vector<int> leftViewRecursive(Node* root) {
    vector<int> ans;
    helper(root, ans, 0);
    return ans;
}
 
int main() {

    return 0;
}