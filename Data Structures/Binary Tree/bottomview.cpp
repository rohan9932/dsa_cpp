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

vector<int> bottomView(Node *root) {
    // code here
    vector<int> ans;
    
    if(root == NULL) return ans;
    
    map<int, int> bottomNode; // hd and node
    queue<pair<Node*, int>> q;
    
    q.push(make_pair(root, 0));
    
    while(!q.empty()) {
        pair<Node*, int> temp = q.front();
        q.pop();
        
        Node* frontNode = temp.first;
        int hor_dist = temp.second;
        
        bottomNode[hor_dist] = frontNode->data; //update the map value
        
        if(frontNode->left) {
            q.push(make_pair(frontNode->left, hor_dist-1));
        }
        if(frontNode->right) {
            q.push(make_pair(frontNode->right, hor_dist+1));
        }
    }
    for(auto i: bottomNode) {
        ans.push_back(i.second);
    }
    return ans;
}

//Approach 2
void mapping(Node* root, map<int, pair<int, int>>&m, int hd, int lvl) {
    if(root == NULL) return;
    mapping(root->left, m, hd-1, lvl+1);
    mapping(root->right, m, hd+1, lvl+1);
    if(m.find(hd) == m.end() || lvl >= m[hd].second) {
        m[hd] = {root->data, lvl};
    }
}
vector<int> bottomView2(Node *root) {
    // Your Code Here
    vector<int> ans;
    if(root == NULL) return ans;
    
    map<int, pair<int, int>> m;
    mapping(root, m, 0, 0);
    for(auto i: m) {
        ans.push_back(i.second.first);
    }
    return ans;
}

int main() {

    return 0;
}