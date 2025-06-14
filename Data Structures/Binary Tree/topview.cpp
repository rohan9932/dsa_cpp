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

vector<int> topView(Node *root) {
    // code here
    vector<int> ans;
    
    if(root == NULL) return ans;
    
    map<int, int> topNode; // hd and node
    queue<pair<Node*, int>> q;
    
    q.push(make_pair(root, 0));
    
    while(!q.empty()) {
        pair<Node*, int> temp = q.front();
        q.pop();
        
        Node* frontNode = temp.first;
        int hor_dist = temp.second;
        
        //if one val not present for a hor_dist enter data else do nothing
        if(topNode.find(hor_dist) == topNode.end()) {
            topNode[hor_dist] = frontNode->data;
        }
        
        if(frontNode->left) {
            q.push(make_pair(frontNode->left, hor_dist-1));
        }
        if(frontNode->right) {
            q.push(make_pair(frontNode->right, hor_dist+1));
        }
    }
    for(auto i: topNode) {
        ans.push_back(i.second);
    }
    
    return ans;
}

//Approach 2
void mapping(Node* root, int v_lvl, int lvl, map<int, pair<int,int>>& m) {
    if(root == NULL) return;
    if(m.find(v_lvl) == m.end() || lvl < m[v_lvl].first) {
        m[v_lvl] = {lvl, root->data};
    }
    mapping(root->left, v_lvl-1, lvl+1, m);
    mapping(root->right, v_lvl+1, lvl+1, m);
}

vector<int> topView2(Node *root) {
    vector<int> ans;
    if(root == NULL) return ans;
    map<int, pair<int, int>> m;
    mapping(root, 0, 0, m);
    for(auto i: m) {
        ans.push_back(i.second.second);
    }
    
    return ans;
}

int main() {

    return 0;
}