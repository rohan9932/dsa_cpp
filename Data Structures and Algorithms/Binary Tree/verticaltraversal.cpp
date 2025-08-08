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

        cout << "Enter left node for " << temp->data << ": ";
        int l_data;
        cin >> l_data;
        if(l_data != -1) {
            temp->left = new Node(l_data);
            q.push(temp->left);
        }

        cout << "Enter right node for " << temp->data << ": ";
        int r_data;
        cin >> r_data;
        if(r_data != -1) {
            temp->right = new Node(r_data);
            q.push(temp->right);
        }
    }
}

vector<vector<int>> verticalOrder(Node* root) {
    map<int, map<int, vector<int>>> nodes;
    queue<pair<Node*, pair<int, int>>> q;
    vector<vector<int>> ans;

    if(root == NULL) return ans;

    q.push(make_pair(root, make_pair(0, 0)));

    while(!q.empty()) {
        pair<Node*, pair<int, int>> temp = q.front();

        Node* frontNode = temp.first;
        int hor_dist = temp.second.first;
        int lvl = temp.second.second;

        nodes[hor_dist][lvl].push_back(frontNode->data);

        if(frontNode->left) {
            q.push(make_pair(frontNode->left, make_pair(hor_dist-1, lvl+1)));
        } 
        if(frontNode->right) {
            q.push(make_pair(frontNode->right, make_pair(hor_dist+1, lvl+1)));
        }
    }
    for(auto i: nodes){
        vector<int> temp;
        for(auto j: i.second) {
            vector<int> v = j.second;
            sort(v.begin(), v.end());
            temp.insert(temp.end(), v.begin(), v.end());
        }
        ans.push_back(temp);
    }
    return ans;
}

//Approach 2
void mapping(Node* root, int v_lvl, int lvl, map<int, map<int, vector<int>>>& m) {
    if(root == NULL) return;
    m[v_lvl][lvl].push_back(root->data);
    mapping(root->left, v_lvl-1, lvl+1, m);
    mapping(root->right, v_lvl+1, lvl+1, m);
}

vector<vector<int>> verticalTraversal(Node* root) {
    vector<vector<int>>ans;
    if(root == NULL) return ans;
    map<int, map<int, vector<int>>> m; // vertical level -> (lvl -> nodes)
    mapping(root, 0, 0, m);
    for(auto i: m) {
        vector<int> v_lvl;
        for(auto j: i.second) {
            vector<int> lvl_sort = j.second;
            sort(lvl_sort.begin(), lvl_sort.end());
            v_lvl.insert(v_lvl.end(), lvl_sort.begin(), lvl_sort.end());
        }
        ans.push_back(v_lvl);
    }
    return ans;
}

int main() {

    return 0;
}